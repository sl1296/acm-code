
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 1000000007
int a[1000];
__int64 c=1,x[1010][1010],y[1010];
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int main(){
    __int64 n,m,i,r,j;
    for(i=0;i<=1000;i++)x[i][0]=1;
    for(i=1;i<=1000;i++)for(j=1;j<=1000;j++)x[i][j]=(x[i-1][j]+x[i-1][j-1])%M;
    y[0]=1;
    for(i=1;i<=1000;i++)y[i]=(y[i-1]*2)%M;
    scanf("%I64d%I64d",&n,&m);
    if(m==n){
        printf("1\n");
        return 0;
    }
    for(i=0;i<m;i++)scanf("%d",&a[i]);
    qsort(a,m,sizeof(int),*cmp);
    r=n-m;
    if(a[0]>1)c=(c*x[r][a[0]-1])%M;
    r=r-a[0]+1;
    for(i=1;i<m;i++){
        if(a[i]-a[i-1]==1)continue;
        c=(c*y[a[i]-a[i-1]-2])%M;
        c=(c*x[r][a[i]-a[i-1]-1])%M;
        r=r-a[i]+a[i-1]+1;
    }
    printf("%I64d\n",c);
}

