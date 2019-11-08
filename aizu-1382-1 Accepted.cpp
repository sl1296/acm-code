
#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
int sum[maxn],dp[maxn];
char s1[maxn],s2[maxn];
struct node{
    int p,v;
    node() {}
    node(int p,int v):p(p),v(v) {}
};
deque<node> que;
//dp[i]=(2*dp[j]+sum[i]-sum[j+1]+3)/2
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s%s",s1+1,s2+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+(s2[i]!=s2[i-1]);
    }
    que.push_back(node(0,-1));
    for(int i=1;i<=n;i++){
        if(s1[i]==s2[i]) dp[i]=dp[i-1];
        else{
            while(!que.empty()&&que.front().p+k<i) que.pop_front();
            dp[i]=(sum[i]+que.front().v+3)/2;
        }
        int c=2*dp[i]-sum[i+1];
        while(!que.empty()&&que.back().v>c) que.pop_back();
        que.push_back(node(i,c));
    }
    printf("%d\n",dp[n]);
    return 0;
}

