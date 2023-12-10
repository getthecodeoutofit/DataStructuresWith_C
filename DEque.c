#include<stdlib.h>
#include<stdio.h>


struct node{
    int data;
    struct node * next;
};

struct node * head = NULL;

void frontinsert(){

    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    int item;
    printf("Enter the element: ");
    scanf("%d",&item);
    newnode->data = item;
    newnode->next = head;
    head = newnode;

}

void backinsert(){
    int item;
    printf("Enter the element: ");
    scanf("%d",&item);
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode ->data = item;
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


void frontdelete(){
    if(head == NULL){
        printf("Empty: \n");
        return;
    }
    printf("poping front element: \n");

    struct node* temp = head;
    head = head->next;
    free(temp);
}

void backdelete(){

    printf("Deleting item from end: \n");
    if(head == NULL){
        printf("no item to pop: \n");
        return;
    }

    else if(head->next == NULL){
        head = NULL;
        return;
    }

    else {
        struct node * slow = head,*fast = head->next;
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = NULL;
        free(fast);

    }



   
}

void display(){
    struct node * temp = head;

    if(head == NULL){
        return;
    }
    else{
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    int choice;
    printf("1 - insertion at front:\t\t\t2 - insertion at back:\n3 - pop at front:\t\t4 - pop at back:\n5 - display:\n");
    while(1){
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:frontinsert();
            break;
            case 2:backinsert();
             break;
             case 3:frontdelete();
             break;
             case 4:backdelete();
             break;
             case 5:display();
             break;
             default:printf("Enter valid:\n");
             break;
        }
    }
}