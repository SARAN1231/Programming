#include<stdio.h> 
#include<stdlib.h>

struct node  {
    int data;
    struct node *left,*right;
};

struct node* create(int x) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node *root,int x) {

    if(root == NULL) {
        root = create(x);
        return root;
    }
    if(x<root->data){
        root->left = insert(root->left,x);
    }
    else if(x > root->data) {
        root->right = insert(root->right,x);
    }
    return root;
}

struct node* search(struct node *root,int x) {
    
    if(root->data == x || root == NULL) return root;
    if(x < root->data) {
        return search(root->left,x);
    }
    else {
        return search(root->right,x);
    }
    
}
void inorder(struct node *root) {
    if(root == NULL) return ;
  
    inorder(root->left);
      printf("%d ",root->data);
    inorder(root->right);
}

struct node * delete(struct node *root,int x) {
    if(root == NULL) return NULL;
    if(x < root->data) {
        root->left = delete(root->left,x);
    }
    else if(x > root->data) {
        root->right = delete(root->right,x);
    }
    else{
        if(root->right == NULL) return root->left;
        else if(root->left == NULL) return root->right;
        root->data = findmin(root->right);
        root->right = delete(root->right,root->data);
    }
    return root;
}

int findmin(struct node *root) {
    int min = root->data;
    while(root->left != NULL) {
        min = root->left->data;
        root = root->left;
    }
    return min;
}

int ancestor(struct node *root,int x) {
    if(root == NULL) return 0;
    if(root->data==x) return 1;
    if(ancestor(root->left,x) || ancestor(root->right,x)){
        printf("%d ",root->data);
        return 1;
    }
    return 0;
}


int main() {
    struct node *root = NULL;
    int x;
    printf("Enter values to insert into the tree (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &x);
        if (x == -1) break;
        root = insert(root, x);
    }

    printf("\nInorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Enter the node value to find its ancestors: ");
    scanf("%d", &x);
    printf("Ancestors of node %d: ", x);
    if (!ancestor(root, x)) {
        printf("Node %d is not present in the tree", x);
    }
   
    return 0;
}