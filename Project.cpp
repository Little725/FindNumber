#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "if_win.h"
#include "file_in_out.h"
#include "initial.h"
#include "move.h"
#include "display.h"

using namespace std;

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
      cout<<"Guess a number (from 1 to 20) that may appear in the matrix: ";
      cin >> input;
      if (input=="end"){
        cout << "You leave in " << i << " steps." << endl;
        break;
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
          cout<<"Sorry, you got a wrong answer. We have to delete the newest right number.\nThis is your current matrix:"<<endl;
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
      delete head;
      head=NULL;
    }
    else {
      fileoutleft(i);
      cout<<"Play again? (yes/no)"<<endl;
      cin >> yesno;
      delete head;
      head=NULL;
    }
  }
  cout << "Bye!" << endl;
  return 0;
}
