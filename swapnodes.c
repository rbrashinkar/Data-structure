#include<stdio.h>
#include<stdlib.h>
#include "function_sll.c"



int main()
{
  PNODE head=NULL; //macro
  BOOL bret=TRUE;
 
  bret=InsertFirst(&head,11);
  bret=InsertFirst(&head,21);
  bret=InsertFirst(&head,31);
  bret=InsertFirst(&head,41);
  bret=InsertFirst(&head,51);
  int iRet=0;

  Display(head);
  iRet=count(head);
  printf("No of element in LinkedList is:%d\n",iRet);
 
  swapNodes(&head,41,21);
  Display(head);
  
 return 0;
}
