#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left,*right;
};

struct node * createnode(int x) {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node * insert(struct node *root,int x) {
    if(root == NULL) {
        root = createnode(x);
        return root;
    }
    if(x<root->data) {
        root->left = insert(root->left,x);
    }
    else {
        root->right = insert(root->right,x);
    }
    return root;
}

void inorder(struct node *root) {
    if(root == NULL) return ;
 
    inorder(root->left);
       printf("%d ",root->data);
    inorder(root->right);
}

int main() {
    struct node *root = NULL;
    int n;
    printf("Enter values to insert into the BST (enter -1 to stop):\n");
    while(1){
        scanf("%d",&n);
        if(n == -1) break;
        root = insert(root,n);
    }
    printf("Preorder = ");
    inorder(root);
}