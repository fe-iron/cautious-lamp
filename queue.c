#include<stdio.h>
#include<string.h>
#include<iostream>

struct arrayQueue
{
  int front,rear;
  unsigned capacity;
  int *array;
};

struct arrayQueue* create(unsigned cap){
  struct arrayQueue *s;
  s=(arrayQueue*)malloc(sizeof(struct arrayQueue));
  if(!s)
    return NULL;
  s->capacity=cap;
  s->rear=s->front=-1;
  s->array=(int*)malloc(sizeof(int)*s->capacity);
  if(!s->array)
   return NULL;
  return s;
}

int isemptyQueue(struct arrayQueue *t){
  return t->front==-1;
}

int isfullQueue(struct arrayQueue *p){
  return ((p->rear+1)%p->capacity==p->front);
}

void enQueue(struct arrayQueue* p,int data){
  if(isfullQueue(p))
    printf("Queue overflow\n");
  else{
   p->rear=(p->rear+1)%p->capacity;
   p->array[p->rear]=data;
   if(p->front==-1)
    p->front=p->rear;
  }
}

int dequeue(struct arrayQueue* s){
  int dat;
  if(isemptyQueue(s))
    printf("Queue underflow\n");
  else{
  dat=s->array[s->front];
  if(s->rear==s->front)
   s->rear=s->front=-1;
  else
   s->front=(s->front+1)%s->capacity;
  }
 return dat;
}

int sizeQueue(struct arrayQueue *ptr){
  return ((ptr->capacity-ptr->front+ptr->rear+1)%ptr->capacity);
}

void deleteQueue(struct arrayQueue*p){
  if(p){
   if(p->array){
    free(p->array);
   }
  free(p);
 }
}

int menu(){
 int n;
 printf("choose from the given menu\n");
 printf("\n1.Insert in queue\n2.Delete single element from queue\n3.Size of queue\n4.Delete trhe Queue\n5.Exit\t");
 scanf("%d",&n);
 return n;
}

int main(){
 int cap,data;
 struct arrayQueue *temp;
 printf("enter the siz eof the Queue\t");
 scanf("%d",&cap);
 temp=create(cap);
 while(1){
  switch(menu()){
   case 1:
    printf("enter the data\t");
    scanf("%d",&data);
    enQueue(temp,data);
    break;
   case 2:
    printf("the %d data is now deleted",dequeue(temp));
    break;
   case 3:
    printf("the size of the Queue is %d\t",sizeQueue(temp));
    break;
  case 4:
    deleteQueue(temp);
    printf("the Queue has been deleted\n");
    break;
  case  5:
    exit(0);
  }
 }
 return 0;
}
