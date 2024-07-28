#include<stdio.h>
#include<stdlib.h>

struct Node {
    int  data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int x){
    struct Node* newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = x;
    return newnode;
}

struct Node* create(){
    struct Node* newnode;
    int x;
    scanf("%d",&x);
    if(x==-1) return 0;
    newnode = createNode(x);
    printf("Enter the left Node of %d ",x);
    newnode->left = create();
    printf(" Enter the right Node of %d ",x);
    newnode->right = create();
    return newnode;
}

void inorder(struct Node* root){
    if(root == NULL) return;
    
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void mirrortree(struct Node* root) {
    if(root == NULL) return ;
    mirrortree(root->left);
    mirrortree(root->right);
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
}

int main(){
    struct Node* root;
    root = create();
    inorder(root);
    printf("\n");
    mirrortree(root);
     inorder(root);
}