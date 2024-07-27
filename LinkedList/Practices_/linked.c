
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail =  NULL;

struct node* createnewnode() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    return newnode;
}

void create() {
    struct node *newnode = createnewnode();
    if(head == NULL){
        head = tail = newnode;
    }
    else{
        tail->next = newnode;
        tail = newnode;
    }
}

void insertbeg() {
    struct node *newnode = createnewnode();
    newnode->next = head;
    head = newnode;
}

void insertend() {
    struct node *newnode = createnewnode();
    tail->next = newnode;
    tail = newnode;
}

void delbeg() {
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void delend(){
    struct node *temp = head;
    struct node *prev;
    while(temp->next != NULL) {
        prev = temp;
        temp =temp->next;
    }
    struct node *del = prev->next;
    prev->next = NULL;
    tail = prev;
    free(del);
}

void inspos() {
    struct node *temp = head;
    struct node *newnode = createnewnode();
    int i = 1;
    printf("Enter the pos");
    int pos;
    scanf("%d",&pos);
    while(i<pos-1){
        i++;
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void delpos() {
    struct node *temp =head;
    struct node *prev;
    int i = 1;
    int pos;
    printf("Enter the pos to del");
    scanf("%d",&pos);
    while(i<pos) {
        i++;
        prev =  temp;
        temp = temp->next;
    }
    struct node *del = prev->next;
    prev->next = temp->next;
    free(del);
}

void reverse(){
    struct node *nextnode,*prev,*currnode;
    prev = NULL;
    currnode = nextnode = head;
    while(nextnode != NULL) {
        nextnode = currnode->next;
        currnode->next = prev;
        prev = currnode;
        currnode = nextnode;
    }
    head = prev;
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
    display();
    create();
    display();
    create();
    display();
    create();
    display();
    insertbeg();
    display();
    insertbeg();
    display();
    insertend();
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
    display();
    return 0;
}