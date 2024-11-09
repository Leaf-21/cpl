#include <stdio.h>

int main(void) {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    int k=n-1;
    int m=1;
    if(a[n-1]<a[n-2]) {
        for(;k>0;k--,m++) {
            if(a[k-1]<=a[k]) {
                break;
            }
        }
        int tmp=a[k-1];
        for(;k<n;k++) {
            if(a[k]<tmp) {
                k--;
                a[n-m-1]=a[k];
                a[k]=tmp;
                break;
            }
        }
        for(int i=0;i<m/2;i++) {
            int tp=a[n-m+i];
            a[n-m+i]=a[n-1-i];
            a[n-1-i]=tp;
        }
        for(int i=0;i<n;i++) {
            printf("%d",a[i]);
            if(i!=n-1) {
                printf(" ");
            }
        }
    }else {
        int tmp=a[n-1];
        a[n-1]=a[n-2];
        a[n-2]=tmp;
        for(int i=0;i<n;i++) {
            printf("%d",a[i]);
            if(i!=n-1) {
                printf(" ");
            }
        }
    }
    return 0;
}
