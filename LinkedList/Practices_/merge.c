#include<stdio.h>

void sort(int arr[],int size) {
    mergesort(arr,0,size-1);
}

void mergesort(int arr[],int low, int high){
    if(low<high) {
        int mid = low +(high - low) /2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void merge(int arr[],int low , int mid,int high) {
    int n1 = mid - low +1;
    int n2 = high -mid;
    int lrr[n1];
    int rrr[n2];

    for(int x=0;x<n1;x++){
        lrr[x] = arr[low+x];
    }

    for(int y=0;y<n2;y++) {
        rrr[y] = arr[mid+1+y];
    }

    int i=0,j=0,k=low;
    while(i<n1 && j<n2) {
        if(lrr[i] <= rrr[j]){
            arr[k] = lrr[i];
            i++;
        }
        else{
            arr[k] = rrr[j];
            j++;
        }
        k++;
    }

    while(i<n1) {
        arr[k] = lrr[i];
        i++;
        k++;
    }

    while(j<n2) {
        arr[k] = rrr[j];
        j++;
        k++;
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,n);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}