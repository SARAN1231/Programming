#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail =  NULL;

struct node* createnode() {
    struct node *newnode ;
    newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    return newnode;
}

void create() {
    struct node *newnode = createnode();
    if(head == NULL) {
        head =tail= newnode;
        
    }
    else{
        tail->next = newnode;
        tail = newnode;
    }
    tail->next = head;
}

void insbeg() {
    struct node *newnode = createnode();
    newnode->next = head;
    head = newnode;
    tail->next = head;
}

void insend() {
    struct node *newnode = createnode();
    struct node *temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;

}

void delbeg() {
    struct node *del = head;
    struct node *temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    head = head->next;
    temp->next = head;
    free(del);
}

void delend() {
    struct node *del;
    struct node *prev;
    struct node *temp = head;
    while(temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    del=temp;
    free(del);
}
void display() {
    struct node *temp = head;
    while(temp->next != head){
        printf("%d " ,temp->data);
        temp = temp->next;
    }
    
    printf("%d" ,temp->data);
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
    insbeg();
    display();
    insend();
    display();
    delbeg();
    display();
    delend();
    display();
}