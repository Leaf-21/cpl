#include <stdio.h>
#include<math.h>
int sushu(int x) {// 要判定是否是素数的数
    int flag = 1; // 1 表示该数是素数
    for (int i = 2; i <= sqrt(x + 0.5); i++) {
        if (x % i == 0) {
            flag = 0;
        }
    }
    return flag;
}
int main(void) {
    int n;
    int cnt=0;
    scanf("%d",&n);
    for(int i=2;i<=n;i++) {
        int tmp=0;
        int k=0;
        int j=i;
        for(;j!=0;) {
            tmp=j%10;
            j/=10;
            k=k*10+tmp;
        }
        if(sushu(i)==1&&sushu(k)==1) {
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
