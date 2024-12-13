#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int main(void) {
    int n,q;
    scanf("%d %d",&n,&q);
    int *arr=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<q;i++) {
        int *a=malloc(sizeof(int));
        scanf("%d",a);
        int *item;
        item=bsearch(a,arr,n,sizeof(int),cmp);
        if(item!=NULL) {
            printf("%d\n",item-arr);
        }else {
            printf("-1\n");
        }
    }
    return 0;
}
