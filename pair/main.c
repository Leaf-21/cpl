#include <stdio.h>

int main(void) {
    int n,m,t;
    scanf("%d %d %d",&n,&m,&t);
    int a[n];
    int b[m];
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++) {
        scanf("%d",&b[i]);
    }
    int min,j0,i0;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(t>=a[j]+b[i]) {
                min=t-a[j]-b[i];
                j0=j;
                i0=i;
                goto new;
            }
            if(i==m-1&&j==n-1) {
                printf("-1");
                return 0;
            }
        }
    }
    new:{
        for(int i=i0;i<m;i++) {
            for(int j=j0;j<n;j++) {
                if(t>=a[j]+b[i]) {
                    int tmp=t-a[j]-b[i];
                    if(min>tmp) {
                        min=tmp;
                    }
                }
            }
        }
        printf("%d",min);
    }
    return 0;
}
