#include<stdio.h> 

int main() {
    char str[5];
    scanf("%s",&str);
    int l = strlen(str);
    for(int i=0;i<l/2;i++) {
        char temp = str[i];
        str[i] = str[l-1-i];
        str[l-1-i] = temp;
    }
    printf("%s \n",str);
}