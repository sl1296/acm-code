
#include<cstdio>
#define ll long long
const ll mod=1e9+7;
ll c[2010][2010];
int main(){
    for(int i=1;i<2010;++i){
        c[1][i]=c[i][1]=i;
    }
    for(int j=2;j<2010;++j){
        for(int i=2;i<2010;++i){
            c[j][i]=c[j-1][i]+c[j][i-1]+1;
            if(c[j][i]>=mod)c[j][i]-=mod;
        }
    }
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        printf("%lld\n",c[n][m]*c[n][m]%mod);
    }
    return 0;
}

