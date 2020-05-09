#ifndef IFWIN
#define IFWIN

struct Node {
  int info;
  Node * next;
};

bool if_win(int** matrix, int n, Node * head)
      // check if the player completes either of the followings: a row, a column, or a diagonal
{
  for (int i=0; i<n; ++i){
    int checkrow=0;
    for (int j=0; j<n; ++j){
      Node * current1 = head;
      while (current1 != NULL) {
    	   if (current1 -> info == matrix[i][j]){
           checkrow++;
         }
         current1 = current1 -> next;
       }
     }
     if (checkrow==n){
       return true;
     }
   }

   for (int i=0; i<n; ++i){
     int checkcolumn=0;
     for (int j=0; j<n; ++j){
       Node * current2 = head;
       while (current2 != NULL) {
         if (current2 -> info == matrix[j][i]){
           checkcolumn++;
         }
         current2 = current2 -> next;
        }
      }
      if (checkcolumn==n){
        return true;
        }
    }

    int checkdiagonal1=0, checkdiagonal2=0;
    for (int i=0; i<n; ++i){
        Node * current3 = head;
        while (current3 != NULL) {
          if (current3 -> info == matrix[i][i]){
            checkdiagonal1++;
            }
            current3 = current3 -> next;
        }
    }
    if (checkdiagonal1==n){
      return true;
    }

    for (int i=0; i<n; ++i){
      Node * current4 = head;
      while (current4 != NULL) {
        if (current4 -> info == matrix[n-i-1][i]){
          checkdiagonal2++;
        }
        current4 = current4 -> next;
      }
    }
    if (checkdiagonal2==n){
      return true;
    }

    return false;
}

#endif
