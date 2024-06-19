#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
} *head, *newnode, *temp;

void create() {
    newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = temp = newnode;
    }
    else {
        temp->next = newnode;
        temp = newnode;
    }
}

void display(){
    temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void insbeg(){
    newnode = (struct node*)malloc(sizeof(struct node));
    scanf("\n%d", &newnode->data);
        newnode->next = head;
        head = newnode;

}
void insend() {
     newnode = (struct node*)malloc(sizeof(struct node));
    scanf("\n%d", &newnode->data);
   
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    
}

void inspos(){
    int i =1,pos;
    printf("\npos");
    scanf("%d\n",&pos);
    newnode = (struct node*)malloc(sizeof(struct node));
    scanf("\n%d", &newnode->data);
  
    temp = head;
    while(i<pos-1){
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    
}
void delbeg(){
   struct node *rem;
    rem =head;
    head = head->next;
    free(rem);
    printf("\n");
}
void delend(){
    struct node* prev;
    temp = head;
    while(temp->next!= NULL){
        prev = temp;
        temp=temp->next;
    }
    prev->next= NULL;
       printf("\n");
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
    free(temp);
}
int main() {
    head = NULL;
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
    return 0;
}
