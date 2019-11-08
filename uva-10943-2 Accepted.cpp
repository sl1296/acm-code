
#include<cstdio>
#define ll long long
ll c[300][300]={1};
int main(){
    int n,k;
    for(int i=1;i<=210;i++){
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%1000000;
    }
    while(1){
        scanf("%d%d",&n,&k);
        if(n==0&&k==0)break;
        printf("%lld\n",c[n+k-1][k-1]);
    }
    return 0;
}

