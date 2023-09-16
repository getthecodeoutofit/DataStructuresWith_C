#include<stdio.h>
#include<stdbool.h>
void insertion(int num,int size,int *stack,int *top){
    if(*top>=size-1){
        printf("stack overflow: ");
        return;
    }
    if(*top == -1){
        *top = 0;
        stack[*top]=num;

    }
    else{
        (*top)++;
        stack[*top]=num;
    }

}
void pop(int*top){
if(*top==-1){
    printf("no element to pop: ");
    return;
}
(*top)--;
}
void traverse(int *stack, int *top){
    int i;
    if(*top == -1){
        return;
    }
    for(i=0;i<=*top;i++){
        printf("%d ",stack[i]);
    }

}
void searching(int key,int *stack,int *top){
    int i;
    if(*top==-1){
        return;
    }
    for(i=0;i<=*top;i++){
        if(stack[i]==key){
            printf("the element found at index = %d",i);
            return;
        }
    }

}

int main(){
    int size,top,choice,num,k;
    printf("enter the size of the stack: ");
    scanf("%d",&size);
    int a[size];
    bool b = true;
    top = -1;
    while(b){
        printf("enter the choice you want to make: \n1 for insertion \n2 for pop\n3for traversing\n4 for searching\n5 for exit: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        printf("enter the number to insert: ");
        scanf("%d",&num);
        insertion(num,size,a,&top);
        break;
        case 2:pop(&top);

        break;
        case 3:traverse(a,&top);
        break;

    case 4:printf("enter the element to search: ");
    scanf("%d",&k);
    searching(k,a,&top);
    break;
    case 5:
    b = false;
    break;
        default:
        printf("enter the valid value: ");
        break;
        }
    }
}