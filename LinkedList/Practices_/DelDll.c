#include<stdlib.h>
#include<stdio.h>

struct node {
    int data;
    struct node *prev,*next;
};
struct node *head = NULL;
struct node *tail = NULL;
struct node* createnode() {
    struct node *newnode =(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next = newnode->prev = NULL;
    return newnode;
}

void create() {
    struct node *newnode = createnode();
    if(head == NULL) {
        head = tail = newnode;
    }
    else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void display() {
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void del(int x) {
    struct node *temp = head;
    while(temp != NULL) {
        if(temp->data == x)break;
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
}
int main() {
    create();
    display();
    create();
    display();
    create();
    display();
    create();
    display();
    del(3);
    display();
}