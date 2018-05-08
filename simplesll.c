//programe of simple singly linked list
#include<stdio.h>
#include<stdlib.h>

//define struct
struct node
{
 int data;
 struct node * next;
};

//print linkedlist
void printll(struct node *temp)
 {
  while(temp !=NULL)
  {
   printf("%d\t",temp->data);
   temp=temp->next;
  }
   printf("\n..............\n");
 }

int main()
{
 struct node* head=NULL;
 struct node*  second=NULL;
 struct node* third=NULL;
//allocate memeory
  head=(struct node *)malloc(sizeof(struct node));
  second=(struct node *)malloc(sizeof(struct node));
  third=(struct node *)malloc(sizeof(struct node));
  
  head->data=2;
  head->next=second;

  second->data=4;
  second->next=third;

  third->data=6;
  third->next=NULL;
  
 printll(head);
 
return 0;
}
