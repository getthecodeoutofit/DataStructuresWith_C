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
  if(Head ==NULL){
    printf("NO item to display: ");
    return;
  }

  while(temp!=NULL){
    printf("data: %d",temp->data);
    printf("\npriority: %d",temp->priority);
    temp = temp->next;
  }
}

void deletePriority(){
  int pri;
  printf("Enter the priority: ");
  scanf("%d",&pri);
  struct node * temp = Head->next,*slow = Head;
  if(Head ==NULL){
    printf("No item to delete: ");
    return;
  }
  else if(Head->priority == pri){
    Head = temp;
    free(slow);
    return;
    }
    else{


    }


}

void deleteitem(){
  struct node * temp = Head->next,*slow = Head;
}

int main(){
  int choice;
  while(1){
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        break;
        case 2:
          break;
    }
  }
  
  
}