#include<stdio.h>
#include<stdlib.h>
#include "function_sll.c"



int main()
{
  PNODE head=NULL; //macro
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
  deleteLL(&head);
 Display(head);
  return 0;
}
