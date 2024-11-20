#include <stdio.h>

int main(void) {
    int n,L;
    scanf("%d %d",&n,&L);
    int v[n],w[n];
    int shunxu[10000];
    for(int i=0;i<10000;i++) {
        shunxu[i]=-1;
    }
    for(int i=0;i<n;i++) {
        scanf("%d",&v[i]);
    }
    for(int i=0;i<n;i++) {
        scanf("%d",&w[i]);
    }
    for(int i=0;i<n;i++) {
        for(int j=1;j<n-i;j++) {
            if(v[j-1]>v[j]) {
                int tmp=v[j];
                v[j]=v[j-1];
                v[j-1]=tmp;
                int temp=w[j];
                w[j]=w[j-1];
                w[j-1]=temp;
            }
        }
    }
    int sum=0;
    int k=n-1;
    int x=0;
    for(;sum<L;k--) {
        sum+=w[k];
        if(sum+w[k-1]>=L) {
            x=L-sum;
            sum+=w[k-1];
        }
    }
    int value=0;
    for(int i=n-1;i>=k+1;i--) {
        value+=w[i]*v[i];
    }
    value+=x*v[k];
    printf("%d",value);
    return 0;
}
