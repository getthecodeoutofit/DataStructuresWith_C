#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *right,*left;
};

struct node * Maxroot =NULL;
struct node * Minroot = NULL;


void Maxinsertion(){
struct node *newnode = (struct node*)malloc(sizeof(struct node));
int item;
printf("Enter the Data: ");
scanf("%d",&item);
newnode->data = item;
newnode->right = NULL;
newnode->left = NULL;
if(Maxroot == NULL){
    Maxroot = newnode;
    return;
}
else{

}


};

void Mininsertion(){
struct node *newnode = (struct node*)malloc(sizeof(struct node));
int item;
printf("Enter the Data: ");
scanf("%d",&item);
newnode->data;
newnode->right = NULL;
newnode->left = NULL;
if(Minroot == NULL){
    Minroot = newnode;
    return;
}
else{

}

};

void display(){

};

void Maxdeletion(){

};

void Middeletion(){

};


int main(){



return 0;
};