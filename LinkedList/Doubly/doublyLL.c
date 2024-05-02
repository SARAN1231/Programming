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
}

void display() {
    temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void insbeg(){
     newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->prev = NULL;
    newnode->next = head;
    head->prev = newnode;
    head= newnode;
}
void insend(){
      newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void delbeg(){
    head->next->prev = NULL;
    head = head->next;
    printf("\n");
}
void delend(){
    tail->prev->next = NULL;
    tail = tail->prev;
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
