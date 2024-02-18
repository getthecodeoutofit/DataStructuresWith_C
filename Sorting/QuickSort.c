#include<stdio.h>


int fn(int * arr,int low,int high){
    
    int i=low,j=high;
    int pivot = arr[low];
    
    while(i<j){
      while(pivot >= arr[i] && i <= high){
        i++;
      }
      while(pivot <= arr[j] && j>=low){
        j--;
      }
      if(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    if(i==j){
      int temp = arr[low];
      arr[low] = arr[i];
      arr[i] = temp;
    }
    return j;
  
};

void QuickSort(int *arr,int low,int high){
  
  if(low<high){
    int pivot = fn(arr,low,high);
    QuickSort(arr,low,pivot-1);
    QuickSort(arr,pivot+1,high);
  }
  
}

int main(){
  
  int arr[40];
  int n,i;
  printf("Enter the size of array: ");
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
  printf("Enter the element: ");
    scanf("%d",&arr[i]);
  }
  
  QuickSort(arr,0,n-1);
  
  printf("The array is:");
  
  for(i=0;i<n;i++){
    printf(" %d",arr[i]);
  }
  return 0;
}