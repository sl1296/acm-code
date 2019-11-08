
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=2147480000,INE=2147483600;
int dp[1000010];
struct node{
    int pos,val;
    bool operator < (const node &p) const{
        return val>p.val;
    }
};
int main(){
    int n,l,a,b,s,e;
    while(~scanf("%d%d%d%d",&n,&l,&a,&b)){
        bool is=true;
        if(l&1)is=false;
        dp[0]=0;
        for(int i=1;i<=l;i++)dp[i]=INF;
        for(int i=0;i<n;i++){
            scanf("%d%d",&s,&e);
            if(e-s>b*2)is=false;
            if(is)for(int j=s+1;j<e;j++)dp[j]=INE;
        }
        if(!is){
            printf("-1\n");
            continue;
        }
        priority_queue<node> qu;
        int now=0;
        for(int i=2*a;i<=l;i++){
            if(dp[i]==INE)continue;
            int st=i-2*b;
            int en=i-2*a;
            for(int j=now;j<=en;j++){
                if(dp[j]==INE)continue;
                qu.push((node){j,dp[j]});
            }
            now=en+1;
            while(!qu.empty()){
                node tmp=qu.top();
                if(tmp.pos>=st){
                    dp[i]=min(dp[i],tmp.val+1);
                    break;
                }
                qu.pop();
            }
        }
        printf("%d\n",dp[l]);
    }
    return 0;
}

