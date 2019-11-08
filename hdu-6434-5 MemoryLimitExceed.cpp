
#include<cstdio>
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
#define ll long long
#define N 40000001
int prime[N],phi[N],cnt;// prime:记录质数，phi记录欧拉函数
int Min_factor[N];// i的最小素因子
bool vis[N];
ll ans[20000001];
inline void Init()
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
int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w+",stdout);
//    for(int i=1;i<40000001;i++)euler[i]=i;
//    for(int i=2;i<40000001;i++)if(euler[i]==i)for(int j=i;j<40000001;j+=i)euler[j]=euler[j]/i*(i-1);
    Init();
    for(int i=1;i<20000001;i++){
        ans[i]=ans[i-1]+(phi[i<<1]>>1);
    }
    int t,n;
    IO::begin();
    IO::read(t);
//    scanf("%d",&t);
    while(t--){
//        scanf("%d",&n);
        IO::read(n);
        printf("%lld\n",ans[n]);
    }
}

