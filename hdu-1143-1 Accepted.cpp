
#include <stdio.h>
__int64 a[55]={1,0,3};
int main(){
    int i,n;
    for(i=4;i<33;i+=2)a[i]=a[i-2]*4-a[i-4];
    while(1){
        scanf("%d",&n);
        if(n==-1)break;
        printf("%I64d\n",a[n]);
    }
    return 0;
}

