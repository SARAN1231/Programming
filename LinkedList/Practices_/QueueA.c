#include<stdio.h>
#define N 5
int q[N];
int front = -1;
int rear = -1;

void enqueue() {
    int n;
    scanf("%d",&n);
    if(rear == N-1) {
        printf("Overflow");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        q[front] = n;
    }
    else{
        q[++rear] = n;
    }
}

void dequeue() {
    if(front ==-1) {
        printf("underflow");
    }
    else if(front == rear) {
        front = rear =-1;
    }
    else{
        printf("%d dequeued",q[front++]);
    }
    printf("\n");
}

void display() {
    for(int i=front;i<=rear;i++) {
        printf("%d ",q[i]);
    }
     printf("\n");
}

int main() {
    enqueue();
     enqueue();
      enqueue();
       enqueue();
        enqueue();
        display();
        dequeue();
        display();
}