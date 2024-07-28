#include<stdio.h>
#include<stdlib.h>

struct queue {
    int data;
    struct queue* next;
};
struct queue* front1 = NULL;
struct queue* rear1 = NULL;
struct queue* front2 = NULL;
struct queue* rear2 = NULL;

void push() {
    int n;
    scanf("%d",&n);
    struct queue *newnode = (struct queue*)malloc(sizeof(struct queue));
    newnode->data = n;
    if(front1 == NULL && rear1 == NULL) {
        front1 =rear1 = newnode;
    }
    else{
        rear1->next = newnode;
        rear1 = newnode;
    }
}

void pop() {
    if(front1 == NULL) printf("empty");
    struct queue* temp = front1;
    struct queue* prev;
    while(temp->next != NULL) {
        prev = temp;
        temp =temp->next;
    }
    if(prev == NULL) {
        printf("%d poppped",temp->data);
    }
    else{
        while(front1 != NULL && front1 != temp) {
        struct queue *newnode = (struct queue*)malloc(sizeof(struct queue));
        newnode->data = front1->data;
        if(front2 == NULL && rear2 == NULL) {
           front2 =rear2 = newnode;
        }
        else{
            rear2->next = newnode;
            rear2 = newnode;
         }
         front1 = front1->next;
        }
        printf("%d popped",temp->data);
        front1 = rear1 = NULL;
        struct queue* temp_front = front1;
        struct queue* temp_rear = rear1;
        front1 = front2;
        rear1 = rear2;
        front2 = temp_front;
        rear2 = temp_rear; 
    }
}

void display(){
    struct queue* temp = front1;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
  push(2);
push(3);
display();
pop();
display();
push(4);
display();
pop();
display();
}