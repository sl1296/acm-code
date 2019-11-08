
#include <stdio.h>
__int64 a[1000010];
int main(){
    int i,t,n,z;
    a[1]=1;a[2]=2;
    for(i=3;i<1000001;i++)a[i]=((4*i-2)*a[i-1]/(i+1))%1000000007;
    scanf("%d",&t);
    for(z=1;z<=t;z++){
        scanf("%d",&n);
        printf("Case #%d:\n%I64d\n",z,a[n]);
    }
}

