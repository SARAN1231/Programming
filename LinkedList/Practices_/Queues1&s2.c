#include<stdio.h>
#define N 5
int s1[N];
int s2[N];

int top1 =-1;
int top2 = -1;

void push() {
    int n;
    scanf("%d",&n);
    if(top1 == N-1) printf("Over flow");
    else {
        s1[++top1] = n;
    }
}

void pop() {
    if(top1 == -1 && top2 ==-1) printf("Empty");

    if(top2 == -1) {
        for(int i=top1;i>=0;i--) {
            s2[++top2] = s1[i];
        }
    }
    printf("%d popped",s2[top2]);
    top2--;
    printf("\n");
}

void display() {
    for(int i=0;i<=top1;i++) {
        printf("%d ",s1[i]);
    }
    printf("\n");
}

void display2(){
    for(int i=top2;i>=0;i--) {
        printf("%d ",s2[i]);
    }
    printf("\n");
}

int main() {
    push();push();push();
    display();
    pop();
    display2();
     pop();
    display2();
     pop();
    display2();
    push();
    display();
    pop();
    display2();
    push();
    display();
}