#include<stdio.h>

void selectionSort(int *arr,int n){
    
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
        printf("%d",arr[i]);
    }
}