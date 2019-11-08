
#include <cstdio>
long long euler[50100];
int main(){
    int i,n,j;
    for(i=1;i<50010;i++)euler[i]=i;
    for(i=2;i<50010;i++)if(euler[i]==i)for(j=i;j<50010;j+=i)euler[j]=euler[j]/i*(i-1);
    for(i=2;i<50010;i++)euler[i]+=euler[i-1];
    while(1){
        scanf("%d",&n);
        if(!n)break;
        printf("%lld\n",euler[n]*2-1);
    }
    return 0;
}

