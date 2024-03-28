#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void inserthead(vector<int> &arr,int val){

    arr.push_back(val);
    int index = arr.size();
    int par = (index-1)/2;
    while(index>0){
    if(arr[par] < val){
        swap(arr[par],arr[index]);
        index = par;
    }

    else{
        return;
    }
    }
}

void display(vector<int> &arr){

}

void deleteheap(vector<int> &arr){
    
}

int main(){

    vector<int>arr;
    int n;
int choice;
cout << "Enter your choice: ";
cin >> choice;
while(true){
switch(choice){
    case 1:
    int temp;
    cin >>temp;
    inserthead(arr,temp);
    break;
    case 2:display(arr);
    break;
    case 3:
    break;
    case 4:
    break;
    case 5:
    break;
    default:
    break;
}
}
    return 0;
}