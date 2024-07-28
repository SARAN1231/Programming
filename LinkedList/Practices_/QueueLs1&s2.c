#include<stdio.h>
#include<stdlib.h>

struct stack {
    int data;
    struct stack *next;
};
struct stack *top1 = NULL;
struct stack *top2 = NULL;

void enqueue() {
    int n;
    scanf("%d",&n);
        struct stack * newnode;
        newnode = (struct stack*)malloc(sizeof(struct stack));
        newnode->data = n;
        newnode->next = top1;
        top1 = newnode;
}

void dequeue() {
    if(top1 == NULL && top2 == NULL) printf("Empty");
    if(top2 == NULL) {
       
        while(top1 != NULL) {
            struct stack * newnode;
            newnode = (struct stack*)malloc(sizeof(struct stack));
            newnode->data = top1->data;
            newnode->next = top2;
            top2 = newnode;
            top1 = top1->next;
        }
    }

    printf("%d dequeued \n",top2->data);
    struct stack *del = top2;
    top2 = top2->next;
    free(del);
}

void display() {
    struct stack* temp = top1;
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp =temp->next;
    }
    printf("\n");
}

void display2(){
    struct stack* temp = top2;
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp =temp->next;
    }
    printf("\n");
}

int main() {
    enqueue();
    enqueue();
    enqueue();
    display();
    dequeue();
    display2();
}