#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n,m,d;
    scanf("%d %d %d",&n,&m,&d);
    int a[n+2*d][m+2*d];
    for(int i=0;i<n+2*d;i++) {
        for(int j=0;j<m+2*d;j++) {
            a[i][j]=0;
        }
    }
    int value[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            value[i][j]=0;
        }
    }
    int max=-10000000;
    int axis[100000][2];
    int k=0;
    int cnt=0;
    for(int i=d;i<n+d;i++) {
        for(int j=d;j<m+d;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=d;i<n+d;i++) {
        for(int j=d;j<m+d;j++) {
            for(int p=0;p<=d;p++) {
                for(int q=d-p;q>=0;q--) {
                    value[i-d][j-d]+=a[i+p][j+q]+a[i-p][j+q]+a[i+p][j-q]+a[i-p][j-q];
                }
            }
            for(int p=1;p<=d;p++) {
                value[i-d][j-d]=value[i-d][j-d]-a[i+p][j]-a[i-p][j]-a[i][j+p]-a[i][j-p];
            }
            value[i-d][j-d]-=3*a[i][j];
            if(value[i-d][j-d]>=max) {
                max=value[i-d][j-d];
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(value[i][j]==max) {
                axis[k][0]=i+1;
                axis[k][1]=j+1;
                cnt++;
                k++;
            }
        }
    }
    printf("%d %d\n",max,cnt);
    for(int i=0;i<k;i++) {
        printf("%d %d\n",axis[i][0],axis[i][1]);
    }
    return 0;
}
