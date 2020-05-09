#ifndef MOVE
#define MOVE

#include <iostream>
#include <vector>
#include "if_win.h"


bool existence(vector<int> all_num, int n){
  //check if the input number is in the vector(as mentioned before)
  for (int i = 0; i < all_num.size(); ++i){
    if (n == all_num[i])
      return true;
  }
  return false;
}

void moveon(Node * & head, int n){
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

#endif
