#include<stdio.h>

int main(){
    int array[20][20];
    int **arr = array;
    arr[0][0] = 10;

    printf("%d",**arr);




    return 0;
}