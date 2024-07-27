#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;

struct node* createnode() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
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

void insbeg() {
    struct node *newnode = createnode();
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insend() {
    struct node *newnode = createnode();
    
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void delbeg() {
    struct node *del = head;
    head = head->next;
    free(del);
}

void delend() {
    struct node *temp = tail;
    tail->prev->next = NULL;
    tail = tail->prev;
    free(temp);
}

void inspos() {
    struct node *newnode = createnode();
    struct node *temp = head;
    int i= 1;
    int pos;
    printf("enter the pos to add");
    scanf("%d",&pos);
    while(i<pos-1){
        i++;
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

void delpos() {
    struct node *del;
    struct node *temp = head;
    int i=1;
    int pos;
    printf("Enter the pos to del");
    scanf("%d",&pos);
    while(i<pos){
        i++;
        temp = temp->next;
    }
    del = temp;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(del);
}

void display() { 
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse() {
    struct node *currnode = head;
    struct node *nextnode;
    while(currnode != NULL) {
        nextnode = currnode->next;
        currnode->next = currnode->prev;
        currnode->prev = nextnode;
        currnode = nextnode;
    }
    currnode = head;
    head = tail;
    tail = currnode;
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
    insbeg();
    display();
    insend();
    display();
    delbeg();
    display();
    delend();
    display();
    inspos();
    display();
    delpos();
    display();
    reverse();
    // display();
}