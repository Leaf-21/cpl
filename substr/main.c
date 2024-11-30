#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *str;
    char *part;
    str=(char *)malloc(100000*sizeof(char));
    scanf("%s",str);
    part=(char *)malloc(100000*sizeof(char));
    scanf("%s",part);
    int len_p=strlen(part);
    int len_s=strlen(str);
    for(int i=0;i<=len_s-len_p;i++) {
        int count=0;
        char *tmp;
        tmp=str+i;
        for(int j=0;j<len_p;j++) {
            char s=*(tmp+j);
            char t=*(part+j);
            if(s==t) {
                count++;
            }
        }
        if(count ==len_p) {
            printf("%d ",i);
        }
    }
    return 0;
}
