#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    struct node*prev;
    int data;
    struct node *next;
};

struct node *start = NULL,*end = NULL;

void Finsert(){
printf("Enter the Item to Insert: ");
int item;
scanf("%d",&item);
struct node *new = (struct node *)malloc(sizeof(struct node));
new->data = item;
new->prev = NULL;
if(start == NULL){
end = new;
new ->next = NULL;
}
else{
    new->next = start;
    start->prev = new;
}
start = new;

}
void Binsert(){
printf("Enter the item to insert: ");
int item;
fflush(stdin);
scanf("%d",&item);
struct node *new = (struct node *)malloc(sizeof(struct node));
new ->data = item;
new->next = NULL;
if(start == NULL){
start = new;
new->prev = NULL;
}
else{
end->next = new;
new->prev = end;
}
end = new;
}

void Pinsert(){
struct node* new = (struct node*)malloc(sizeof(struct node));
printf("Enter the position to insert: ");
int pos,item;
scanf("%d",&pos);
printf("Enter the item to INsert: ");
scanf("%d",&item);
int i;
struct node *temp = start;
new->data = item;
if(start == NULL){
start = new;
end = new;
}
else{
for(i=1;(i<pos-1)&&(temp->next!=NULL);i++){
temp = temp->next;
}
new->next=temp->next;
temp->next = new;
new->prev = temp;
}
}

void Fpop(){
if(start==NULL){
    printf("The Linked List is empty:\n");
    return;
}
else{
    printf("Deleting item...........\n");
    struct node* temp = start;
    start = start->next;
    if(start!=NULL){
    start->prev = NULL;
    }
    else{
        end=NULL;
    }
    free(temp);
}
}

void Bpop(){
if(start == NULL){
printf("Linked List is empty:\n");
return;
}
else{
    printf("Deletion the Item........\n");
    struct node* temp = end;
    end = end->prev;
    if(end != NULL){
        end->next=NULL;
    }
    else{
        start = NULL;
    }
    free(temp);
}
}

void Ppop(){
if(start == NULL){
    printf("Empty stack: ");
    return;
}
else{
    printf("Enter the position of element: ");
    int pos;
    scanf("%d",&pos);
    printf("Deletiong the element: ");
}
}

void selectpop(){

}

void display(){
    struct node *temp = start;
    printf(": ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
bool a = true;
printf("1-for insertion from front:\t\t2-for insertion from back:");
printf("\n3-for insertion ant any position:\t4-for pop from front:");
printf("\n5-for pop from back:\t\t\t6-for pop at specific position:");
printf("\n7-fro pop from selected position:\t8-for pop any slected item:");
printf("\n10-for exiting:\n\n");
while(a){
printf("Enter the choice: ");

int choice;
scanf("%d",&choice);
switch(choice){
    case 1:Finsert();
    break;
    case 2:Binsert();
    break;
    case 3:Pinsert();
    break;
    case 4:Fpop();
    break;
    case 5:Bpop();
    break;
    case 6:Ppop();
    break;
    case 7:selectpop();
    break;
    case 8:display();
    break;
    case 10:a = false;
    break;
}
    }
return 0;
}