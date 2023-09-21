#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
int data;
struct nodde *link;
};

void Insert_front(struct node **head){
struct node *new = (struct node*)malloc(sizeof(struct node));
struct node *temp = *head;
printf("Enter the element: ");
int item;
scanf("%d",&item);
new->data = item;

if(*head ==NULL){
    *head = new;
    temp = new;  
}

else{
while((temp->link)!=(*head)){
temp = temp->link;
}
temp->link = new;
}
new->link = (*head);
}

void Insert_between(struct node **head){
struct node *temp,*new = (struct node *)malloc(sizeof(struct node));
int item,position;
printf("Enter the position you want to enter the element: ");
scanf("%d",&position);
printf("Enter the element: ");
scanf("%d",&item);
new->data = item;
if(*head ==NULL||position == 1){
    new->link = *head;
    (*head)->link = new;
    *head = new;
    temp = *head;

}
else{
    
    int i;
    for(i=1;(i<position ) && ((temp->link)!=(*head));i++){
        temp = temp->link;
    }
    new ->link= temp->link;
    temp->link = new;
}
}

void display(struct node *head){
struct node *temp = head;
do{
    printf("%d ",temp->data);
    temp = temp->link;
}while(temp != head);
}

void pop(){

}

void pop_between(){

}

int main(){
struct node *head = NULL;
printf("This is a circular linked list........................\n");
bool a = true;
int choice;
while(a){
printf("Enter the choice: \n");
printf("");
printf("");
printf("");
scanf("%d",&choice);
switch(choice){
    case 1:Insert_front(&head);
    break;
    case 2:Insert_between(&head);
    break;
    case 3:pop(&head);
    break;
    case 4:pop_between(&head);
    break;
    case 5:display(head);
    break;
    case 6:a = false;
    break;
}
}


return 0;
}