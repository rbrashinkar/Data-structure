#include<stdio.h>
#include<stdlib.h>
#include "function_sll.c"



int main()
{
  PNODE head=NULL; //macro
  BOOL bret=TRUE;
  bret=InsertFirst(&head,11);
  bret=InsertFirst(&head,21);
  bret=InsertFirst(&head,51);
  int iRet=0;

  Display(head);
  iRet=count(head);
  printf("No of element in LinkedList is:%d\n",iRet);
 	
  bret=InsertLast(&head,121);
  bret=InsertLast(&head,151);
  Display(head);

   bret= DeleteLast(&head);
   bret=InsertLast(&head,151);
   Display(head);

   bret=DeleteFirst(&head);
   Display(head);

   bret=InsertAtPos(&head,135,2);
   bret=InsertAtPos(&head,401,1);
   Display(head);
 
   bret=DeleteAtPos(&head,1);
   Display(head);
 
   bret=DeleteAtPos(&head,3);
   Display(head);

 
 
  return 0;
 }



 


