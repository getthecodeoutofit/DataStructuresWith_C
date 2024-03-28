#include<stdio.h>
#include<math.h>

int JumpS(int *arr,int n,int key){
    int jump = sqrt(n);
    int left=0;

    for(int i=0;i<n;i+=jump){
        if(arr[i]==key){
            return i;
        }
        else if(key < arr[i]){
            for(int j=i-jump;j<i;j++){
                if(arr[j]==key){
                    return j;
                }
            }
            return -1;

        }
    left =i;
    }

    while(left<n){
        if(arr[left]==key){
            return left;
        }
        left++;
    }
    return -1;
    
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

    int flag=JumpS(arr,n,key);
    if(flag>=0){
        printf("found: ");
    }
    return 0;
}