#include<stdio.h>

void merge(int *arr,int l,int m,int h){
    int n1 = m-l+1;
    int n2 = h-m;
    printf("Getting: \n");
    int arr1[n1],arr2[n2];

    for(int i=0;i<n1;i++){
        arr1[i] = arr[l+i];
    }

    for(int i=0;i<n2;i++){
        arr2[i] = arr[m+i+1];
    }

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr[k++] = arr1[i++];

        }
        else if(arr1[i]>arr2[j]){
            arr[k++] = arr2[j++];

        }
        else{
            arr[k++] = arr1[i++];
            arr[k++] =arr2[j++];

        }
    }

    while(i<n1){
        arr[k++] = arr1[i++];
    }

    while(j<n2){
        arr[k++] = arr2[j++];
    }
}

void msort(int *arr,int l,int h ){
    if(l<h){
        int mid = l + (h-l)/2;
        msort(arr,l,mid);
        msort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }

}

int main(){
    int arr[30];
    int n;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    printf("Enter the element: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    msort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}