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

}

void Fpop(){

}

void Bpop(){

}

void Ppop(){

}

void selectpop(){

}

void display(){
    struct node *temp = start;
    printf("\n: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
bool a = true;
while(a){
printf("Enter the choice: ");
printf("\n1 for insertion from front:\n2 for insertion from back:\n");
printf("\n : ");
int choice;
scanf("%d",&choice);
switch(choice){
    case 1:Finsert();
    break;
    case 2:Binsert();
    break;
    case 8:display();
    break;
    case 10:a = false;
    break;
}
    }
return 0;
}