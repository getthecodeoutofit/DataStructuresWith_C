#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node *Tail = NULL;
//tail will store the address of the last element
void Finsert(){
    printf("Enter the item: ");
    int item;
    scanf("%d",&item);
    struct Node * new = (struct Node*)malloc(sizeof(struct Node));
    new->data = item;
    if(Tail == NULL){
        Tail = new;
        new->next = Tail;

    }
    else{ 
        new->next = Tail->next;
        Tail->next = new;
    }
}
void Binsert(){
    printf("Enter the item: ");
    int item;
    scanf("%d",&item);
    struct Node*new = (struct Node*)malloc(sizeof(struct Node));
    new->data = item;
    
    if(Tail == NULL){
        
        new ->next = new;
    }
    else{
        new->next = Tail->next;
        Tail->next = new;
    }
    Tail = new;
}

void display(){
    if(Tail==NULL){
        printf("The list is empty: ");
        return;
    }
    else{
        struct Node*temp = Tail->next;
        do{
            printf("%d ",temp->data);
            temp = temp->next;
        }while(temp!=Tail->next);
    }
}





int main(){


int choice;
while(1){
printf("\nEnter the choice: ");
scanf("%d",&choice);
switch (choice)
{
case 1:Finsert();
    break;
case 2:Binsert();
break;
case 3:display();
break;
default:printf("\nEnter the valid choice: \n");
    break;
}


}

return 0;
}