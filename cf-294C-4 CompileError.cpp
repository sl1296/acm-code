
/*
"Can\u0027t compile file:
program.cpp: In function \u0027int main()\u0027:
program.cpp:21:35: error: invalid conversion from \u0027long long int (*)(const void*, const void*)\u0027 to \u0027int (*)(const void*, const void*)\u0027 [-fpermissive]
     qsort(a,m,sizeof(__int64),*cmp);
                                   ^
In file included from program.cpp:3:0:
C:/Programs/mingw-tdm-gcc/include/stdlib.h:371:22: note:   initializing argument 4 of \u0027void qsort(void*, size_t, size_t, int (*)(const void*, const void*))\u0027
 _CRTIMP void __cdecl qsort(void*, size_t, size_t,
                      ^
"
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 1000000007
__int64 a[1010],c=1,x[1010][1010],y[1010];
__int64 cmp(const void *a,const void *b){
    return *(__int64*)a-*(__int64*)b;
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
    for(i=0;i<m;i++)scanf("%I64d",&a[i]);
    qsort(a,m,sizeof(__int64),*cmp);
    r=n-m;
    if(a[0]>1)c=(c*x[r][a[0]-1])%M;
    r=r-a[0]+1;
    for(i=1;i<m;i++){
        c=(c*y[a[i]-a[i-1]-2])%M;
        c=(c*x[r][a[i]-a[i-1]-1])%M;
        r=r-a[i]+a[i-1]+1;
    }
    printf("%I64d\n",c);
}

