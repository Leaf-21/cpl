#include <stdio.h>
char str[10000][10000];
int jiance(int i,int j,int max) {
    int cnt=0;
    for(int k=1;k<=max;k++) {
        if(k==1) {
            if(str[i+1][j]=='\\'&&str[i+1][j+1]=='/') {
                cnt++;
            }
        }else {
            int correct=1;
            for(int l=0;l<k;l++) {
                if(str[i+l][j-l]=='/'&&str[i+l][j+1+l]=='\\') {
                }else {
                    correct=0;
                    break;
                }
            }
            for(int l=0;l<k;l++) {
                if(str[i+2*k-1-l][j-l]=='\\'&&str[i+2*k-1-l][j+l+1]=='/') {
                }else {
                    correct=0;
                    break;
                }
            }
            if(correct==1) {
                cnt++;
            }
        }
    }
    return cnt;
}
int main(void) {
    int R,C;
    scanf("%d %d",&R,&C);
    int count=0;
    for(int i=0;i<R;i++) {
        scanf("%s",&str[i]);
    }
    for(int i=0;i<R-1;i++) {
        for(int j=0;j<C-1;j++) {
            if(str[i][j]=='/'&&str[i][j+1]=='\\') {
                int max=j+1;
                if(C-j-1<max) {
                    max=C-1-j;
                }else if((R-i)/2<max) {
                    max=(R-i)/2;
                }
                count+=jiance(i,j,max);
            }
        }
    }
    printf("%d",count);
    return 0;
}
