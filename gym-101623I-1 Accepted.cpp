
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define maxn 505
struct node{
    int d,s,id;
    bool operator <(const node &rhs)const{
        return s+rhs.d<rhs.s+d;
    }
}v[maxn];
int dp[maxn][maxn];
bool path[maxn][maxn];
vector<int> vec;
int main(){
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&v[i].d,&v[i].s);
        v[i].id=i;
    }
    sort(v+1,v+1+n);
    memset(dp,inf,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            dp[i][j]=dp[i-1][j];
            path[i][j]=false;
            if(dp[i-1][j-1]+max(v[i].d,v[i].s)>c) continue;
            if(dp[i][j]>dp[i-1][j-1]+v[i].s){
                dp[i][j]=dp[i-1][j-1]+v[i].s;
                path[i][j]=true;
            }
        }
    }
    int p=0;
    for(int i=0;i<=n;i++)
        if(dp[n][i]<inf) p=i;
    int j=n;
    while(p){
        if(path[j][p]){
            vec.push_back(v[j].id);
            p--;
        }
        j--;
    }
    reverse(vec.begin(),vec.end());
    printf("%d\n",vec.size());
    for(int i=0;i<vec.size();i++)
        printf("%d%c",vec[i],i==vec.size()-1?'\n':' ');
    return 0;
}

