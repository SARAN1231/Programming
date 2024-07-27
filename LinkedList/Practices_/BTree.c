#include<stdio.h>
#include<stdlib.h>

struct node  {
    int data;
    struct node *left,*right;
};

struct node * create() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    int x;
    scanf("%d",&x);
    if(x == -1) return NULL;
    newnode->data = x;
    printf("Enter the left child of %d",x);
    newnode->left = create();
    printf("Enter the right child of %d",x);
    newnode->right = create();
    return newnode;
}

void preorder(struct node *root) {
    if(root == NULL) return ;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root) {
    if(root == NULL) return ;
    preorder(root->left);
    preorder(root->right);
    printf("%d ",root->data);
}

void inorder(struct node *root) {
    if(root == NULL) return ;
    preorder(root->left);
    printf("%d ",root->data);
    preorder(root->right);

}

int main() {
    struct node *root;
    root = create();
    printf("\n preorder = ");
    preorder(root);
    printf("\n postorder = ");
    postorder(root);
    printf("\n inorder = ");
    inorder(root);
}