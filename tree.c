#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
int data;
struct node*lchild,*rchild;
};

void searchloc(int item);
struct node *root = NULL;
struct node* par=NULL;struct node *loc=NULL;

void insert(){
    int item;
    printf("ENter the item to insert: ");
    scanf("%d",&item);
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    newnode->data = item;
    if(root == NULL){
        root = newnode;
        return;
    }
    searchloc(item);


    if(item > loc->data){
            loc->rchild = newnode;
            return;
        }
    else if(item < loc->data){
            loc->lchild = newnode;
            return;
        }
}

void preorder(struct node *root){
    
    if(root == NULL){
        return;
    }
    printf("%d\t",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void inorder(struct node *root){
    
    if(root == NULL){
        return;
    }
    preorder(root->lchild);
    printf("%d\t",root->data);
    preorder(root->rchild);
}
void postorder(struct node *root){
    
    if(root == NULL){
        return;
    }
    preorder(root->lchild);
    preorder(root->rchild);
    printf("%d\t",root->data);
}


void searchloc(int item){
struct node *temppar = NULL,*temploc=NULL;
if(root ==NULL){
    par = NULL;
    loc = NULL;
    return;
}
if(root ->data == item){
        par = NULL;
        loc = root;
        return ;
}
else{
        temploc = root;

        while((temploc->lchild != NULL )&&(temploc->rchild!=NULL)){
        if(item < temploc->data){
            temppar = temploc;
            temploc = temploc->lchild;

        }
        else if(item > temploc->data){
            temppar = temploc;
            temploc = temploc->lchild;

        }
        else if(temploc->data == item){
            par = temppar;
            loc = temploc;
            return;
        }

        }
        loc = temploc;
        par = temppar;

    }
}


void DeleteElement(){
    int item;
    printf("Enter the element to delete: ");
    scanf("%d",&item);
    searchloc(item);
    if(root == NULL){
        printf("Element not found: ");
        return ;
    }
    else if(root->data == item){


    }

}

int main(){
    bool a = true;
    int choice;
    printf("1 - Insert element:\t\t2 - Preorder Traversal:\n");
    printf("3 - Inorder Traversal:\t\t4 - Postorder Traversal:\n");
    printf("5 - Deletin by element:\t\t6 - Search Element:\n");
    printf("7 - Exit:\n");
    while(a){
    printf("Enter the choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:insert();
        break;
        case 2:preorder(root);
        break;
        case 3:inorder(root);
        break;
        case 4:postorder(root);
        break;
        case 5:DeleteElement();
        break;
        case 6:
        int item;
        scanf("%d",&item);
        searchloc(item);
        break;
        case 7:a = false;
        break;
    }
    }

    return 0;
}