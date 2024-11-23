#include <stdio.h>
#include <stdbool.h>
#include <string.h>
char a[1000000];
int top=-1;
bool is_empty(void) {
    return top==-1;
}
void push(char m) {
    top++;
    a[top]=m;
}
void pop(void) {
    if(is_empty()) {
        printf("False\n");
    }else {
        top--;
    }
}
char first() {
    return a[top];
}
int main(void){
    int T;
    scanf("%d",&T);
    char str[1000000]={};
    for(int i=0;i<T;i++) {
        scanf("%s",&str);
        unsigned int len=strlen(str);
        for(int j=0;j<len;j++) {
            if(str[j]=='('||str[j]=='['||str[j]=='{') {
                push(str[j]);
            }else if(str[j]==')') {
                if(first()=='(') {
                    pop();
                }else {
                    printf("False\n");
                    top=0;
                    break;
                }
            }else if(str[j]==']') {
                if(first()=='[') {
                    pop();
                }else {
                    printf("False\n");
                    top=0;
                    break;
                }
            }else if(str[j]=='}') {
                if(first()=='{') {
                    pop();
                }else {
                    printf("False\n");
                    top=0;
                    break;
                }
            }
        }
        if(top==-1) {
            printf("True\n");
        }
        top=-1;
    }
    return 0;
}
