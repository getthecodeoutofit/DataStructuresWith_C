#include<stdio.h>
#include<stdlib.h>

typedef enum{link,thread} num;

struct Node{
int data;
struct Node *left, *right;
num l,r;
};

struct Node *Head = NULL;
struct Node *parent = NULL;
struct Node *child = NULL;


void insert(){
    struct Node *newnode = (struct Node*)malloc (sizeof(struct Node));
    int item;
    printf("Enter the item to insert: ");
    scanf("%d",&item);
    newnode->data = item;
    if(Head == NULL){
        Head = newnode;
        

    }
    else{

    }
}

void search(){

}

void traversal(){

}

//infix L->node->right
int main(){

int choice,item;
printf("1 - insertion: 2 - deletion: \n");
printf("3 - display: \n");
while(1){
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:insert();
        break;
        case 2:traversal();
        break;
        case 3:printf("ENter the item to search: ");
        scanf("%d",&item);
        search(item);
        break;
        case 5:exit(0);
        break;
    }
}





}