#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

struct node{
int data;
struct node*lchild,*rchild;
};

void searchloc(int item);
struct node *root = NULL;
struct node* par=NULL;
struct node *loc=NULL;

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
    if(par==NULL && loc == NULL){
        printf("Item exists: ");
    }

    if(item > par->data){
            par->rchild = newnode;
            return;
        }
    else if(item < par->data){
            par->lchild = newnode;
            return;
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
loc = NULL;
par = NULL;

struct node *temppar = NULL,
*temploc=NULL;

if(root==NULL){
    return;
}
else if(root->data == item){
    loc = root;
    return;
}
else{
    temppar = root;
    if(item>root->data){
        temploc = root->rchild;
        while(temploc!=NULL){
            if(temploc->data == item){
                loc = temploc;
                par = temppar;
                return;
            }
            else if(temploc->data<item){
                temppar = temploc;
                temploc = temploc->rchild;
            }
            else if(temploc->data>item){
                temppar = temploc;
                temploc = temploc->lchild;
            }
            else{
                par =NULL;
                loc =NULL;
                return;
            }

        }
        par = temppar;
        loc = NULL;
    }
    else if(item < root->data){
        temploc = root->lchild;
        while(temploc!=NULL){
            if(temploc->data == item){
                loc = temploc;
                par = temppar;
                return;
            }
            else if(temploc->data<item){
                temppar = temploc;
                temploc = temploc->rchild;
            }
            else if(temploc->data>item){
                temppar = temploc;
                temploc = temploc->lchild;
            }
            else{
                par =NULL;
                loc =NULL;
                return;
            }

        }
        par = temppar;
        loc = NULL;
    }
}



}

int maximum(int a,int b){
  if(a>b){
    return a;
  }
  else {
    return b;
  }


}


int Height(struct node * root){
  if(root == NULL){
    return 0;
  }
  return 1+maximum(Height(root->lchild),Height(root->rchild));

}

void case1(struct node *par ,struct node*loc){

struct node*temp1,*temp2;
temp1 = loc->lchild;
temp2 = loc->rchild;
if (par == NULL){
root = temp2;
struct node *trav = temp2;
while(trav->lchild!=NULL){
trav = trav->lchild;
}
trav->lchild = temp1;
}


else{
  struct node *trav = temp2;
if(par->lchild == loc){
  par->lchild = temp2;
  while(trav->lchild!= NULL){
    trav = trav->lchild;
  }
  trav->lchild = temp1;
}

else if(par->rchild ==loc){
    par->rchild = temp2;
    struct node *trav = temp2;
    while(trav->lchild!= NULL){
      trav = trav->lchild;
    }
    trav->lchild = temp1;
}
}

free(loc);

}

void case2(struct node*par,struct node*loc){

  if(par ==NULL && loc ==root ){
    if (root->rchild ==NULL){
      root = root->lchild;

    }
    else if(root->lchild ==NULL){
      root = root->rchild;
    }

  }
else if(par!=NULL && loc !=NULL){
  if(loc->rchild ==NULL){
    if(par->rchild ==loc){
      par->rchild = loc->lchild;
    }
    else if(par->lchild == loc){
      par->lchild = loc->lchild;
    }
  }

  else if(loc->lchild == NULL){
    if(par->rchild == loc){
        par->rchild = loc->rchild;
    }
    else if(par->lchild ==loc){
      par->lchild = loc->rchild;
    }
  }
}
free(loc);
  }


void case3(struct node*par,struct node * loc){
if(par == NULL && loc ==root){
root = NULL;
}

else if(par !=NULL){
if(loc == par->lchild){
  par->lchild = NULL;
}
else if(loc == par->rchild){
  par->rchild = NULL;
}
}
free(loc);
}

void delete(){
    int item;
    printf("ENter the item: ");
    scanf("%d",&item);
    searchloc(item);


    if(par==NULL&& loc!=NULL){
    printf("location found\n");
}

    if(par == NULL && loc == root){
        if(root->lchild != NULL && root->rchild != NULL){
          case1(par,loc);
        }
        else if(root->lchild == NULL && root->rchild == NULL){
          case3(par,loc);
        }
        else{
          case2(par,loc);
        }
    }
    else if((par == NULL && loc ==NULL)||(par!=NULL && loc ==NULL)){
      printf("no item to delte: \n");
      return;
    }
    else if(par != NULL && par != NULL){
      if (loc ->rchild == NULL && loc -> lchild ==NULL){
        case3(par,loc);
      }
      else if(loc->lchild !=NULL && loc->rchild ==NULL){
        case1(par,loc);
      }
      else{
        case2(par,loc);
      }
    }

}


void klargest(){


}



int main(){
    bool a = true;
    int item;
    int choice;
    printf("1 - Insert element:\t\t2 - Preorder Traversal:\n");
    printf("3 - Inorder Traversal:\t\t4 - Postorder Traversal:\n");
    printf("5 - Deleting by element:\t\t6 - Search Element:\n");
    printf("7 - Exit:\n");
    while(a){
    printf("\nEnter the choice: ");
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
        case 5:delete();
        break;
        case 6:printf("Enter the item to search: ");
        scanf("%d",&item);
        searchloc(item);
        if(loc == NULL){
          printf("No element Found: ");
        }
        else{
          printf("Element found at location : %p\n",loc);
        }
        break;
        case 7:int height = Height(root);
        printf("The height of the tree is: %d\n",height);
        break;
        case 8:a = false;
        break;
    }
    }

    return 0;
}