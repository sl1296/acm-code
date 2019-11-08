
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cmath>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

typedef long long LL;
const int INF = (1<<30)-1;
const int mod=1000000007;
const int maxn=100005;

int vis[maxn],r[maxn],s[maxn];

int main(){
    //freopen("in.txt","r",stdin);
 // freopen("out.txt","w+",stdout);
    int n,m;
    while(cin>>n>>m){
        memset(vis,0,sizeof(vis));
        memset(r,0,sizeof(r));
        memset(s,0,sizeof(s));

        int cnt=0;
        int t=n;
        r[cnt++]=n/m;
        n=n%m;
        while(!vis[n]&&n){
            vis[n]=cnt;
            s[cnt]=n;//s????????????????
            r[cnt++]=n*10/m;//r??????????????
            n=n*10%m;
        }

        printf("%d/%d = %d.",t,m,r[0]);

        for(int i=1;i<cnt&i<=50;i++){
            if(s[i]==n&&n) printf("(");
            printf("%d",r[i]);
        }
        if (!n) printf("(0");
        if (cnt > 50) printf("...");
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n",!n?1:cnt-vis[n]);
    }
    return 0;
}

