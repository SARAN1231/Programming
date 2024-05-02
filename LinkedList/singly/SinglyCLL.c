#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
} *head,*newnode,*temp;

void create() {
    newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    if(head == NULL){
        head = temp = newnode;
    }
    else{
        temp->next = newnode;
        temp = newnode;
    }
    temp->next = head;
}

void display(){
    temp = head;
    while(temp->next != head){
        
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d \n",temp->data);
}
void insbeg() {
    newnode = (struct node*)malloc(sizeof(struct node));
     scanf("%d",&newnode->data);
     newnode->next = head;
     temp=head;
     while(temp->next != head){
         temp = temp->next;
     }
     temp->next = newnode;
     head = newnode;
}

void insend() {
      newnode = (struct node*)malloc(sizeof(struct node));
     scanf("%d",&newnode->data);
     temp=head;
     while(temp->next != head){
         temp = temp->next;
     }
     newnode->next = temp->next;
     temp->next = newnode;
}
void inspos(){
    int pos,i=1;
       newnode = (struct node*)malloc(sizeof(struct node));
     scanf("%d",&newnode->data);
    scanf("%d",&pos);
    temp=head;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
  
    
}
void delbeg(){
    struct node* curr;
    temp =curr= head;
      while(temp->next != head){
         temp = temp->next;
     }
    head = head->next;
    temp->next = head;
    free(curr);
    
}
void delend(){
     struct node* prev,*curr;
    temp = head;
      while(temp->next != head){
          prev = temp;
         temp = temp->next;
     }
     curr = temp;
     prev->next = head;
     free(curr);
     
}
void delpos(){
    struct node* prev;
    temp = head;
    int pos,i=1;
    scanf("%d",&pos);
    while(i<pos){
        prev = temp;
        temp=temp->next;
        i++;
    }
    prev->next = temp->next;
}
int main(){
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
    inspos();
    display();
    delbeg();
    display();
    delend();
    display();
    delpos();
    display();
}
