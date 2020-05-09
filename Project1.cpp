#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Node {
  int info;
  Node * next;
};

int** init_matrix(int n) {
  //generate the initial matrix with size n*n and each entry ranging from 1 to 20
  int m;
  cout<<"Please input an integer to generate random numbers: ";
  cin >> m;
  srand(m);

  int ** a = new int*[n];
  for (int i=0; i<n; ++i){
    a[i] = new int[n];
  }
  for (int i=0; i<n; ++i){
    for (int j=0; j<n; ++j){
      a[i][j]=rand()%20+1;
    }
  }
  return a;
}

void numberset(vector<int> &all_num, int** matrix, int n){
  //generate a vector that contains all the distinct numbers in the initial matrix
  int p=0, q=0, c=0;
  while (p<n){
    while (q<n) {
      for (int k=0; k<all_num.size(); k++){
        if (matrix[p][q]== all_num[k]){
          c++;
        }
      }
      if (c==0){
        all_num.push_back(matrix[p][q]);
      }
      q++;
      c=0;
    }
    p++;
    q=0;
  }
}


bool existence(vector<int> all_num, int n){
  //check if the input number is in the vector(as mentioned before)
  for (int i = 0; i < all_num.size(); ++i){
    if (n == all_num[i])
      return true;
  }
  return false;
}

void moveon(Node * &head, int n){
  //insert the new right number to the beginning of existing right numbers
  Node * p = new Node;
  p->info = n;
  p->next = head;
  head=p;
}

bool valid(Node * head, int n){
  Node * q = head;
  int i=0;
  while (q!=NULL){
    if (q->info == n){
      i++;
    }
    q=q->next;
  }
  if (i==0){
    return true;
  }
  else {
    return false;
  }
  //check if the input is already existing in the list

}

void moveback(Node * &head){
  //delete the most recent existing right number
  if (head!= NULL){
    Node * p=head;
    head=head->next;
    delete p;
  }
}

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

bool row_win(int** matrix, int n, Node * head)
  // check if the player completes a row
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
  return false;
}

bool column_win(int** matrix, int n, Node * head)
    // check if the player completes a column
{
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
  return false;
}

bool diagonal_win(int** matrix, int n, Node * head)
  // check if the player completes a diagonal
{
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

bool if_win(int** matrix, int n, Node * head)
  // check if the player completes either of the followings: a row, a column, or a diagonal
{
  if (row_win(matrix, n, head)){
    return true;
  }
  else if (column_win(matrix, n, head)){
    return true;
  }
  else if (diagonal_win(matrix, n, head)){
    return true;
  }
  else {
    return false;
  }
}

void greet()
  //print out the contents in the 'greetings' file
{
  ifstream fin;
  fin.open("greetings.txt");
  //open the 'greetings' file
  if ( fin.fail() )
  {
		cout << "Error in file opening!" << endl;
 		exit(1);
  }
  string greetings;
  getline(fin, greetings);
  cout << greetings << endl;
}

void fileout(int i)
  // store the winning records in a .txt file
{
  ofstream fout;
  fout.open("records.txt");
  if ( fout.fail() ) {
    cout << "Error in file opening!" << endl;
    exit(1);
  }
  else {
    fout << "Congratulations! You won in " << i << " steps." << endl;
    fout.close();
  }
}

int main()
{
  greet();
  //print out the greetings in file 'greetings.txt'
  int n, i;
  string yesno;
  yesno = "yes";
  //initialize the answer for clicking into the game
  while (yesno != "no"){
    cout<<"Please input an integer n to determine the size of your n*n matrix: ";
    cin >> n;
    //require the user to input an integer to determine the size of the matrix
    i = 0;
    //determine initial size
    int** matrix=init_matrix(n);
    //generate initial matrix
    //in the 'init_matrix' func, user is required to input an integer for srand()
    vector<int> numbers;
    //create a vector
    numberset(numbers, matrix, n);
    //use the vector 'numbers' to store all the distinct numbers in the initial matrix
    Node * head = NULL;
    //a list that will be used later for storing all the right numbers from user's input
    cout<<"This is your current matrix:"<<endl;
    display_matrix(matrix, n, head);
    string input;
    //input number tp play or 'end' to terminate
    while (! if_win(matrix, n, head)){
      cout<<"Guess a number that may appear in the matrix: ";
      cin >> input;
      if (input=="end"){
        cout << "You leave in " << i << " steps." << endl << "Play again? (yes/no)" << endl;
        cin >> yesno;
      }
      else {
        int num=stoi(input);
        if (existence(numbers,num)){
          //if the user'input is one of right numbers
          if (valid(head, num)){
            moveon(head,num);
            //add the input number to the beginning of right number list
            cout<<"You got a right answer! \nThis is your current matrix:"<<endl;
            display_matrix(matrix, n, head);
            //print out current matrix
          }
          else{
            cout<<"This number already exists in your matrix. \nThis is your current matrix:"<<endl;
            display_matrix(matrix, n, head);
          }
        }
        else {
          moveback(head);
          //delete the most recent existing right number from the list
          cout<<"Sorry, you got a wrong answer. \nThis is your current matrix:"<<endl;
          display_matrix(matrix, n, head);
          //print out current matrix
        }
        i++;
      }
    }

    if (if_win(matrix, n, head)){
      fileout(i);
      cout << "Congratulations! You won in " << i << " steps." << endl << "Play again? (yes/no)" << endl;
      cin >> yesno;
    }
  }
  return 0;
}
