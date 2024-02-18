#include<stdio.h>

#include<stdlib.h>

struct node
    {
  int data;
  struct node* next;
    };
    
    struct node * head = NULL;

void insert(int item){
  struct node * newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data =item;
  newnode->next = NULL;
  if(head == NULL){
    head = newnode;
    return;
  }
  else{
    struct node * temp = head;
    while(temp->next!=NULL){
      temp = temp->next;
    }
    temp->next = newnode;
  }
}

void searchpair(int *p,int pair){
  int i,j,nodesize=0;
  struct node *temp = head;
  while(temp!=NULL){
    nodesize++;
    temp = temp->next;
  }
  
  temp = head;
  struct node *temp2 = head->next;
  
    temp = head;
  for(i=0;i<=nodesize;i++){
    
    for(j=0;j<=nodesize;j++){
      if((temp->data+temp2->data)%pair == 0){
        p[0] = temp->data;
        p[1] = temp2->data;
        return;
      }
      else{
        temp2 = temp2->next;
      }
    }
    temp = temp->next;
    temp2 = temp;
  }
  printf("no pair found: \n");
  
  
}

int main(){
  int num,size=0,arr[50],i,item;
  
  printf("Enter the number of element to insert: ");
  scanf("%d",&num);
  
  for(i=0;i<num;i++){
    printf("Enter the element: ");
    scanf("%d",&item);
    insert(item);
  }
  
  
  printf("Enter the element to find the pair: ");
  int pair;
  scanf("%d",&pair);
  searchpair(arr,pair);
 
  for(i=0;i<2;i++){
    printf("%d ",arr[i]);
  }
  
  return 0;
}