#include<stdio.h>

void JumpS(int *arr,int n,int key){
    


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
    int key;
    printf("Enter the key to be searched: ");
    scanf("%d",&key);

    JumpS(arr,n,key);
    return 0;
}