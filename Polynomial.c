#include<stdio.h>
#include<stdlib.h>

struct node{
    int coff;
    char var;
    int exp;
    struct node * next;
};

struct node * poly1 = NULL;
struct node * poly2 = NULL;
struct node * added = NULL;


void insert(struct node ** root){
    int coffecient,var,exp;
    printf("Enter the coffecient variable and exponent: ");
    scanf("%d %c %d",&coffecient,&var,&exp);
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coff = coffecient;
    newnode->var = var;
    newnode->exp = exp;
    newnode->next = NULL;
    if(*root == NULL){
        *root = newnode;
        return;
    }
    else{
        struct node *temp = *root;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;

    }
}

void add(){
    struct node * p = poly1;
    struct node *q = poly2;
    int len1=0,len2=0;

    while(p!=NULL){
        p = p->next;
        len1++;
    }

     while(q!=NULL){
        q = q->next;
        len2++;
    }

    p = poly1;
    q = poly2;

    while(len1<len2){
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coff = p->coff;
    newnode->exp = p->exp;
    newnode->var = p->var;
    newnode->next = NULL;
    if(added == NULL){
        added = newnode;
    }
    else{
        struct node * temp = added;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp ->next = newnode;
    }

    p = p->next;
    len2--;

    }


    while(len2<len1){
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coff = q->coff;
    newnode->exp = q->exp;
    newnode->var = q->var;
    newnode->next = NULL;
    q = q->next;
    len1--;
    if(added == NULL){
        added = newnode;
    }
    else{
        struct node * temp = added;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp ->next = newnode;
    }
    }

    while(p!=NULL){
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coff = q->coff+p->coff;
    newnode->var = q->var;
    newnode->exp = q->exp;
    newnode->next = NULL;
    q = q->next;
    p =p->next;
    if(added == NULL){
        added = newnode;
    }
    else{
        struct node * temp = added;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp ->next = newnode;  
    }

    }
    
}

void display(){
    struct node * temp = added;
    while(temp!=NULL){
        printf("%d %c ^%d ",temp->coff,temp->var,temp->exp);
        if(temp->next!= NULL){
            printf("+ ");
        }
        temp = temp->next;
    }
}

int main(){

int choice;
while(1){
    printf("Enter the choice: ");
    scanf("%d",&choice);
    switch(choice){
    case 1: insert(&poly1);
    break;
    case 2:insert(&poly2);
    break;
    case 3:
    add();
    display();
    break;


}
}

    return 0;
}