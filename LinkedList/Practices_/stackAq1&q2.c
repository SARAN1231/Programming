#include<stdio.h>
#define N 5
int q1[N];
int q2[N];

int front1 = -1;
int rear1 = -1;
int front2 = -1;
int rear2 = -1;

void push() {
    int n;
    scanf("%d",&n);
    if(rear1 == N-1) printf("Overflow");
    else if(front1 == -1 && rear1 == -1){
        front1 = rear1 =0;
        q1[front1] = n;
    }
    else {
        q1[++rear1] = n;
    }
}

void pop() {
    if(front1 == -1 && rear1 == -1){
        printf("empty");
    }
    else {
        while(front1 != rear1) {
            q2[++rear2] = q1[front1++];
        }
        printf("%d popped",q1[front1]);
        front1 = rear1 =-1;
        while(rear2 != -1){
            if(front1 == -1 && rear1 == -1) {
                front1 = rear1 =0;
                q1[front1] = q2[front2++];
            }
            else{
                q1[++rear1] = q2[front2++];
            }
            if(front2 > rear2) {
                front2 = rear2 = -1;
            }
        }
    }
}

void display() {
    if (front1 == -1) {
        printf("Empty\n");
    } else {
        for (int i = front1; i <= rear1; i++) {
            printf("%d ", q1[i]);
        }
        printf("\n");
    }
}

int main() 
{
    push();
    push();
    push();
    display();
    pop();
    display();
}