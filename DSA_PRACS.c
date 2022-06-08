#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int top = -1;
char stack[100][100];

void push(char str[], int length){
    top++;
    for(int i=0;i<length;i++){
        stack[top][i]=str[i];
    }
}

void pop(){
    top--;
}

int main(){
    int n,length=0,k;
    printf("Enter the total number of words in the string: ");
    scanf("%d",&n);
    char str[100];
    printf("Enter the string: ");
    for(int i=0;i<n;i++){
        length=0;
        scanf("%s",&str);
        for(int j=0;str[j]!='\0';j++){
            length++;
        }
        push(str,length);
    }
    printf("Enter k: ");
    scanf("%d",&k);
    for (int i = 0; i < k-1; i++)
    {
        pop();
    }
    for (int i = 0; stack[top][i] != '\0'; i++)
    {
        printf("%c", stack[top][i]);
    }
    
    
    return 0;
}