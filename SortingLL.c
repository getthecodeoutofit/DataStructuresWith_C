#include<stdio.h>
#include<stdlib.h>

//sorting of linked list
// time com. = O(n^2)

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
    struct node * temp = Head;
    while(temp->next!=NULL){
      temp = temp->next;
    }
    temp->next = newnode;
  }
}
//----------------------------------------------------------------------

void display(){
  if(Head == NULL){
    printf("No data to display: \n");
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

//---------------------------------------------------------------

void sort(){
  int count =1;
  struct node * trav;
  struct node *move = Head,*temp,*third;

  while(move->next!=NULL){
    temp = move;
    trav = move->next;
while(trav!= NULL){
  if(trav->data < move->data)
    {
    temp->next = trav->next;
    trav ->next = move;
    if(move!=Head){
      third = Head;
      while(third->next!=move){
        third=third->next;
      }
      third->next = trav;
    }
    move = trav;
    trav = temp->next;
  }

  else{
    trav = trav->next;
    temp = temp->next;
  }

    }
    if (count ==1){
      Head = move;
      count++;
    }
    move = move->next;
  }
}

//-----------------------------------------------------------------

void delete(){
struct node * temp;
int item;
if(Head ==NULL){
  printf("no item to delete: \n");
  return;
}
else{
  printf("Enter the item to delete: ");
  scanf("%d",&item);
  if(Head->data == item){
    temp = Head;
    Head = Head->next;
    free(temp);
  }
  else{
    struct node *slow = Head;
    temp = Head->next;
    while(temp!=NULL){
      if(temp->data == item){
        slow ->next = temp->next;
        free(temp);
      }
      slow = temp;
      temp =temp->next;
    }
  }
}
}

//--------------------------------------------------------------------------

int main(){
  int choice;
  printf("1 - insertion:\t\t\t2 - sorting:\n3 - Display: \t\t\t4 - deletion: \n");
  while(1){
    printf("Enter the choice: ");
    scanf("%d",&choice);
    switch(choice){
    case 1:insert();
      break;
    case 2:sort();
      break;
    case 3:display();
      break;
      case 4:delete();
        break;
    }
  }

}