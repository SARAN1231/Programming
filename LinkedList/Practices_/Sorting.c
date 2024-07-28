#include<stdio.h>

int main() {
    int arr[5];
    for(int i=0;i<5;i++) {
        scanf("%d",&arr[i]);
    }

    Bubble(arr,5);
    
    for(int j=0;j<5;j++) {
        printf("%d ",arr[j]);
    }
    printf("\ninsertion = ");
    insertion(arr,5);
    for(int j=0;j<5;j++) {
        printf("%d ",arr[j]);
    }
    printf("\nselection = ");
    selection(arr,5);
    for(int j=0;j<5;j++) {
        printf("%d ",arr[j]);
    }
}

void Bubble(int arr[] ,int n) {
    for(int i=0;i<n-1;i++) {
        int flag =0;
        for(int j=0;j<n-1-i;j++) {
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag =1;
            }
        }
        if(flag == 0) break;
    }
}

void insertion(int arr[],int n){
    for(int i=1;i<n-1;i++) {
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void selection(int arr[],int n) {
    for(int i=0;i<n-1;i++) {
        int min = i;
        for(int j =i+1;j<n;j++) {
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min !=i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
