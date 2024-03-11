#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[400];
    printf("Enter the data in the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the key: ");
    scanf("%d", &key);
    for(int i=0; i<n; i++){
        if(arr[i] == key){
            printf("%d is present at index %d\n", key, i);
        }
    }

    return 0;
}