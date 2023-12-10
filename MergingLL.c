#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node * next;
};

struct node * head1 = NULL;
 struct node * head2 = NULL;
 struct node *mainhead = NULL;

void insert(struct node ** Head){
  struct node * newnode = (struct node *)malloc(sizeof(struct node));
  int item;
  printf("Enter the data: ");
  scanf("%d",&item);
  newnode->data = item;
  newnode->next = NULL;
  if(*Head == NULL){
    *Head = newnode;
    return;
  }
  else{
    struct node *temp = *Head;
    while(temp->next!=NULL){
      temp = temp->next;
    }
    temp->next = newnode;
  }
}

void sortMerge(){
  struct node * temp1= head1,*temp2= head2;

  if(head1->data<head2->data){
    mainhead = head1;
  }
  else{
    mainhead = head2;
  }
  while(temp1!=NULL || temp2!=NULL){
    if(temp1->data < temp2->data){
      

    }


  }


}

int main(){
  int choice;
  while(1){
    printf("Enter the choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1:insert(&head1);
        break;
        case 2:insert(&head2);
          break;
          case 3:sortMerge();
            break;
            case 4:
               break;
    }
  }

return 0;
}