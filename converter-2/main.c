#include <stdio.h>
static char *ones[] = {
    "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
static char *tens[] = {
    "0", "1", "twenty", "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety"};
int express(int x) {
    int one=x%10;
    int ten=(x%100-one)/10;
    int hun=(x%1000-10*ten-one)/100;
    switch(hun) {
        case 0:
        break;
        case 1:printf("one hundred ");
        break;
        case 2:printf("two hundred ");
        break;
        case 3:printf("three hundred ");
        break;
        case 4:printf("four hundred ");
        break;
        case 5:printf("five hundred ");
        break;
        case 6:printf("six hundred ");
        break;
        case 7:printf("seven hundred ");
        break;
        case 8:printf("eight hundred ");
        break;
        case 9:printf("nine hundred ");
        break;
    }
    if(ten+one!=0&&hun!=0) {
        printf("and ");
    }
    if(ten>=2) {
        printf("%s",tens[ten]);
        if(one!=0) {
            printf("-%s ",ones[one]);
        }
        else printf(" ");
    }
    if(ten<2) {
        printf("%s ",ones[one+10*ten]);
    }
    return 0;
}
int main(void) {
    long long int x;
    scanf("%lld",&x);
    int one=0,ten=0,hun=0;;
    if(x<0) {
        printf("minus ");
        x=-x;
    }
    if(x==0) {
        printf("zero");
        return 0;
    }
    if(x>0) {
        if(x<1000) {
            express(x);
        }else if(x>=1000&&x<1000000) {
            express(x/1000);
            printf("thousand ");
            express(x%1000);
        }else if(x>=1000000&&x<1000000000) {
            express(x/1000000);
            printf("million ");
            express((x%1000000)/1000);
            printf("thousand ");
            express((x%1000000)%1000);
        }else {
            express(x/1000000000);
            printf("billion ");
            express((x%1000000000)/1000000);
            printf("million ");
            express(((x%1000000000)%1000000)/1000);
            printf("thousand ");
            express(((x%1000000000)%1000000)%1000);
        }
    }
    return 0;
}
