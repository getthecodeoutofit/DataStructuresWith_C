#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct node{
int data;
struct node*lchild,*rchild;
};

void searchloc(int item);
struct node *root = NULL;
struct node* par=NULL;
struct node *loc=NULL;
//--------------------------------------------------------------------------------------
void insert(){
    int item;
    printf("Enter the item to insert: ");
    scanf("%d",&item);
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    newnode->data = item;
    if(root == NULL){
        root = newnode;
        return;
    }
    else{
      struct node * temp = root;
      while(temp!=NULL){
        if(temp->data > item){
          
          if(temp->lchild !=NULL){
            temp = temp->lchild;
          }
          else{
            temp->lchild = newnode;
            return;
          }
          
        }
        else if(temp->data < item){
          if(temp->rchild !=NULL){
            temp = temp->rchild;
          }
          else{
            temp->rchild = newnode;
            return;
          }
        }
      }
    }
}
//-----------------------------------------------------------------------------

void preorder(struct node *root){
    if(root == NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    inorder(root->lchild);
    printf("%d ",root->data);
    inorder(root->rchild);
}
void postorder(struct node *root){
    
    if(root == NULL){
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ",root->data);
}

//--------------------------------------------------------------------------------
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
    if(item > root->data){
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
//------------------------------------------------------------------------------------------
int maximum(int a,int b){
  if(a>b){
    return a;
  }
  else {
    return b;
  }

}
//----------------------------------------------------------------------------------

int leaf(struct node* root){
  static int count = 0 ;
  if(root == NULL){
    return 0;
  }
  if(root->lchild == NULL && root ->rchild == NULL){
    return 1;
  }

  count += leaf(root->lchild);
  count += leaf(root->rchild);
  int a = count;
  count = 0;
  return a;

}
//-------------------------------------------------
int max =0;
int finddia(struct node * root,int *max){
  if(root == NULL){
    return 0;
  }

  int lh = finddia(root->lchild,max);
  int rh = finddia(root->rchild,max);
  *max = maximum(*max,1+lh+rh);
  return 1 + maximum(lh,rh);
}

//----------------------------------------------

int successor(struct node * root,int num){
int suc =0;
if(root==NULL ){
    return 0;

  }
  while(root->data!=num ){
    suc = root->data;
    if(num > root->data){
      root = root->rchild;
    }
    else if(num < root->data){
      root=root->lchild;
    }
  }

  root = root->rchild;
  while(root!=NULL){
    root = root->lchild;
    if(root!=NULL){
    suc = root->data;
    }
  };

return suc;
  
}

//-----------------------------------------
int predecessor(struct node * root,int num){

  int pre =0;
  if(root == NULL ){
    return 0;

  }
  while(root->data!=num && root != NULL){
    pre = root->data;
    if(num > root->data){
      root = root->rchild;
    }
    else if(num < root->data){
      root=root->lchild;
    }
  }
  root = root->lchild;
  while(root!=NULL){
    root = root->rchild;
    if(root!=NULL){
    pre = root->data;
    }
  };
  return pre;
};

//----------------------------------------------------------------------------------------------
int atleastchild(struct node *root){
  if (root == NULL) {
    return 0;
  }

  // Initialize count for this node
  int childcount = 0;

  // Check if the node has at least one child
  if (root->lchild != NULL || root->rchild != NULL) {
    childcount = 1;
  }

  // Recursively count nodes with at least one child in left and right subtrees
  childcount += atleastchild(root->lchild);
  childcount += atleastchild(root->rchild);

  return childcount;
}

//======================================================================================================

int Height(struct node * root){
  if(root == NULL){
    return 0;
  }
  return 1+maximum(Height(root->lchild),Height(root->rchild));

}

//-----------------------------------------------------------------------------------------------------

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
//------------------------------------------------------------------------------------------------

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
//----------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------------

int arsize=0;
int arr[50];

void klargest(struct node * root){
  if(root==NULL){
    return;
  }
  arr[arsize]=root->data;
  arsize++;
  klargest(root->lchild);
  klargest(root->rchild);
}
//-------------------------------------------------------------------------
int rightcount(struct node* root){
    if(root == NULL){
      return 0;
    }
    int count =1;
    count += rightcount(root->lchild);
    count += rightcount(root->rchild);
    return count;
};
//-----------------------------------------------------------------
int leftcount(struct node * root){
    if(root ==NULL){
      return 0;
    }
    int count = 1;
    
    count += leftcount(root->lchild);
    count += leftcount(root->rchild);
    return count;
};

//----------------------------------------------------------------------------

int atmost(struct node * root){
  if(root == NULL){
    return 0;
  }

  int count=0;
  if(root->lchild!=NULL && root->rchild !=NULL){
    count = 1;
  }
  count += atmost(root->lchild);
  count += atmost(root->rchild);
  return count;
}

//--------------------------------------------------------------------------------------

int main(){
    bool a = true;
    int item,height,count,j,k,large,child,rnum=0,lnum=0,most;
    int choice;
    printf("\n\n1 - Insert element:\t\t\t2 - Preorder Traversal:\n");
    printf("3 - Inorder Traversal:\t\t\t4 - Postorder Traversal:\n");
    printf("5 - Deleting by element:\t\t6 - Search Element:\n");
    printf("7 - Height of Tree:\t\t\t8 - Count of Leaf Nodes:\n");
    printf("9 - K largest element:\t\t\t10 - count number of node with child:\n");
    printf("11 - Number of leftnodes:\t\t12 - number of right nodes: \n");
    printf("13 - Number of nodes with 2 child:\t14 - Diameter of tree:\n");
    printf("15 - Successor of a number:\t\t16 - predecessor of a number:\n");
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
        case 7:
        height = Height(root);
        printf("The height of the tree is: %d\n",height);
        break;
        case 8:count = leaf(root);
        printf("%d\n",count);
        break;
        case 9:arsize =0;
          klargest(root);
          for(j=0;j<arsize;j++){
            
            for(k=0;k<arsize-1-j;k++){
              if(arr[k] > arr[k+1]){
                int temp = arr[k];
                arr[k]=arr[k+1];
                arr[k+1] = temp;
              }
            }
            
          }
          printf("Enter the n largest number: ");
          scanf("%d",&large);
          printf("The number is: %d",arr[large-1]);
        break;
        case 10:
          child = atleastchild(root);
          printf("%d",child);
        break;
        case 11:
        if(root != NULL){
        rnum = rightcount(root->rchild);
        }
        printf("The number of nodes in the right subtree are: %d",rnum);
        break;
        case 12:
        if(root!=NULL){
        lnum = leftcount(root->lchild);
        }
        printf("The number of nodes on left subtree are: %d",lnum);
        break;
        case 13: 
        most = atmost(root);
        printf("The number of nodes: %d",most);
        break;
        case 14:int diameter =0;
        finddia(root,&diameter);
        printf("%d",diameter);
        break;
        case 15:printf("Enter the element to find its successor: ");
        scanf("%d",&item);
        int succ;
        succ = successor(root,item);
        printf("The successor is: %d\n",succ);
        break;
        case 16:
        printf("Enter the element to find its predecessor: ");
        scanf("%d",&item);
        int pre;
        pre = predecessor(root,item);
        printf("The predecessor is: %d\n",pre);
        break;
        case 17:a = false;
        break;
        
        default:printf("Enter a valid choice:\n");
        break;
    }
    }
    return 0;
}