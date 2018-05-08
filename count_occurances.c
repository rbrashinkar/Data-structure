#include<stdio.h>
#include<stdlib.h>
#include "function_sll.c"


 int count1(PNODE first,int no)
 {
   int icnt=0;
  if(first==NULL)
     return;
 while(first !=NULL)
  {
   if(first->data==no)
   {
    icnt++;
    first=first->next;
   }
   first=first->next;
  }
  return icnt;
 }

int main()
{
  PNODE head=NULL; //macro
  BOOL bret=TRUE;
  bret=InsertFirst(&head,51);
  bret=InsertFirst(&head,11);
  bret=InsertFirst(&head,21);
  bret=InsertFirst(&head,11);
  int iRet=0;

  Display(head);
  iRet=count(head);
  printf("No of element in LinkedList is:%d\n",iRet);
  printf("no of occurances of given no is %d\n",count1(head,11));	

return 0;

}
