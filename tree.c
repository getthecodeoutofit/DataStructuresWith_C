#include<stdio.h>

struct node{
int data;
struct node*lchild,*rchild;
};

struct node *root = NULL;

void check(struct node **par,struct node** loc ,int item){
struct node *tempar,*temloc;

}

void insert(){
struct node*par=NULL,*loc=NULL;
int item;
scanf("%d",&item);
struct node * top = root;
struct node*newnode = (struct node *)malloc(sizeof(struct node));
newnode->data = item;
newnode->lchild = NULL;
newnode->rchild = NULL;
if(root==NULL){
    root = newnode;
    return;
}
else{


}
}

void preorder(struct node *root){
    
    if(root == NULL){
        return;
    }
    printf("%d",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void inorder(struct node *root){
    
    if(root == NULL){
        return;
    }
    preorder(root->lchild);
    printf("%d",root->data);
    preorder(root->rchild);
}
void postorder(struct node *root){
    
    if(root == NULL){
        return;
    }
    preorder(root->lchild);
    preorder(root->rchild);
    printf("%d",root->data);
}


int main(){

    return 0;
}