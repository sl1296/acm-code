
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
set<pp> st;
const int MAXN=1000010;
const ll p1=10009;
const ll p2=10007;
#define mod1 1000000007
#define mod2 1000000009
char s[MAXN];
char Ma[MAXN*2];
int Mp[MAXN*2];
ll xp1[MAXN],xp2[MAXN],xp3[MAXN];
ll h1[MAXN],h2[MAXN],h3[MAXN];
ll Manacher(int len) {
    int l=0;
    Ma[l++]='$';
    Ma[l++]='#';
    xp1[0]=xp2[0]=xp3[0]=1;
    h1[0]=h2[0]=s[0];
    h3[0]=s[0]-'0';
    for(int i=0; i<len; i++) {
        if(i){
            xp1[i]=xp1[i-1]*p1%mod1;
            xp2[i]=xp2[i-1]*p2%mod2;
            xp3[i]=xp3[i-1]*10%mod1;
            h1[i]=(h1[i-1]*p1+s[i])%mod1;
            h2[i]=(h2[i-1]*p2+s[i])%mod2;
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
            ll hx,hy,hz;
            if(u==-1) hx=h1[v];
            else hx=(h1[v]-h1[u]*xp1[v-u]%mod1+mod1)%mod1;
            if(u==-1) hy=h2[v];
            else hy=(h2[v]-h2[u]*xp2[v-u]%mod2+mod2)%mod2;
            if(st.count(make_pair(hx,hy))){
                Mp[i]++;
                continue;
            }
            st.insert(make_pair(hx,hy));
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
    while(scanf("%s",s)!=EOF){
        int len=strlen(s);
        st.clear();
        printf("%lld\n",Manacher(len));
    }
    return 0;
}

