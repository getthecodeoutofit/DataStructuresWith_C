#include <stdlib.h>
#include <stdio.h>

int front = -1,rear = -1;

void push(int size,int *q){
int item;
printf("Enter the item: ");
scanf("%d",&item);
if(front == -1){
  front = 0;
  rear = 0;
  q[rear] = item;
}
else if(rear != size-1){
  rear ++;
  q[rear] = item;
}
else{
  printf("Size exceeds: ");
  return;
}
}


void pop(int size,int *q){
  if (front == -1){
    printf("The Queues is empty:\n");
    return;
  }
  else{
    if (front == rear){
      front = rear = -1;
    }
    else {
      front++;
    }

  }

}
void display(int *q){
  int start = front ;
  int end = rear;
  while(start != end){
    printf("%d\n",q[start++]);
  }
  printf("%d\n",q[start]);
}


int main(){
  int n;
  printf("Enter the size of Queue: ");
  scanf("%d",&n);
  int arr[n];
  int choice;

  while(1){
    printf("\nEnter the choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1:push(n,arr);
        break;
        case 2:pop(n,arr);
          break;
          case 3:display(arr);
            break;
    }
  }

}