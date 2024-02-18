#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data;
struct node *next;
}node;

void insert(node **head,int item){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = item;
    newnode->next = NULL;
    if(*head == NULL){
        *head = newnode;
    }
    else{
        node *temp = *head;
        while(temp->next == NULL){
            temp = temp->next;

        }
        temp->next = newnode;
    }

}

void display(node *head){
    while(head!=NULL){
        printf("%d->",head->data);
        head = head->next;
    }

}

void adjust(node **head1,node **head2){

}

int main(){
    node *head1 = NULL,*head2 =NULL;
    int item;
    int n1,n2;
    printf("Enter the size of node 1: ");
    scanf("%d",&n1);
    printf("Enter the size of node 2: ");
    scanf("%d",&n2);
    printf("Enter the item in LL1: ");
    for(int i=0;i<n1;i++){
        scanf("%d",&item);
        insert(&head1 ,item);
    }
    printf("Enter the item in LL2: ");
    for(int i=0;i<n2;i++){
        scanf("%d",&item);
        insert(&head2,item);
    }
    // adjust(&head1,&head2);
    
    


    return 0;
}
