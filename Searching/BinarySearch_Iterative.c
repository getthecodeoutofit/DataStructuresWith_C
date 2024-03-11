#include<stdio.h>

void search(int *arr,int item,int size){
    int left =0,right = size-1;
    while(left < right){
    int mid = left + ((right - left)/2);
        if(arr[mid] == item){
            printf("key found at index : %d\n",mid);
            return ;
        }
        else if(arr[mid]>item){
            right = mid-1;
        }
        else if(arr[mid]<item){
            left = mid+1;   
        }
    }
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