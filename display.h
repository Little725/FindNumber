#ifndef DISPLAY
#define DISPLAY

#include <iostream>
#include "if_win.h"

void display_matrix(int** matrix, int n, Node * head)
  // display the current matrix after a guess
{
  for (int i=0; i<n; ++i){
    for (int j=0; j<n; ++j){
      Node * current = head;
      int k=0;
	    while (current != NULL){
		      if (current -> info == matrix[i][j]){
            k++;
          }
          current=current->next;
      }
      if (k!=0){
        cout << matrix[i][j] <<'\t';
      }
      else{
        cout << '*' << '\t';
      }
    }
    cout<<endl;
    }
}

#endif
