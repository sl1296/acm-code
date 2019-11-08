
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int gs[12][100010];
int maxn[12],maxs,maxdel;
struct node{
    int k,p;
    bool operator < (const node &a) const{
        if(p!=a.p)return p>a.p;
        return k<a.k;
    }
};
node jn[1010];
ll dp[2010];
const ll INF=1LL<<60;
int main(){
    int m,n;
    while(~scanf("%d%d",&n,&m)){
        maxdel=0;
        for(int i=0;i<11;i++)gs[i][0]=maxn[i]=0;
        for(int i=0;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            gs[b][++gs[b][0]]=a;
            maxn[b]=max(maxn[b],a);
            maxdel=max(maxdel,b);
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d",&jn[i].k,&jn[i].p);
        }
        sort(jn+1,jn+m+1);
        maxs=jn[1].p;
        if(maxdel>=maxs){
            printf("-1\n");
            continue;
        }
        int pp=1;
        for(int i=1;i<=m;i++){
            jn[pp++]=jn[i];
            while(i+1<m&&jn[i+1].p==jn[i].p)i++;
        }
        ll ans=0;
        for(int z=0;z<11;z++){
            if(gs[z][0]){
                int en=maxn[z]+maxs+2;
                dp[0]=0;
                for(int j=1;j<en;j++)dp[j]=INF;
                for(int i=1;i<pp;i++){
                    int sh=jn[i].p-z;
                    if(sh<1)break;
                    for(int j=sh;j<en;j++){
                        dp[j]=min(dp[j],dp[j-sh]+jn[i].k);
                    }
                }
                for(int i=1;i<=gs[z][0];i++){
                    ll cnt=INF;
                    int aim=gs[z][i];
                    int to=aim+maxs;
                    for(int i=aim;i<=to;i++){
                        cnt=min(cnt,dp[i]);
                    }
                    ans+=cnt;
                }
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

