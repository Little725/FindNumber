#ifndef FILEINANDOUT
#define FILEINANDOUT

#include <iostream>
#include "if_win.h"

using namespace std;

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

void fileoutleft(int i)
  // store the game records in a .txt file
{
  ofstream fout;
  fout.open("records.txt");
  if ( fout.fail() ) {
    cout << "Error in file opening!" << endl;
    exit(1);
  }
  else {
    fout << "You left the game in " << i << " steps." << endl;
    fout.close();
  }
}

#endif
