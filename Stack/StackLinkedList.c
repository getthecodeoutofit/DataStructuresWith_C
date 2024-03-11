#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int stacksize = 0;

struct node{
    int data;
struct node* link;
};

void listinsert(struct node **top_add,int num,int *size){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data=num;
    temp->link = *top_add;
    *top_add = temp;
    (*size)++;
}

void listpop(struct node **top_add,int *size){
if(*top_add==NULL){
    printf("the stack is empty: ");
    return;
}
else{
    struct node* temp;
    temp = *top_add;
    *top_add = temp->link;
    free(temp);
}
(*size)--;
}

void listprint( struct node *top_add){
    
    struct node *temp1 = top_add;
  if(temp1 == NULL){
        printf("\nThe stack is empty: ");
        return;
    }
    while(temp1!=NULL){
        printf("%d ",temp1->data);
        temp1 = temp1->link;
    }
}

void searchlist(struct node *top,int key){
    
    while(top!=NULL){
        
        if(top->data == key){
            printf("\nThe number found with structure address: %p",top);
            return;
        }
        top = top->link;
    }
    printf("Not found: ");
}

int main(){
    bool b =true;
    struct node *top_add = NULL;
    int num,choice,key;
while(b){

    printf("\nEnter the choice: \n1 for insertion\n2 for deletion\n3 for printing\n4 for searching\n5 for checking length of stack\n6 for exit : ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("\nEnter the number to insert: ");
        scanf("%d",&num);
        listinsert(&top_add,num,&stacksize);
        printf("Insterted...\n");
        break;

    case 2:
        printf("\ndeleting the element..... \n");
        listpop(&top_add,&stacksize);
        break;
        
    case 3:
        printf("\nprinting the stack: ");
        listprint(top_add);
        break;

    case 4 :printf("enter the element to search: ");
       scanf("%d",&key);
       printf("searching the element... \n");
       searchlist(top_add,key);
       break;

    case 5 : printf("the size of stack is: %d\n",stacksize);

        break;

    case 6: b = false;
       break;
    
    default:printf("Enter the valid choice: ");
        break;

    }
}
return 0;
}