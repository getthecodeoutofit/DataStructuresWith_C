#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node * next;

};

struct node * Head = NULL;
void insert(){
  struct node * newnode = (struct node *)malloc(sizeof(struct node));
  int item;
  printf("Enter the item: ");
  scanf("%d",&item);
  newnode->data = item;
  newnode->next = NULL;

  if(Head == NULL){
    Head = newnode;
    return;
  }
  else{

  }
}

void display(){
  if(Head == NULL){
    return;
  }
  else{
    struct node * temp = Head;
    while(temp!=NULL){
      printf("%d ",temp->data);
      temp = temp->next;  
    }
    printf("\n");
  }
}

void sort(){
  
}

int main(){
  int choice;

  while(1){
    printf("ENter the choice: ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    }
  }

}