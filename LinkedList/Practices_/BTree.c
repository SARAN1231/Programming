#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node {
    int data;
    struct node *left,*right;
};

struct node* create() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    int x;
    scanf("%d",&x);
    if(x == -1) return NULL;
    newnode->data = x;
    printf("Enter the left child for %d",x);
    newnode->left = create();
    printf("Enter the right child for %d",x);
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

int height(struct node *root) {
    if(root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh>rh)?lh+1:rh+1;
} 
int depthofnode(struct node  *root,int  x) {
    if(root == NULL) return 0;
    int dist = -1;
    if((root->data == x) || (dist = depthofnode(root->left,x)>=0)  || (dist = depthofnode(root->right,x) >=0) ){
        return dist+1;
    }
    return dist;
}

int heights(struct node *root,int x) {
    int h = -1;
    heightutil(root,x,&h);
    return h;
}

int heightutil(struct node *root,int x,int* h) {
    if(root == NULL) return -1;

    int ans;
    int lh = heightutil(root->left,x,h);
    int rh = heightutil(root->right,x,h);
    if(lh>rh) {
        ans = lh+1;
    }
    else ans = rh+1;
    if(root->data == x) *h = ans;
    return ans;
}


bool search(struct node *root,int x) {
    if(root == NULL) return false;
    if(root->data == x) return true;
    bool a = search(root->left,x);
    if(a) return true;
    bool b = search(root->right,x);
    return b;
}
int level(struct node *root,int x) {
    return levelofnode(root,x,1);
}

int levelofnode(struct node *root,int x,int level) {
    if(root == NULL) return 0;
    if(root->data == x) return level;
   int dl = levelofnode(root->left,x,level+1);
   if(dl!=0) return dl;
    dl = levelofnode(root->right,x,level+1);
    return dl;
}

void parent(struct node *root,int x,int parentd) {
    if(root == NULL) return ;
    if(root->data == x) printf("\n parent = %d",parentd);
    parent(root->left,x,root->data);
    parent(root->right,x,root->data);
   
}
void mirror(struct node* root) {
    if(root == NULL) return;
    mirror(root->left);
    mirror(root->right);
    struct node *temp = root->left;
    root->left = root->right;
    root->right = temp;
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
    printf("\nHeight = %d",height(root));
    printf("\n depth of node = %d",depthofnode(root,25));
    printf("\n height of node = %d",heights(root,25));
    printf("\n %s",(search(root,25) ? "found":"not found"));
    printf("\n level of node %d",level(root,25));
    parent(root,25,-1);
    printf("\n");

    mirror(root);
    printf("\n mirror : ");
    inorder(root);
}