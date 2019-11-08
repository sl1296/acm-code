
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F(x) ((x)*(x))
int d[2010][2010];
int cmp(const void *a,const void *b){
    return *(int*)b-*(int*)a;
}
int main(){
    int x[2010],n,k,i,j;
    while(scanf("%d%d",&n,&k)!=EOF){
        for(i=0;i<n;i++)scanf("%d",&x[i]);
        qsort(x,n,sizeof(int),*cmp);
        d[2][1]=F(x[1]-x[0]);
        for(i=3;i<=n;i++){
            for(j=1;j<=(i>>1);j++){
                d[i][j]=d[i-1][j]>d[i-2][j-1]+F(x[i-1]-x[i-2])?(d[i-2][j-1]+F(x[i-1]-x[i-2])):d[i-1][j];
            }
            if(~i&1)d[i][i>>1]=d[i-2][(i>>1)-1]+F(d[i-1]-d[i-2]);
        }
        printf("%d\n",d[n][k]);
    }
    return 0;
}

