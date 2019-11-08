
#include<cstdio>
typedef long long ll;
using namespace std;
#define N 40000010
#define M 20000010
int prime[3000000],phi[N],cnt;// prime:记录质数，phi记录欧拉函数
int Min_factor[N];// i的最小素因子
bool vis[N];
void init()
{
    cnt=0;
    phi[1]=1;
    int x;
    for(int i=2;i<N;i++)
    {
        if(!vis[i])
        {
            prime[++cnt]=i;
            phi[i]=i-1;
            Min_factor[i]=i;
        }
        for(int k=1;k<=cnt&&prime[k]*i<N;k++)
        {
            x=prime[k]*i;
            vis[x]=true;
            Min_factor[x]=prime[k];
            if(i%prime[k]==0)
            {
                phi[x]=phi[i]*prime[k];
                break;
            }
            else phi[x]=phi[i]*(prime[k]-1);
        }
    }
//    printf("%d ??\n",cnt);
}
ll ans[M];
int main(){
    init();
    for(int i=1;i<M;i++){
        ans[i]=ans[i-1]+phi[i*2]/2;
    }
    int t,n;
//    scanf("%d",&t);
//    while(t--){
//        scanf("%d",&n);
//        printf("%lld\n",ans[n]);
//    }
}

