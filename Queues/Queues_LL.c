#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
int data;
struct node *next;
};

void insert(struct node **front,struct node **rear,int num,int *len){
  struct node * new=(struct node*)malloc(sizeof(struct node));
  if(*front == NULL){
    *front = new;
    *rear = new;
  }
  else{
    (*rear)->next = new;
    (*rear) = new;
  }
  (*rear)->data = num;
  (*rear)->next = NULL;
  (*len)++;   
}

void pop(struct node **front,struct node **rear,int *len){
    if(*front == NULL){
        printf("the data is empty: ");
        return;
    }
    else if(*front == *rear){
        free(*front);
        *front = NULL;
    }
    else{
        struct node* rem;
        rem = *front;
        (*front)=(*front)->next;
        free(rem);
        (*len)--;
    }
}

void search(int key,struct node *front){
    int len = 1;
    if(front==NULL){
        printf("\nThe datas is empty: ");
        return;
    }
    else{
        while(front!=NULL){
        if(front->data==key){
            printf("\nThe element has been found in the %d location:",len);
            return;
        }
        front = front->next;
        len++;
    }
    }
}

void print(struct node *front){
    if(front==NULL){
        printf("\nThe datas is empty: ");
        return;
    }
    else{
        while(front!=NULL){
            printf("%d ",front->data);
            front = front->next;
        }
    }
}

int main(){
int choice,num,key,len=0;
bool b = true;
struct node *front = NULL,*rear = NULL;
while(b){
    printf("\nENTER the choice: \n1 for insertion\n2 for pop\n3 for print\n4 for search\n5 for length\n6 for exit: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:printf("Enter the number to insert: ");
    scanf("%d",&num);
    insert(&front,&rear,num,&len);
    break;

    case 2:printf("Deleting the element....");
    pop(&front,&rear,&len);
    break;

    case 3: printf("Printing the data...: ");
    print(front);
    break;

    case 4:printf("Enter the element to search: ");
    scanf("%d",&key);
    search(key,front);
    break;

    case 5:printf("The length of the data is: %d",len);
    break;

    case 6:
    printf("\nProgram terminated....\n\n");b = false;
    break;

    default:
     break;
    }
}
return 0;
}