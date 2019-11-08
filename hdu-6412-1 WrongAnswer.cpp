
#include<cstdio>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const ll mod=1e9+7;
int a[5][1010];
int cnt[1010];
int k;
struct node{
    int x[5];
    bool operator < (const node &p) const{
        for(int i=0;i<k;++i)if(x[i]>=p.x[i])return false;
        return true;
    }
};
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        vector<int> ve[5][1010];
        int n;
        scanf("%d%d",&k,&n);
        for(int i=0;i<k;++i){
            for(int j=0;j<n;++j){
                scanf("%d",&a[i][j]);
                ve[i][a[i][j]].push_back(j);
            }
        }
        int nn=0,pos=0;
        for(int i=1;i<=n;++i){
            int tmp=1;
            for(int j=0;j<k;j++){
                tmp*=ve[j][i].size();
            }
            cnt[i]=tmp;
            nn+=tmp;
//            printf("i=%d cnt=%d nn=%d\n",i,tmp,nn);
        }
        vector<node> p(nn);
        vector<vector<int> > edge(nn);
        vector<ll> dp(nn);
        vector<int> du(nn);
        for(int i=0;i<nn;++i)dp[i]=1,du[i]=0;
        for(int i=1;i<=n;++i){
//            printf("i=%d\n",i);
            if(!cnt[i])continue;
            int tt[5]={-1};
            while(cnt[i]--){
                ++tt[0];
                int pp=0;
                while(tt[pp]>=ve[pp][i].size()){
                    tt[pp]=0;
                    ++pp;
                    ++tt[pp];
                }
//                printf("add %d:",pos);
//                for(int j=0;j<k;++j)printf("%d ",tt[j]);printf("\n");
//                for(int j=0;j<k;++j)printf("%d ",ve[j][i][tt[j]]);printf("\n");
                for(int j=0;j<k;++j)p[pos].x[j]=ve[j][i][tt[j]];
                ++pos;
            }
        }
        for(int i=0;i<nn;++i){
            for(int j=i+1;j<nn;++j){
                if(p[i]<p[j]){
//                    printf("add %d %d\n",i,j);
                    edge[i].push_back(j);
                    ++du[j];
                }else if(p[j]<p[i]){
//                    printf("add %d %d\n",j,i);
                    edge[j].push_back(i);
                    ++du[i];
                }
            }
        }
        queue<int> qu;
        for(int i=0;i<nn;++i){
//            printf("i=%d du=%d\n",i,du[i]);
            if(!du[i])qu.push(i);
        }
        ll ans=0;
        while(!qu.empty()){
            int now=qu.front();
            ans+=dp[now];
//            printf("now=%d ans=%I64d\n",now,ans);
            if(ans>=mod)ans=0;
            qu.pop();
            int sz=edge[now].size();
            for(int i=0;i<sz;++i){
                int nxt=edge[now][i];
                --du[nxt];
                if(!du[nxt])qu.push(nxt);
                dp[nxt]+=dp[now];
                if(dp[nxt]>=mod)dp[nxt]-=mod;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

