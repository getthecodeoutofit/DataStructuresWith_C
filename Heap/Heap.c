#include<stdio.h>
#include<stdlib.h>

//array Implementation

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
};

void Max(int * arr,int *size){
    int item;
    printf("Enter the item: ");
    scanf("%d",&item);
    (*size)+=1;
    arr[(*size)] = item;

    int newsize = *size;

    while(newsize > 1){

    int parent = newsize/2;
    if(arr[parent] < arr[newsize]){

        swap(&arr[parent],&arr[newsize]);
    }
    newsize/=2;
    }
}

void Min(int * arr,int *size){
    int item;
    printf("Enter the item: ");
    scanf("%d",&item);

    (*size)+=1;
    arr[(*size)] = item;

    int newsize = *size;

    while(newsize > 1){

    int parent = newsize/2;
    if(arr[parent] > arr[newsize]){

        swap(&arr[parent],&arr[newsize]);
    }
    newsize/=2;
    }

};

void Display(int *arr,int size){
    int i;
    for(i=1;i<=size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

}

void MinSort()
{

};

void MaxSort(){

};

void MaxDelete(){

};

void MinDelete(){

};

int main(){
    int max[100],Msize = 0;
    int min[100],msize = 0;
    int choice;
    printf("1 - Insert Maxheap:\t\t2 - Insert MinHeap:\n");
    printf("3 - Display Maxheap:\t\t4 - Display MinHeap:\n");
    printf("5 - Deletion Maxheap:\t\t6 - Deletion MinHead:\n");
    printf("7 - Sorting MaxHeap:\t\t8 - Sorting MinHeap:\n");

    while(1){
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:Max(max,&Msize);
            break;
            case 2:Min(min,&msize);
            break;
            case 3:Display(max,Msize);
            break;
            case 4:Display(min,msize);
            break;
            case 5:
            break;

        }
    }



return 0;
};