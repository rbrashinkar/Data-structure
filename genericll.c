#include<stdio.h>
#include<stdlib.h>

struct node
{
 void *data;
 struct node* next;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void insert(PPNODE first,void *no,size_t data_size)
{
  PNODE newnode=(PNODE)malloc(sizeof(NODE));
  newnode->data=malloc(data_size);
  newnode->next=(*first);
  
  int i;
  for(i=0;i<data_size;i++)
  {
   *(char *)(newnode->data+i)=*(char*)(no+i);
  }
  *first=newnode;
}

void display(PNODE first,void(*fptr)(void*))
{
  while(first !=NULL)
  {
    (*fptr)(first->data);
     first=first->next;
  }
}

void printInt(void * n)
{
  printf("%d\t",*(int *)n);
}

void printFloat(void * f)
{
  printf("%f\t",*(float*)f);
}

int main()
{
  PNODE head=NULL;
  unsigned int_size=sizeof(int);
  int arr[]={10,20,30,40,50},i;
  for(i=4;i>=0;i--)
  {
   insert(&head,&arr[i],int_size);
  }
  printf("\n\ncreated interger linked list is\n");
  display(head,printInt);

  unsigned float_size=sizeof(float);
  head=NULL;
  float arr2[]={10.1,20,3,30.4,40.5,50.6};
  for(i=4;i>=0;i--)
  {
   insert(&head,&arr2[i],float_size);
  }
  printf("\n\ncreated float linked list is\n");
  display(head,printFloat);
  return 0;
}
