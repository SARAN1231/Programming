#include<stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
} *head,*tail,*newnode,*temp;

void create()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head == NULL) {
        head = tail= newnode;
    }
    else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    tail->next = head;
    head->prev = tail;
}

void display() {
    temp = head;
    while(temp->next != head){
        printf("%d ",temp->data);
        temp = temp->next;
    }
     printf("%d ",temp->data);
}
void insbeg(){
     newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->prev = tail;
    newnode->next = head;
    head->prev = newnode;
    head= newnode;
    tail->next = head;
}
void insend(){
      newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    tail->next = head;
}

void delbeg(){
    head->next->prev = tail;
    head = head->next;
    tail->next = head;
    printf("\n");
}
void delend(){
    tail->prev->next = head;
    tail = tail->prev;
    tail->next = head;
    printf("\n");
}
void delpos(){
    int pos,i=1;
    temp = head;
    scanf("%d",&pos);
    while(i<pos){
        temp=temp->next;
        i++;
    }
    struct node * rem = temp;
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(rem);
}

int main()
{
  head = NULL;
  create();
  create();
  create();
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
  delpos();
  display();
    return 0;
}
