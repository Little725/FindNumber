#ifndef INITIALIZATION
#define INITIALIZATION

#include <iostream>
#include <vector>

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

#endif
