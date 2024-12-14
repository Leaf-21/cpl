#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char name[50];
    int atk;
    int dfs;
    int cpr;
}team;
int cmp_atk(const void *a, const void *b) {
    team *teamA = (team *)a;
    team *teamB = (team *)b;
    if (teamA->atk < teamB->atk) return 1;
    else if (teamA->atk > teamB->atk) return -1;
    else return 0;
}
int cmp_dfs(const void *a, const void *b) {
    team *teamA = (team *)a;
    team *teamB = (team *)b;
    if (teamA->dfs < teamB->dfs) return 1;
    else if (teamA->dfs > teamB->dfs) return -1;
    else return 0;
}
int cmp_cpr(const void *a, const void *b) {
    team *teamA = (team *)a;
    team *teamB = (team *)b;
    if (teamA->cpr < teamB->cpr) return 1;
    else if (teamA->cpr > teamB->cpr) return -1;
    else return 0;
}
int main(void) {
    int n;
    scanf("%d",&n);
    team country[n];
    for(int i=0;i<n;i++) {
        scanf("%s",country[i].name);
        country[i].atk=0;
        country[i].dfs=0;
        country[i].cpr=0;
        for(int j=0;j<11;j++) {
            char str[10];
            int atk,dfs,cpr;
            scanf("%s %d %d %d",str,&atk,&dfs,&cpr);
            country[i].atk+=atk;
            country[i].dfs+=dfs;
            country[i].cpr+=cpr;
        }
    }
    qsort(country, n, sizeof(team), cmp_atk);
    for (int i = 0; i < n; i++) {
        printf("%s ", country[i].name);
        if(i==n-1)printf("\n");
    }
    qsort(country, n, sizeof(team), cmp_dfs);
    for (int i = 0; i < n; i++) {
        printf("%s ", country[i].name);
        if(i==n-1)printf("\n");
    }
    qsort(country, n, sizeof(team), cmp_cpr);
    for (int i = 0; i < n; i++) {
        printf("%s ", country[i].name);
        if(i==n-1)printf("\n");
    }
    return 0;
}