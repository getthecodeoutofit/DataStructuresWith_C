#include<stdio.h>

void swap(int *arr,int l,int h){
  int temp = arr[l];
  arr[l] = arr[h];
  arr[h] = temp;
}

int piv(int *arr,int l,int h){
  int piv = h--;
  while(l < h){
    if(arr[l]<arr[piv]){
      l++;
    }

    else if(arr[h]>arr[piv]){
      h--;
    }

    else{

      swap(arr,l,h);
      h--;
      l++;
    }
  }
  swap(arr,l,piv);
  return l;

}

void quick(int *arr,int l,int h){
if(l>=h){
  return;
}
int pivot = piv(arr,l,h);
quick(arr,l,pivot-1);
quick(arr,pivot+1,h);
}

int main(){
  int arr[] = {8,56,3,9,1,3,5};

  quick(arr,0,6);
  for(int i=0;i<7;i++){
    printf("%d ",arr[i]);
  }



  return 0;
}