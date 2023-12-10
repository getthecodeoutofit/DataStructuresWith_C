#include <stdio.h>
#include<stdlib.h>


struct node{
    
    int data;
    struct node * lchild,*rchild;
    
  };
  
  struct node * root = NULL;
  
  
  void insert(){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    int item;
    newnode->data = item;
    newnode->rchild = NULL;
    newnode->lchild = NULL;
  }
  
  void check(){
    struct node * temp = root;
  }
  
  int main(){
    int choice;
    while(1){
      printf("Enter the choice: ");
      scanf("%d",&choice);
      switch(choice){
        case 1:
          break;
          case 2:
            break;
            case 3:
              break;
              case 4:
                break;
      }
    }
    
  }
  