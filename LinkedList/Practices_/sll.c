#include<stdio.h> 

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void create() {
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next = NULL;

    if(head == NULL) {
        head = tail= newnode;
    }
    else {
        tail->next = newnode;
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

int main() {
    create();
    create();
    create();
    create();
    create();
    display();
}