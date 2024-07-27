#include<stdio.h>
#define N 5
int stack[N];
int top =-1;

void push(int data) {
    if(top == N-1) {
        printf("Overflow");
    }
    else {
        stack[++top] = data;
    }
}

void pop() {
    if(top == -1) {
        printf("underflow");
    }
    else{
        printf("popped %d",stack[top--]);
    }
    printf("\n");
}

void display() {
    for(int i=top;i>=0;i--) {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main() {
    push(1);
    push(12);
    push(13);
    push(32);
    push(234);
    push(21);
    display();
    pop();
    display();
    pop();
    display();

}