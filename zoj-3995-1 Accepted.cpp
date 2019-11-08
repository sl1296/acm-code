
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define maxm 600010
#define maxn 100010
char ss[maxm],*s[maxn];
int dpncc[maxm],*dp[maxn],len[maxn];
ull Hashncc[maxm],*ha[maxn],xp[maxm];
map<ull,int> mp;
int main(){
    int n;
    xp[0]=1;
    for(int i=1;i<maxm;i++) xp[i]=xp[i-1]*10007;
    while(scanf("%d",&n)!=EOF){
        mp.clear();
        int l=0;
        for(int i=1;i<=n;i++){
            s[i]=ss+l;
            dp[i]=dpncc+l;
            ha[i]=Hashncc+l;
            scanf("%s",s[i]);
            len[i]=strlen(s[i]);
            l+=len[i]+1;
            ull h=0;
            for(int j=0;j<len[i];j++){
                ha[i][j]=h=h*10007+s[i][j];
                mp[h]++;
            }
        }
        for(int i=1;i<=n;i++){
            dp[i][len[i]]=0;
            for(int j=len[i]-1;j>=0;j--){
                ull h=ha[i][len[i]-1];
                if(j) h-=ha[i][j-1]*xp[len[i]-j];
                if(mp.count(h)) dp[i][j]=mp[h];
                else dp[i][j]=dp[i][j+1];
            }
        }
        int q,a,b;;
        scanf("%d",&q);
        while(q--){
            scanf("%d%d",&a,&b);
            if(a>n||b>n){
                printf("N\n");
                continue;
            }
            int l=0,r=min(len[a],len[b]);
            while(l<r){
                int mid=(l+r)/2+1;
                ull h1=ha[a][len[a]-1];
                if(len[a]>mid) h1-=ha[a][len[a]-mid-1]*xp[mid];
                ull h2=ha[b][len[b]-1];
                if(len[b]>mid) h2-=ha[b][len[b]-mid-1]*xp[mid];
                if(h1==h2) l=mid;
                else r=mid-1;
            }
            if(dp[a][len[a]-l]) printf("%d\n",dp[a][len[a]-l]);
            else printf("N\n");
        }
    }
    return 0;
}
/*
3
sabcd
xabcd
bcd
1
1 2
1
*/

