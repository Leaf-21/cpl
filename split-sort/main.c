#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int char_cmp(const void* p1, const void* p2)
{
    return strcmp(*(char**)p1,*(char**)p2);
}

int main(void) {
    char *str=malloc(sizeof(char)*10000);
    scanf("%s",str);
    char *s=malloc(sizeof(char));
    scanf("%s",s);
    char **token=malloc(sizeof(char*)*100);
    token[0]=strtok(str,s);
    int cnt=0;
    for(int i=1;token[i-1]!=NULL;i++) {
        token[i]=strtok(NULL,s);
        cnt++;
    }
    qsort(token,cnt,sizeof(char*),char_cmp);
    for(int i=0;i<cnt;i++) {
        printf("%s\n",token[i]);
    }
    return 0;
}
