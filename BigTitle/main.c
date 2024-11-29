#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char *str ;
    char c,d;
    while(scanf("%c",&c)) {
        c=toupper(c);
        printf("%c",c);
        while(scanf("%c",&d),d!=' ') {
            d=tolower(d);
            printf("%c",d);
            if(d=='\n') {
                return 0;
            }
        }
        printf(" ");
    }
    return 0;
}
