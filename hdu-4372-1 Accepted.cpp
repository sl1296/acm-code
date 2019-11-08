
#include<cstdio>
#define ll long long
const ll mod=1000000007;
ll stir1[2010][2010];
ll c[2010][2010];
int main(){
    for(int i=0;i<2005;i++)stir1[i][i]=1;
    for(int i=1;i<2005;i++)for(int j=1;j<=i;j++)stir1[i][j]=((i-1)*stir1[i-1][j]%mod+stir1[i-1][j-1])%mod;
    stir1[0][0]=0;
    for(int i=0;i<=2005;i++)c[i][0]=1;
    for(int i=1;i<=2005;i++)for(int j=1;j<=2005;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    int t;
    scanf("%d",&t);
    while(t--){
        int n,f,b;
        scanf("%d%d%d",&n,&f,&b);
        ll ans=c[f+b-2][f-1]*stir1[n-1][f+b-2]%mod;
        printf("%lld\n",ans);
    }
    return 0;
}

