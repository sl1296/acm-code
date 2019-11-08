
#include<cstdio>
int a[1000010]={0,1,2,2,3};
int main(){
    for(int i=5;i<1000005;i++)if(i%2)a[i]=a[i-1];else a[i]=(a[i-1]+a[i/2])%1000000000;
    int n;
    while(~scanf("%d",&n))printf("%d\n",a[n]);
    return 0;
}


