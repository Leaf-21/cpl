#include <stdio.h>
int main(void){
    int X;
    scanf("%x",&X);
    printf("%d\n",X);
    printf("%u\n",X);
    float new_X=*(float *)&X;
    printf("%.6f\n",new_X);
    printf("%.3e",new_X);
    return 0;
}
