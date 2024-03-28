#include<stdio.h>
#include<stdlib.h>
int piv(int *arr,int l,int h){

}
void select(int *arr,int l,int h,int k){

}

int main(){
    int num;
    printf("Enter the size of arr: ");
    scanf("%d",&num);
    int *arr = calloc(num,sizeof(int));
    printf("Enter the element: ");
    for(int i=0;i<num;i++){
        scanf("%d ",&arr[i]);
    }
    printf("Enter the Kth location for large element: ");
    int k;
    scanf("%d",&k);
    select(arr,0,num-1,k);
    return 0;
}