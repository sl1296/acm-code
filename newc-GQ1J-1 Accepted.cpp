
#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int dp[maxn];
struct node{
    int p,x;
    node() {}
    node(int p,int x):p(p),x(x) {}
};
stack<node> st;
int main(){
    int n,m,q,x;
    scanf("%d%d%d",&n,&m,&q);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(st.empty()||x%2==0||st.top().x!=x-1){
            st.push(node(i,x));
            dp[i]=i+1;
        }else{
            node e=st.top();st.pop();
            dp[i]=dp[e.p-1];
        }
    }
    while(q--){
         int l,r;
         scanf("%d%d",&l,&r);
         if(dp[r]==l||dp[l-1]==dp[r]) printf("Yes\n");
         else printf("No\n");
    }
    return 0;
}

