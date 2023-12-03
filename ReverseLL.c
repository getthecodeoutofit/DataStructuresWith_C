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
    struct node * temp = Head ;
    while(temp->next!=NULL){
      temp = temp->next;
    }
    temp->next = newnode;
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

void reverse(){
  
  if(Head == NULL){
    return;
  }
  
  else{
    struct node* previous = NULL;
    struct node * current = Head ,*next = current->next;
    while(next != NULL){
      next = current->next;
      current->next = previous;
      previous = current;
      current = next;
    }
    Head =previous;
  }
}

void delete(){
  struct node * temp = Head->next;
    int item;
    printf("Enter the item to delete: ");
    scanf("%d",&item);
  if(Head == NULL){
    printf("No item to delete: \n");
    return;
  }
  else if(Head->data == item){
    temp = Head;
    Head = Head->next;
    free(temp);
  }
  else{
    struct node * prev = Head;
    while(temp!=NULL){
      if(temp->data == item){
        prev ->next = temp->next;
        free(temp);
        return;
      }
      prev = temp;
      temp  = temp->next;

    }
    if(temp == NULL){
      printf("Item not found: \n");
    }
  }
}

int main(){
  int choice;
  printf("1 - Insertion:\t\t\t2 - Display: \n3 - Reversal: \t\t\t4 - Deletion:\n");
  while(1){
    printf("\nEnter the choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1:insert();
        break;
        case 2:display();
          break;
          case 3:reverse();
            break;
            case 4:delete();
              break;
    }
  }
  
}