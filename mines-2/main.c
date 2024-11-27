#include <stdio.h>

int main(void){
    int n;
    scanf("%d\n",&n);
    char a[n+2][n+2][n+2];
    for(int i=1;i<n+1;i++) {
        for(int j=1;j<n+1;j++) {
            for(int k=1;k<n+1;k++) {
                a[i][j][k]='0';
            }
        }
    }
    int x,y,z;
    int tmp=0;
    long long int wrong_axis[10000][3];
    for(int i=1;i<n+1;i++) {
        for(int j=1;j<n+1;j++) {
            for(int k=1;k<n+1;k++) {
                scanf("%c",&a[i][j][k]);
                if(a[i][j][k]=='?') {
                    x=i;
                    y=j;
                    z=k;
                }
            }
        }
    }
    int cor0=1;
    int cor1=1;
    char str0='0',str1='0';
    for(int i=1;i<n+1;i++) {
        for(int j=1;j<n+1;j++) {
            for(int k=1;k<n+1;k++) {
                if(a[i][j][k]!='*'&&a[i][j][k]!='?') {
                    int count0=0,count1=0;;
                    int vectors[][3] = {{0,0,1}, {0,0,-1}, {0,1,0}, {0,-1,0},{1,0,0},{-1,0,0}};
                    for(int l=0;l<6;l++) {
                        int newI=i+vectors[l][0];
                        int newJ=j+vectors[l][1];
                        int newK=k+vectors[l][2];
                        if(a[newI][newJ][newK]=='*') {
                            count0 ++;
                        }
                        if(a[newI][newJ][newK]=='*'||a[newI][newJ][newK]=='?') {
                            count1++;
                        }
                    }
                    str0+=count0;
                    str1+=count1;
                    if(str0!=a[i][j][k]){
                        cor0=0;
                    }
                    if(str1!=a[i][j][k]) {
                        cor1=0;
                    }
                    if(a[i][j][k]!=str1){
                        wrong_axis[tmp][0]=i;
                        wrong_axis[tmp][1]=j;
                        wrong_axis[tmp][2]=k;
                        tmp++;
                    }
                }
                str0='0';
                str1='0';
            }
        }
    }
    if(cor0==1) {
        printf("valid\n");
        int count=0;
        int vectors[][3] = {{0,0,1}, {0,0,-1}, {0,1,0}, {0,-1,0},{1,0,0},{-1,0,0}};
        for(int l=0;l<6;l++) {
            int newI=x+vectors[l][0];
            int newJ=y+vectors[l][1];
            int newK=z+vectors[l][2];
            if(a[newI][newJ][newK]=='*') {
                count ++;
            }
        }
        printf("%d",count);
        return 0;
    }
    if(cor1==1) {
        printf("valid\n");
        printf("*");
    }
    if(cor1==0) {
        printf("invalid\n");
        for(int i=0;i<tmp;i++) {
            printf("%d %d %d\n",wrong_axis[i][0],wrong_axis[i][1],wrong_axis[i][2]);
        }
    }
    return 0;
}
