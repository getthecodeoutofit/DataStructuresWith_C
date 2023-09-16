#include<stdio.h>
#include<stdbool.h>


void insertion(int *move,int *front,int num,int size,int *q){
    if(move==size){
        printf("the queue is full: ");
        return;
    }
    if(*front == -1){
        *front =0;
        *move =0;
    }
    q[*move]=num;
    (*move)++;

}

void pop(int *move,int *front,int *q){
    if(*front==-1){
        printf("noting to pop: ");
        return;
    }
    if(*front == *move){
        *front = -1;
        return;
    }
    (*front)++;
}
void main(){
int size,front=-1,move=-1;
printf("enter the size for the queue: ");
scanf("%d",&size);
int queue[size];
bool a=true;
int choice,k,num;
while(a){
printf("enter the choice you want to make: \n1 for insertion \n2 for deleting/pop\n3for traversing\n4 for searching\n5 for exit: ");
scanf("%d",&choice);
switch (choice)
{
case /* constant-expression */1: 

    /* code */
    break;

default:
    break;
}
}
}