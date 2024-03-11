#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void Front_Insert(int *front,int *rear,int *deq,int size){
    if(*front==-1){
        *front=*rear=0;
    }
    else if((*front == 0)&&(*rear<size-1)){
        *front = size-1;
    }
    else if((*front == *(rear)+1)||(*front ==0 && *rear ==size-1)){
        printf("\nThe Queue is Full: ");
        return;
    }
    else{
        (*front)--;
    }
    printf("\nEnter the item: ");
    int item;
    scanf("%d",&item);
    deq[*front] = item;
}

void Rear_Insert(int *front,int *rear,int *deq,int size){
if(*front == -1){
    *front=*rear=0;
}
else if((*rear==size-1) && (*front >0)){
    *rear =0;
}
else if((*rear == *front-1)||(*front == 0 && *rear == size-1)){
    printf("\nThe queue is full: ");
    return;
}
else{
    (*rear)++;
}
printf("\nEnter the item: ");
int item;
scanf("%d",&item);
deq[*rear]=item;

}

void Front_pop(int *front,int *rear,int *deq,int size){


}
void Rear_pop(int *front,int *rear,int *deq,int size){

}

void display(int *front,int *rear,int *deq){

}

//---------------------------------------------------------------------------------
void type1(){
int n,choice;
bool a =true;
printf("\nEnter the size of stack: ");
scanf("%d",&n);
int Dequeue[n];
int front=-1,rear=-1;
while(a){
printf("Enter the choice:");
printf("\n1-for insertion from front:\n2-for insertion from rear:\n3-for Deletion:\n4-for displaying\n5-for exit:\n: ");
scanf("%d",&choice);
switch(choice){
case 1:Front_Insert(&front,&rear,Dequeue,n);
break;
case 2:Rear_Insert(&front,&rear,Dequeue,n);
break;
case 3:Front_pop(&front,&rear,Dequeue,n);
break;
case 4:display(&front,&rear,Dequeue);
break;
case 5:printf("Exiting from the program: "); a = false;
break;
default:printf("Enter the valid choice: \n");
break;
}
}
}

//-----------------------------------------------------------------------------------------

void type2(){
int n,choice;
bool a =true;
printf("\nEnter the size of stack: ");
scanf("%d",&n);
int Dequeue[n];
int front=-1,rear=-1;

while(a){
printf("Enter the choice:");
printf("\n1-for insertion:\n2-for deletion from rear:\n3-for Deletion from front:\n4-for displaying\n5-for exit:\n: ");
scanf("%d",&choice);
switch(choice){
case 1:
break;
case 2:
break;
case 3:
break;
case 4:
break;
case 5:printf("Exiting from the program: "); a = false;
break;
default:printf("Enter the valid choice: \n");
break;
}
}
}


//------------------------------------------------------------------------------------------


int main(){
int choice;
bool a= true;
printf("\nWhich type of DEqueue is yours:\n");
printf("1-for output restriction:\n2-for input restriction:\n3-for exiting the program:\n: ");
scanf("%d",&choice);
while(a){
switch(choice){
    case 1:type1();
    break;
    case 2:type2();
    break;
    case 3:printf("\nExiting from program: "); a = false;
    break;
    default:printf("\nEnter the valid choice: ");
    break;
}
}


return 0;
}