
#include <stdio.h>
__int64 a[55]={1,1};
int main(){
    int i,n;
    for(i=2;i<51;i++)a[i]=a[i-1]+a[i-2];
    while(scanf("%d",&n)!=EOF)printf("%I64d\n",a[n]);
    return 0;
}

