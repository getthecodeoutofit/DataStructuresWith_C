#include<stdio.h>

void swap(int *arr,int i,int min){
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
}

void selectionSort(int *arr,int n){

    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        swap(arr,i,min);
    }
    
    
}


int main(){
    int n;
    int arr[30];
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,n);
    printf("The sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}