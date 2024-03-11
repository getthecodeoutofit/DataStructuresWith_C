#include<stdio.h>


void search(int *arr,int item,int size){
    int left,right;

}

int main(){
    int size;
    printf("Enter the number of elements: ");
    scanf("%d",&size);
    int array[size];
    int i,item;
    printf("Enter the elements:\n");
    for(i=0;i<size;i++){
        scanf("%d",&array[i]);
    }

    printf("Which item to searh: ");
    scanf("%d",&item);

    search(array,item,size);
    return 0;


}