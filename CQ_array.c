#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void insert(int *cq,int *front,int *rear,int *len,int size){
    int num;
    if((*rear==*front-1)||((*rear==size-1)&&(*front ==0))){
        printf("\nTHE CIRCULAR QUEUE IS FULL: ");
        return;
    }
    else{
        printf("\nEnter the element you want to insert: ");
        scanf("%d",&num);
        if(*front == -1){
            *front =0;
            *rear = 0;
           
        }
        else if((*rear==size-1)&&(*front>0)){
            *rear =0;
        }
        else{
            (*rear)++;
        }
        cq[*rear]=num;
        (*len)++;
    }


}

void pop(int *front,int *rear,int *len,int size ){
 if((*front ==-1)){
    printf("\nThe circular queue is empty: ");
    return;
 }
else{
    if(*front == *rear){
        *front =-1;
    }
    else if(*front == size-1){
        *front =0;
    }
    else{
        (*front)++;
    }
    (*len)--;
}
}

void search(int key,int front,int rear,int size,int *cq){
    if(front==-1){
        printf("The queue is empty nothing to search: ");
        return;
    }
    else{
        int i;
        if((rear>front)&&(rear<size)){
            for(i=front;i<=rear;i++){
                if(cq[i]==key){
                    printf("The element is in the queue in index: %d",i);
                    return;
                }

            }
            printf("Element not found:");
        }
        else if(rear <front){
            for(i=front;i<size;i++){
                if(cq[i]==key){
                    printf("The element is in the queue in index: %d",i);
                    return;
                }
            }
            for(i=0;i<=rear;i++){
                 if(cq[i]==key){
                    printf("The element is in the queue in index: %d",i);
                    return;
                }
            }
            printf("The element not found: ");

        }
    }

}



void display(int *cq,int *front,int*rear,int size){
    int i;
    if(*front ==-1){
        printf("\nNothing to display: ");
        return;
    }
    else{
        printf("\nDisplaying the C_Queue: ");
        if(*front<=*rear){
            i = *front;
            while(i<=*rear){
                printf("%d ",cq[i]);
            i++;
            }
            
        }
        else{

                i = *front;
                while(i<size){
                    printf("%d ",cq[i]);
                    i++;

                }
           
                i =0;
                while(i<=*rear){
                    printf("%d ",cq[i]);
                    i++;
                }
            
        }

    }


}

int main(){
int size,choice,key;
bool a = true;
printf("Enter the size of the Queues: ");
scanf("%d",&size);
int cq[size];
int front = -1,rear= -1,len=0;
while(a){
    printf("\nEnter the choice: \n1 for insertion\n2 for Deletion\n3 for search\n4 for length\n5 for printing\n6 for exiting the program: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:insert(cq,&front,&rear,&len,size);
        break;

        case 2:pop(&front,&rear,&len,size);
        break;

        case 3:printf("Enter the lemenet to search: ");
        scanf("%d",&key);
        search(key,front,rear,size,cq);
        break;

        case 4:printf("\nThe length of the queue is: %d",len);
        break;

        case 5:display(cq,&front,&rear,size);
        break;

        case 6: a = false;
        break;

    }

}
return 0;
}