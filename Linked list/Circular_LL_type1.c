#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
int data;
struct node *link;
};

struct node *head = NULL;

void Insert_front(){
struct node *newnode = (struct node*)malloc(sizeof(struct node));
printf("Enter the element: ");
int item;
scanf("%d",&item);
newnode->data = item;

if(head ==NULL){
    head = newnode;
    newnode->link = head;
}

else{
newnode->link = head;

struct node *temp = head;
do{
temp = temp->link;
}while(temp->link!=head);
head = newnode;
temp->link = head;

}
}

void insert_back(){
struct node* newnode = (struct node*)malloc(sizeof(struct node));
int item;
struct node * temp = head;
printf("Enter the item: ");
scanf("%d",&item);

newnode->data = item;

newnode->link = head;

if(head == NULL){
    head = newnode;
    newnode->link = head;

}
else{
    do{
        temp = temp->link;
    }while(temp->link!=head);

    temp->link =  newnode;
}


}

void Insert_between(){

struct node *temp,*new = (struct node *)malloc(sizeof(struct node));

int item,position;

printf("Enter the position you want to enter the element: ");
scanf("%d",&position);

printf("Enter the element: ");
scanf("%d",&item);
new->data = item;
if(head ==NULL||position == 1){
    new->link = head;
    (head)->link = new;
    head = new;
    temp = head;

}
else{
    
    int i;
    for(i=1;(i<position ) && ((temp->link)!=(head));i++){
        temp = temp->link;
    }
    new ->link= temp->link;
    temp->link = new;
}
}

void display(){
struct node *temp = head;
do{
    printf("%d ",temp->data);
    temp = temp->link;
}while(temp != head);
}

void pop_front(){
struct node* temp = head;
if(head == NULL){
    printf("No element to remove: ");
    return;
}
else{
    struct node *p = head;
    do{
        p = p->link;
    }while(p->link!=head);
    head = head->link;
    p->link = head;
    free(temp);
}

}

void pop_back(){
struct node *temp=head;
if(head == NULL){
    printf("The node is empty: ");
    return;
}
else{

}
}

void pop_between(){
int pos;
if(head == NULL){
printf("No element to delete: ");
return;
}
printf("Enter the position to delete: ");
scanf("%d",&pos);
struct node * temp = head;
int count = 1;

while(temp!=head){
count++;
temp = temp->link;
}
struct node * itr = head;
if((pos<=count)&&(pos>0)){
    if(pos == 1 ){
        head = head->link;
        free(itr);
        return;
    }
    else{

    }
 }


else if(pos>count){
    printf("Range out of bound: ");
    return;
}
}


int main(){
printf("This is a circular linked list........................\n");
bool a = true;
int choice;
while(a){
printf("1 - insertion front:\t\t2 - insertion between:\n");
printf("3 - insert at any location:\t4 - pop front:\n");
printf("4 - pop back:\t\t\t5 - pop from any location:\n");
printf("7 - Displayig the element:\t8 - Exiting the program:\n");
printf("Enter the choice: ");
scanf("%d",&choice);
switch(choice){
    case 1:Insert_front();
    break;
    case 2:insert_back();
    break;
    case 3:Insert_between();
    break;
    case 4:pop_front();
    break;
    case 5:pop_back();
    break;
    case 6:pop_between();
    break;
    case 7:display();
    break;
    case 8:a = false;
    break;
}
}


return 0;
}