#include <stdio.h>
#define N 5
int q[N];
int front = -1;
int rear = -1;

void enqueue(int n) {
    if ((rear + 1) % N == front) {
        printf("Overflow\n");
    } else if (rear == -1 && front == -1) {
        front = rear = 0;
        q[rear] = n;
    } else {
        rear = (rear + 1) % N;
        q[rear] = n;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Empty\n");
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % N;
    }
}

void display() {
    if (front == -1) {
        printf("Empty\n");
        return;
    }
    int i = front;
    while (i != rear) {
        printf("%d ", q[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", q[rear]);
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    display();
    enqueue(6);
    display();
    dequeue();
    display();
    return 0;
}
