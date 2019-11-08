
#include<cstdio>
typedef long long ll;
using namespace std;
#define N 40000010
#define M 20000010
namespace IO {
    const int MX = 4e7; //1e7占用内存11000kb
    char buf[MX]; int c, sz;
    void begin() {
        c = 0;
        sz = fread(buf, 1, MX, stdin);
    }
    inline bool read(int &t) {
        while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
        if(c >= sz) return false;
        bool flag = 0; if(buf[c] == '-') flag = 1, c++;
        for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
        if(flag) t = -t;
        return true;
    }
}
int prime[N],phi[N],cnt;// prime:记录质数，phi记录欧拉函数
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
}
ll ans[M];
int main(){
    init();
    for(int i=1;i<M;i++){
        ans[i]=ans[i-1]+phi[i*2]/2;
    }
    IO::begin();
    int t,n;
    IO::read(t);
//    scanf("%d",&t);
    while(t--){
//        scanf("%d",&n);
        IO::read(n);
        printf("%lld\n",ans[n]);
    }
}

