#include<stdio.h>

void bin(int *arr,int h,int l,int key){
    if(l>=h){
        return;
    }
    int mid = l+((h-l)/2);
    if(arr[mid]==key){
        printf("found index :%d",mid);
        return;
    }
    else if(key > arr[mid]){
        bin(arr,h,mid+1,key);
    }
    else{
        bin(arr,mid-1,l,key);
    }
}

int main(){
    int arr[]= {1,2,3,4,5,6,7,8};
    bin(arr,7,0,4);
    
}