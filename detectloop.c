#include<stdio.h>
#include<stdlib.h>
#include "function_sll.c"

int detectloop(PNODE first)
{
 PNODE sp=first,fp=first;
 while(sp && fp && fp->next)
 {
  sp=sp->next;
  fp=fp->next->next;
  if(sp ==fp)
  {
   printf("\n loop detect..\n");
   return 1;
  }
} 	
 return 0;
}


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
  head->next->next->next->next = head;
  detectloop(head);
  return 0;
}
