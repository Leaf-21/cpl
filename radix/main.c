#include <stdio.h>
int trans(int x,int B) {
    if(x>=10) {
        int a=x%10;
        int b=x/10;
        int new_x=B*b+a;
        return new_x;
    }else {
        return x;
    }
}
int compare(int x) {
    int a=x%10;
    int b=x/10;
    return a>b?a:b;
}
int main(void) {
    int p,q,r;
    scanf("%d %d %d",&p,&q,&r);
    int pm=compare(p),qm=compare(q),rm=compare(r);
    int max=pm;
    if(qm>max) {
        max=qm;
    }
    if(rm>max) {
        max=rm;
    }
    for(int B=max+1;B<=40;B++) {
        int new_p=trans(p,B);
        int new_q=trans(q,B);
        int new_r=trans(r,B);
        if(new_p*new_q==new_r) {
            printf("%d",B);
            break;
        }else if(B==40) {
            printf("0");
        }
    }
    return 0;
}
