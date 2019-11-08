
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod1 1000000007
const int MAXN=2000010;
const ll p1=10009;
char s[MAXN];
char Ma[MAXN*2];
int Mp[MAXN*2];
ll xp3[MAXN],h3[MAXN];
ull xp1[MAXN],h1[MAXN];
struct Hash{
    const static int mod=(1<<18)-1;
    vector<ull> g[mod+1];
    int count(ull x)
    {
        ull h=x&mod;
        for(int i=0;i<g[h].size();++i)
            if(g[h][i]==x) return 1;
        return 0;
    }
    void insert(ull x)
    {
        ull h=x&mod;
        g[h].push_back(x);
    }
}st;

ll Manacher(int len) {
    int l=0;
    Ma[l++]='$';
    Ma[l++]='#';
    xp1[0]=xp3[0]=1;
    h1[0]=s[0];
    h3[0]=s[0]-'0';
    for(int i=0; i<len; i++) {
        if(i){
            xp1[i]=xp1[i-1]*p1;
            xp3[i]=xp3[i-1]*10%mod1;
            h1[i]=h1[i-1]*p1+s[i];
            h3[i]=(h3[i-1]*10+s[i]-'0')%mod1;
        }
        Ma[l++]=s[i];
        Ma[l++]='#';
    }
    Ma[l]=0;
    int mx=0,id=0;
    ll ans=0;
    for(int i=0; i<l; i++) {
        Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
        while(Ma[i+Mp[i]]==Ma[i-Mp[i]]){
            int u=(i-Mp[i]+1)/2-2;
            int v=(i+Mp[i])/2-1;
            ull hx;
            ll hz;
            if(u==-1) hx=h1[v];
            else hx=h1[v]-h1[u]*xp1[v-u];
            if(st.count(hx)){
                Mp[i]++;
                continue;
            }
//            printf("%ull\n",hx);
            st.insert(hx);
            if(u==-1) hz=h3[v];
            else hz=(h3[v]-h3[u]*xp3[v-u]%mod1+mod1)%mod1;
            ans=(ans+hz)%mod1;
            Mp[i]++;
        }
        if(i+Mp[i]>mx) {
            mx=i+Mp[i];
            id=i;
        }
    }
    return ans;
}
int main() {
//    freopen("data.txt","r",stdin);
//    freopen("ans.txt","w",stdout);
    scanf("%s",s);
    int len=strlen(s);
    printf("%lld\n",Manacher(len));
    return 0;
}


