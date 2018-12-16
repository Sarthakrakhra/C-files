//retrieved help from www.geekforgeeks.com

#include <stdio.h>


struct node {
  int val;
  struct node *next;
};

int list_sum_i(struct node *head);
int list_sum_r(struct node *head);
struct node * list_reverse(struct node *head);


int main(){
  return 0;
}

int list_sum_r(struct node *head){

  if(head == NULL)
    return 0;
  else
    return head -> val + list_sum_r(head -> next);


}

int list_sum_i(struct node *head){

  int sum = 0;
  struct node *curr = head;
  while(curr!=NULL){
    sum+= curr -> val;
    curr = curr -> next;
  }
  return sum;
}

//I retrieved the solution for this function with the help of my previous java codes. 
struct node * list_reverse(struct node *head){

  struct node *curr = head;
  struct node *prev = NULL;
  struct node *nextOfCurr = NULL;

  while(curr!=NULL){
    nextOfCurr = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = nextOfCurr;
  }
  *head = *prev;
  return head;
}
