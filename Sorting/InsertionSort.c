#include<stdio.h>

void insertionSort(int *arr,int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

int main(){
    int n;
    int arr[30];
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++){
scanf("%d",&arr[i]);
    }
    insertionSort(arr,n);
    printf("The array is now: ");
    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}