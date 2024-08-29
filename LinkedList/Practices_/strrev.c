#include<stdio.h>
#include<stdlib.h>

struct node {
    char data;
    struct node *next;
};
struct node *top1 = NULL;

void push(char str[]) {
    for(int i=0;i<strlen(str);i++){
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = str[i];
    newnode->next = top1;
    top1 = newnode;
    }
}

void pop() {
    struct node *temp = top1;
    while(temp  != NULL) {
        printf("%c",temp->data);
        temp = temp->next;
    }
}

int main() {
    char arr[] = "abc";
    push(arr);
    pop();
}
