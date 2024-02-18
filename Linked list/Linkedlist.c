#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node* add;
};
//Created the Structure

void Insert_begin(struct node **head){ // Creating the function for insertion of the elements in beginning...

struct node* new=(struct node*)malloc(sizeof(struct node));//Memory allocation
printf("Enter the elemnt to insert: ");
int item;
scanf("%d",&item);
if(*head == NULL){
    *head = new;
    new->add= NULL;
}
else{
    new->add = *head;
    *head = new;
}
new->data = item;
}


void Insert_end(struct node **head){//Creating a function for INserting at end
struct node *new=(struct node*)malloc(sizeof(struct node));;
int item;
printf("Enter the element to insert: ");
scanf("%d",&item);
new->data = item;
new->add = NULL;
if(*head==NULL){
(*head) = new;
}
else{
    struct node *temp = *head;//taking a temporary variable to traverse through the nodes
    while(temp->add!=NULL){
        temp = temp->add;
    }
    temp->add = new;
}
}

void Insert_position(struct node **head){
    struct node * temp=*head;
    struct node *new= (struct node*)malloc(sizeof(struct node));
    int pos,i=0;
    printf("Enter the position to insert the Element: ");
    scanf("%d",&pos);
    int item;
    printf("\nEnter the item : ");
    scanf("%d",&item);
    if((*head==NULL)||(pos ==1)){
        new->add = *head;
        *head = new;
    }
    else{
        for(i=1;(i<pos-1)&&(temp->add!=NULL);i++){
            temp = temp->add;
        }
        new->add = temp->add;
        temp->add = new;

    }
    (new)->data = item;
}

void Insert_sorted(struct node **head){


}

void display(struct node *head){
if(head==NULL){
    printf("\nThe list contain no elements: ");
    return;
}
printf("\n: ");
while(head!=NULL){
    printf("%d ",head->data);
    head = head->add;
}
printf("\n");
}

void pop_front(struct node **head){
if(*head ==NULL){
    printf("\nThe List is Empty: ");
    return;
}
else{
    struct node *temp=*head;
    *head = (*head)->add;
    free(temp);
}
}

void pop_element(struct node **head){
struct node *temp;
int item;
printf("Enter the Item to delete: ");
scanf("%d",&item);

if(*head==NULL){
    printf("No element to pop: ");
    return;
}
else if((*head)->data == item){


}
else{

}
}

int main(){
bool a =true;
struct node * head = 0;
while(a){
printf("\nEnter the choice: ");
printf("\n1-for insertion from front: ");
printf("\n2-for insertion from back: ");
printf("\n3-for insertion at any position: ");
printf("\n5-for pop from front: ");
printf("\n6-for pop from back: ");
printf("\n7-for pop at any Specific position: ");
printf("\n8- to display the elements: ");
printf("\n9- to terminate the program: ");
int choice;
scanf("%d",&choice);
switch(choice){
    case 1:Insert_begin(&head);
    break;
    case 2:Insert_end(&head);
    break;
    case 3:Insert_position(&head);
    break;
    case 4:Insert_sorted(&head);
    break;
    case 5:pop_front(&head);
    break;
    case 6:pop_back(&head);
    break;
    case 7:pop_pos();
    break;
    case 8:display(head);
    break;
    case 9: a = false;
    break;
}
}
return 0;
}