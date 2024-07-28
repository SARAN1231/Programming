#include<stdio.h>

int main() {
    int arr[5];
    for(int i=0;i<5;i++) {
        scanf("%d",&arr[i]);
    }

    printf("found in %d",lsearch(arr,3));

}
 int lsearch(int arr[],int n) {
        for(int i=0;i<5;i++) {
            if(arr[i] == n) {
               return i;
            }
        }
        return -1;
    }