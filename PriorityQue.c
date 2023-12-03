#include<stdlib.h>
#include<stdio.h>
//priority queues using linked list

struct node{
  int data;
  int priority;
  struct node*next;
};

struct node * Head = NULL ,*Tail = NULL;

void create(){
  struct node* newnode = (struct node*)malloc(sizeof(struct node*));
  int item;
  int priority;
  printf("Enter the data: ");
  scanf("%d",&item);
  printf("Enter the priority: ");
  scanf("%d",&priority);
  newnode->data = item;
  newnode->priority = priority;
  if(Head == NULL){
    Head = Tail = newnode;
    return;
  }
  else{
    
  }
}

void display(){
  struct node* temp = Head;
  while(temp!=NULL){
    printf("%d",temp->data);
    temp = temp->next;
    
  }
}

void delete(){
  struct node * temp = Head;
  
}

int main(){
  int choice;
  while(1){
    printf("ENter your choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        break;
        case 2:
          break;
    }
  }
  
  
}