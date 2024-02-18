#include<stdio.h>

int main(){
int l1,l2,i,j,k;
printf("Enter the size of the array 1: ");
scanf("%d",&l1);
printf("Enter the size of the array 2: ");
scanf("%d",&l2);
int arr1[l1],arr2[l2],arr3[l1+l2];
printf("enter the elements in array 1: ");
for(i=0;i<l1;i++){
scanf("%d",&arr1[i]);
}
printf("enter the elements in array 2: ");
for(i=0;i<l2;i++){
scanf("%d",&arr2[i]);
}

printf("sorting the array........");
for(i=0;i<l1;i++){
    for(j=0;j<l1-i-1;j++){
        if(arr1[j]>arr1[j+1]){
            int temp = arr1[j];
            arr1[j]=arr1[j+1];
            arr1[j+1]=temp;
        }
    }
}
for(i=0;i<l2;i++){
    for(j=0;j<l2-i-1;j++){
        if(arr2[j]>arr2[j+1]){
            int temp = arr2[j];
            arr2[j]=arr2[j+1];
            arr2[j+1]=temp;
        }
    }
}
printf("Merging the sorted array......");
i=0;j=0;k=0;
while(k<(l1+l2)){

if((i<l1)&&(j<l2)){

if(arr1[i]<arr2[j]){
    arr3[k++]=arr1[i++];
}
else if(arr1[i]>arr2[j]){
    arr3[k++]=arr2[j++];
}
else if (arr1[i]==arr2[j]){
    arr3[k++]=arr1[i++];
    arr3[k++]=arr2[j++];
}
}

else if(i<l1){
    arr3[k++]=arr1[i++];
}
else {
    arr3[k++]=arr2[j++];
}
}

printf("\n%d\n",k);
printf("the merged array is: ");
for(i = 0;i<k;i++){
    printf("%d ",arr3[i]);
}

return 0;
}