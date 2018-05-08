#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;
typedef int BOOL;
#define TRUE 1
#define FALSE 0

//function decleration

BOOL InsertFirst(PPNODE,int);
BOOL InsertLast(PPNODE,int);
BOOL InsertAtPos(PPNODE,int,int);

BOOL DeleteFirst(PPNODE);
BOOL DeleteLast(PPNODE);
BOOL DeleteAtPos(PPNODE,int);

BOOL search(PNODE,int);
void swapNodes(PPNODE,int,int);
int GetNthNode(PNODE,int);
void printNthFormLast(PNODE,int);
void deleteLL(PPNODE);

void printMiddle(PNODE);
void printMiddle1(PNODE);
static void reverse(PPNODE);
void Display(PNODE);
int count(PNODE);

//insert first node
 BOOL InsertFirst(PPNODE first,int no)
 {
  PNODE newnode=NULL;
 //allocate memory
  newnode=(PNODE)malloc(sizeof(NODE));
  if(newnode ==NULL)
  {
   return FALSE;
  }
  newnode->data=no;
  newnode->next=NULL;
 if(*first ==NULL)
  {
   *first=newnode;
  }
  else
  {
   newnode->next=*first;
   *first=newnode;
  }
  return TRUE;
 }

//insert at last position
BOOL InsertLast(PPNODE first,int no)
 {
  PNODE newnode=NULL;
  PNODE temp=NULL;
 //allocate memory
  newnode=(PNODE)malloc(sizeof(NODE));
  if(newnode ==NULL)
  {
   return FALSE;
  }
  newnode->data=no;
  newnode->next=NULL;
 if(*first ==NULL)
  {
   *first=newnode;
  }
  else
  {
  temp=*first;
  while(temp->next != NULL)
  {
   temp=temp->next;
  }
   temp->next=newnode;
  }
  return TRUE;
 }

//insert at given postion
BOOL InsertAtPos(PPNODE first,int no,int pos)
{
 PNODE newnode=NULL;
 PNODE temp=NULL;
 //memory allocation
 newnode=(PNODE)malloc(sizeof(NODE));

 int icnt=count(*first);
 int i=0;
 temp=*first;
 if((pos <=0)||(pos >(icnt+1))) //invalid position
 {
   return FALSE;
 }
 if(pos ==1)
 {
  return (InsertFirst(first,no));
 }
 else if(pos ==(icnt+1))
 {
  return(InsertLast(first,no));
 }
 else
 {
  if(newnode ==NULL)
  {
   return FALSE;
  }
  newnode->data=no;
  newnode->next=NULL;
  
  for(i=0;i<=pos-2;i++)
  {
   temp=temp->next;
  }
  newnode->next=temp->next;
  temp->next=newnode;
 }
 return TRUE;
}

//delete first node
BOOL DeleteFirst(PPNODE first)
{
 PNODE temp= *first;
 if(*first ==NULL)
  {
   return FALSE;
  }
 else
 {
  (*first)=(*first)->next;
   free(temp);
 }
   
   return TRUE;
}

//delete last node
BOOL DeleteLast(PPNODE first)
{
 PNODE temp=*first;
 if(*first ==NULL)
  {
   return FALSE;
  }
  else if((*first)->next ==NULL)
  {
   free(*first);
    *first=NULL;
  }
  else
   {
   while(temp->next->next!=NULL)
   {
     temp=temp->next;
   }
   free(temp->next);
   temp->next=NULL;
  }   
   return TRUE;
}

//delete at given position
BOOL DeleteAtPos(PPNODE first,int pos)
{
  int icnt=0,i=0;
  PNODE temp1=NULL,temp2=NULL;
  icnt=count(*first);
 
 if((pos <1)||(pos >icnt))//invalid pos
 {
  return FALSE;
 }
 if(pos ==1)
 {
  return(DeleteFirst(first));
 }
 else if(pos ==icnt)
 {
  return(DeleteLast(first));
 }
 else
 {
  temp1=*first;
  for(i=0;i<(pos-2);i++)
  {
    temp1=temp1->next;
 }
  temp2=temp1->next;
  temp1->next=temp2->next;
  free(temp2);
 }
 return TRUE;
}
 
//TO DISPLAY LINKEDLIST	
 void Display(PNODE first)
 {
  while(first !=NULL)
  {
   printf("%d\t",first->data);
   first=first->next;
  }
  printf("\n....................\n");
 }
//TO COUNT NO OF ELEMENT IN THE LIST 
 int count(PNODE first)
 {
   int icnt=0;
 while(first !=NULL)
  {
   icnt++;
   first=first->next;
  }
  return icnt;
 }

BOOL search(PNODE first,int no)
{
  PNODE temp=NULL;
  temp= first;
  while(temp !=NULL)
  {
    if(temp->data ==no)
    {
     return TRUE;
    }
    temp=temp->next;
  }
  return FALSE;
 }

void swapNodes(PPNODE first,int x,int y)
{

 //nothing to do if x and y is same
 if(x == y)
 {
  return ;
 }

//search for x
PNODE prevX=NULL,currX=*first;
while(currX &&currX->data !=x)
{
 prevX=currX;
 currX=currX->next;
}

//search for y
PNODE prevY=NULL,currY=*first;
while(currY &&currY->data !=y)
{
 prevY=currY;
 currY=currY->next;
}

// If either x or y is not present, nothing to do
if((currX ==NULL)||(currY == NULL))
{
 return;
}

 // If x is not head of linked list
if(currX !=NULL)
{
 prevX->next=currY;
}
else // Else make y as new head
{
 *first=currY;
}

// If y is not head of linked list
if(currY !=NULL)
{
 prevY->next=currX;
}
else // Else make x as new head
{
 *first=currX;
}

// Swap next pointers
PNODE temp=currY->next;
currY->next=currX->next;
currX->next=temp;


}

// to find n'th node in linked list
int GetNthNode(PNODE first,int index)
{
  
 PNODE temp=first;
 int count=0;
 while(temp != NULL)
 {
  if(count ==index)
  {
    return (temp->data);
  }
  count++;
  temp=temp->next;
 }
 return -1;
}

void printMiddle(PNODE first)
{
    PNODE slow_ptr = first;
    PNODE fast_ptr = first;
 
    if (first!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
} 

 void printMiddle1(PNODE first)
 {
   PNODE temp=first;
   int n=count(first);
   int n1=n/2;
   int i=0;
   while(i < n1)
   {
     i++;
     temp=temp->next;
   }
   printf("the middle index is %d and value is %d\n",i,temp->data);
 }

void printNthFormLast(PNODE first,int n)
{
  int len=0,i;
  PNODE temp=first;
  len=count(first);
  if(len < n)
     return;
  //temp = first;
  for(i=0;i<len-n;i++)
  {
    temp=temp->next;
  }

 printf("%d",temp->data);
 return;

}

void deleteLL(PPNODE first)
{
 PNODE temp=NULL;
 PNODE next=NULL;
 temp=*first;
 while(temp != NULL)
 {
  next=temp->next;
  free(temp);
  temp=next;
 }
 *first=NULL;
}

static void reverse(PPNODE first)
{
 PNODE temp=*first;
 PNODE prev=NULL;
 PNODE next=NULL;
 
while(temp !=NULL)
{
  next=temp->next;
  temp->next=prev;
  prev=temp;
  temp=next;
}
*first=prev;
}

