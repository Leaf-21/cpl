#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int n;
    scanf("%d",&n);
    char *str;
    str=(char*)malloc(1000*sizeof(char));
    scanf("%s",str);
    int len=strlen(str);
    char *newstr=malloc(sizeof(char)*1006);
    memset(newstr,'.',sizeof(newstr));
    strncpy(newstr+3,str,len);
    char *string=malloc(sizeof(char)*1006);
    for(int i=0;i<1006;i++) {
        *(string+i)=*(newstr+i);
    }
    for(int i=0;i<n;i++) {
        for(int j=3;j<len+3;j++) {
            char a=*(string+j);
            int cntA=0,cntB=0;
            if(a=='.') {
                for(int k=-3;k<=3;k++) {
                    if(*(string+j+k)=='A') {
                        cntA++;
                    }else if(*(string+j+k)=='B') {
                        cntB++;
                    }
                }
                if(cntA>=2&&cntA<=4&&cntB==0) {
                    *(newstr+j)='A';
                }else if(cntA==0&&cntB>=2&&cntB<=4) {
                    *(newstr+j)='B';
                }
            }else if(a=='A') {
                for(int k=-3;k<=3;k++) {
                    if(*(string+j+k)=='A') {
                        cntA++;
                    }else if(*(string+j+k)=='B') {
                        cntB++;
                    }
                }
                if(cntB>0) {
                    *(newstr+j)='.';
                }else if(cntA>=6||cntA<=2) {
                    *(newstr+j)='.';
                }
            }else if(a=='B') {
                for(int k=-3;k<=3;k++) {
                    if(*(string+j+k)=='A') {
                        cntA++;
                    }else if(*(string+j+k)=='B') {
                        cntB++;
                    }
                }
                if(cntA>0){
                    *(newstr+j)='.';
                }else if(cntB>=6||cntB<=2) {
                    *(newstr+j)='.';
                }
            }
        }
        strncpy(string,newstr,1006);
    }
    for(int i=3;i<len+3;i++) {
        printf("%c",*(string+i));
    }
    return 0;
}
