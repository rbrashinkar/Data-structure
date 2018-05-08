#include<stdio.h>
#include<stdlib.h>
#include "function_sll.c"
#include<assert.h>
void MoveNode(PPNODE destRef, PPNODE sourceRef);

/* Takes two lists sorted in increasing order, and splices
   their nodes together to make one big sorted list which
   is returned.  */
PNODE SortedMerge(PNODE first,PNODE first1)
{
  NODE dummy;
  PNODE tail=&dummy;
  dummy.next=NULL;
  while(1)
  {
   if(first ==NULL)
   {
    tail->next=first1;
   }
   else if(first1 ==NULL)
   {
    tail->next=first;
   }
    if(first->data <=first1->data)
    {
     MoveNode(&(tail->next),&first);
    }
    else
    {
     MoveNode(&(tail->next),&first1);
    }
    tail=tail->next;
 }
  return (dummy.next);
}

/* UTILITY FUNCTIONS */
/* MoveNode() function takes the node from the front of the
   source, and move it to the front of the dest.
   It is an error to call this with the source list empty.
 
   Before calling MoveNode():
   source == {1, 2, 3}
   dest == {1, 2, 3}
 
   Affter calling MoveNode():
   source == {2, 3}
   dest == {1, 1, 2, 3} */

void MoveNode(PPNODE destRef,PPNODE sourceRef)
{
 PNODE newnode=*sourceRef;
 assert(newnode != NULL);
 
  *sourceRef=newnode->next;
  newnode->next = *destRef;
  *destRef = newnode;
}
int main()
{

  PNODE head=NULL;
  PNODE head1=NULL; //macro
  PNODE res=NULL;
  BOOL bret=TRUE;
  PNODE temp=head;
  int iRet=0;
  int i=0;
  bret=InsertFirst(&head,11);
  bret=InsertFirst(&head,21);
  bret=InsertFirst(&head,31);
  bret=InsertFirst(&head,41);
  bret=InsertFirst(&head,51);

  Display(head);
  iRet=count(head);
  printf("No of element in LinkedList is:%d\n",iRet);
  bret=InsertFirst(&head1,10);
  bret=InsertFirst(&head1,12);
  bret=InsertFirst(&head1,14);
  bret=InsertFirst(&head1,15);
  bret=InsertFirst(&head1,16);
  Display(head1);
  iRet=count(head1);
  printf("No of element in LinkedList is:%d\n",iRet);
  res=SortedMerge(head,head1);
  printf("after merge two linkedlist\n");
  Display(res);

 

  return 0;
}
