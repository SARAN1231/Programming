#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;

void push() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next = top;
    top = newnode;
}

void pop() {
    struct node *del = top;
    printf("%d popped",del->data);
    top = top->next;
    free(del);
    printf("\n");
}

void display() {
    struct node *temp = top;
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push();
    push();
    push();
    push();
    push();
    push();
    display();
    pop();
    display();
    pop();
    display();
}