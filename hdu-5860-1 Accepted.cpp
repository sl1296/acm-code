
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<queue>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#define rep(i,k,n) for(int i=(k);i<=(n);i++)
#define rep0(i,n) for(int i=0;i<(n);i++)
#define red(i,k,n) for(int i=(k);i>=(n);i--)
#define sqr(x) ((x)*(x))
#define clr(x,y) memset((x),(y),sizeof(x))
#define pb push_back
#define mod 1000000007

const int maxn=3000300;
int n,k,q,tot;
int f[maxn],s[maxn],ans[maxn],a[maxn];

void init()
{
    int tmp=n;
    tot=0;
    s[0]=0;
    while(tmp)
    {
        tot++;
        s[tot]=s[tot-1]+(tmp-1)/k+1;
        tmp-=(tmp-1)/k+1;
    }
    f[0]=0;
    rep(i,0,n-1){
        f[i]= i % k ? f[i-i/k-1]+1 : 0 ;
        a[i]= i % k ? a[i-i/k-1] : i/k+1;
    }
    rep(i,0,n-1){
        int tmp=s[f[i]]+a[i];
        ans[tmp]=i;
    }
    //rep(i,1,n) printf("%d %d\n",i,ans[i]+1 );
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&k,&q);
        init();
        while (q--){
            int x;
            scanf("%d",&x);
            printf("%d\n",ans[x]+1);
        }
    }
    
    return 0;
}

