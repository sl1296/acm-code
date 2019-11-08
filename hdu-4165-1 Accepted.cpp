
#include <stdio.h>
__int64 a[1000010];
int main(){
    int i,n;
    a[1]=1;a[2]=2;
    for(i=3;i<31;i++)a[i]=(4*i-2)*a[i-1]/(i+1);
    while(1){
        scanf("%d",&n);
        if(!n)break;
        printf("%I64d\n",a[n]);
    }
    return 0;
}

