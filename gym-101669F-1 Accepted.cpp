
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 5010
int c[maxn];
char a[maxn],b[maxn];
vector<int> g[3];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&c[i]);
    scanf("%s%s",a,b);
    ll f0=0,f1=0,f2=0;
    for(int i=0;i<n;i++){
        if(a[i]=='0'&&b[i]=='1') g[0].push_back(c[i]);
        else if(a[i]=='1'&&b[i]=='0'){
            g[1].push_back(c[i]);
            f1+=c[i];
        }
        else if(a[i]=='1'&&b[i]=='1'){
            g[2].push_back(c[i]);
            f2+=c[i];
        }
    }
    sort(g[0].begin(),g[0].end());
    sort(g[1].begin(),g[1].end(),greater<int>());
    sort(g[2].begin(),g[2].end(),greater<int>());
    int j=0,l;
    int k1=g[1].size(),k2=g[2].size();
    ll ans=0;
    for(int i=0;i<k2;i++){
        while(j<k1&&g[1][j]>=g[2][i]){
            f1-=g[1][j];
            ans+=f1+f2;
            j++;
        }
        ll t=0;
        for(l=0;l<g[0].size();l++){
            if(g[0][l]>=g[2][i]) break;
            t+=g[0][l];
        }

        if(f1+f2-g[2][i]+t+f2<=(ll)l*g[2][i]+(ll)(k1-j)*g[2][i]){
            g[0].insert(g[0].begin()+l,g[2][i]);
            f2-=g[2][i];
            ans+=f1+f2;
        }else break;
    }
    for(;j<g[1].size();j++){
        f1-=g[1][j];
        ans+=f1+f2;
    }
    for(int i=0;i<g[0].size();i++){
        f0+=g[0][i];
        ans+=f0+f2;
    }
    printf("%I64d\n",ans);
    return 0;
}
/*
4
1 1 10 1
0010
1111
*/

