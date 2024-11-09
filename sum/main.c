#include <stdio.h>

int main(void)
{
    int n,t;
    int tmp=0,sum=0;;
    scanf("%d %d",&n,&t);
    for(int i=0;i<n;i++) {
        tmp=tmp*10+t;
        sum+=tmp;
    }
    printf("%d",sum);
    return 0;
}
