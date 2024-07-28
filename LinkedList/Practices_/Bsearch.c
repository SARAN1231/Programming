#include<stdio.h>

int main() {
    int arr[5];
    for(int i=0;i<5;i++) {
        scanf("%d",&arr[i]);
    }

    printf("found in %d",Bsearch(arr,3));

}

int Bsearch(int arr[],int n) {
    int l =0;
    int r = 4;

    while(l<=r) {
        int mid = (l+r)/2;
        if(arr[mid] == n) return mid;
        else if( n < arr[mid])
        r = mid-1;
    else l = mid+1;
    
    }
    return -1;
}