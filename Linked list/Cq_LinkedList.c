#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node *next;

};

void enqueue(struct node **front,struct node **rear,int *len){
    printf("\nEnter the item you want to insert: ");
    int item;
    scanf("%d",&item);
    struct node * new=(struct node *)malloc(sizeof(struct node));
    if(*front ==NULL){
        *front =new;
        *rear = new;
    }
    else{
    (*rear)->next = new;
    (*rear)=new;
    }
    (*rear)->data = item;
    (*rear)->next=*front;
    (*len)++;
}

void dequeue(struct node **front,struct node** rear,int *len){

if((*front) == NULL){
    printf("The CircilarQueue is empty: ");
    return;
}
else{
    struct node* rem = *front;
    if(*front != *rear){
        (*front)=(*front)->next;
        (*rear)->next=*front;
    }
    else{
        *front = NULL;  
    }
    free(rem);
}
(*len)--;
}

void search(int key,struct node *front){


}

void display(struct node *front){
struct node* dis=front;
if(front == NULL){
    printf("The queue is empty: ");
    return;
}
else{
    while(dis->next != front){
        printf("%d ",dis->data);
        dis = dis->next;
    }
    printf(" %d",dis->data);
}
}

void lenth(int len){
printf("The length of the cq is : %d",len);
}

int main(){
int key,choice;
bool a = true;
struct node *front =NULL,*rear = NULL;
int len =0;
while(a){
printf("\nEnter the choice: ");
printf("\n1 for insertion\n2 for deletion\n3 for search\n4 for displaying\n5 for length\n6 for exit\n: ");
scanf("%d",&choice);
switch(choice){
    case 1:enqueue(&front,&rear,&len);
    break;
    case 2:dequeue(&front,&rear,&len);
    break;
    case 3:printf("\nEnter the element to search: ");
    scanf("%d",&key);
    search(key,front);
    break;
    case 4:display(front);
    break;
    case 5: lenth(len);
    break;
    case 6: a =false;
    break;
}
}
return 0;
}