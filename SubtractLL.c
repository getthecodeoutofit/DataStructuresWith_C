#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

struct node * l1 = NULL;
struct node * l2 = NULL;
struct node * diff = NULL;
 
void insert(struct node **head,int item){
  struct node * newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = item;
  newnode->next = NULL;
  if(*head == NULL){
    *head = newnode;
    return;
  }
  else{
    struct node * temp = *head;
    while(temp->next!=NULL){
      temp = temp->next;
    }
    temp->next = newnode;
  }
  
  
}

void reverse(struct node **head){
  struct node*previous=NULL,*current=*head,*next=(*head)->next;
  while(next!=NULL){
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  *head = previous;
  
};

void subtract(){
  //first reverse both list
 reverse(&l1);
 reverse(&l2);
  
  int borrow,count=0,sub=0,data;
  struct node *p=l1 ,*q =l2;
  
  while(p!=NULL){
    if(p->data-count < q->data){
      if (count ==1){
        sub =1;
      }
      borrow = 1;
      count = 1;
    }
    
    else{
      if(count == 1){
        sub = 1;
      }
      else{
        sub =0 ;
      }
      borrow = 0;
      count =0;
    }
    data = ((p->data-sub)+(borrow*10))-(q->data);
    insert(&diff,data);
    p = p->next;
    q = q->next;
  }
  
  //again reversing back to their original position
  reverse(&diff);
  reverse(&l1);
  reverse(&l2);
}

void display(struct node * head){
  struct node * temp = head;
  while(temp!=NULL){
    printf("%d",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main(){
  int number,i;
  printf("Enter the number of element in the list: ");
  scanf("%d",&number);
    int item;
  printf("Insert Element in LL 1: ");
  for(i=0;i<number;i++){
    scanf("%d",&item);
    insert(&l1,item);
  }
  printf("Insert Element in LL 2: ");
  for(i=0;i<number;i++){
    scanf("%d",&item);
    insert(&l2,item);
  }
  
  subtract();
  printf("  ");
  display(l1);
  printf("- ");
  display(l2);
  printf("  ");
  display(diff);
  
  return 0;
}