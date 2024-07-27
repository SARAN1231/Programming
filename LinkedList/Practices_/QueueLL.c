#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue() {
    struct node *newnode  = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);

    if(front == NULL) {
        front = rear = newnode;
    }
    else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    struct node *temp = front;
    printf("%d dequeued",front->data);
    front = front->next;
    free(temp);
    printf("\n");
}

void display() {
    struct node *temp =front;
    while( temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
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