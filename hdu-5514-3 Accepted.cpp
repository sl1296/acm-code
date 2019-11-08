
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#define ll long long
using namespace std;
ll a[10005];
ll b[10005];
ll c[10005];
ll ys[10005];
ll ysc[10005];
int ysn,cn;
map<int,int> ma;
int main(){
    int t;
    scanf("%d",&t);
    int cas=0;
    while(t--){
        ma.clear();
        ll n,m;
        ysn=0;
        cn=0;
        scanf("%I64d%I64d",&n,&m);
        for(int i=1;i<=sqrt(m);i++){
            if(m%i==0){
                ys[ysn]=i;
                ysn++;
                ys[ysn]=m/i;
                ysn++;
            }
        }
        if(ys[ysn-1]==ys[ysn-2])ysn--;
        sort(ys,ys+ysn);
        for(int i=0;i<ysn;i++)ma[ys[i]]=i;
        memset(ysc,0,sizeof(ysc));
        for(int i=0;i<n;i++){
            scanf("%I64d",&a[i]);
            b[i]=__gcd(a[i],m);
        }
        sort(b,b+n);
        for(int i=0;i<n;i++){
            while(b[i+1]==b[i] && i+1<n)i++;
            c[cn]=b[i];
            cn++;
        }
        for(int i=0;i<cn;i++){
            for(int j=ma[c[i]];j<ysn;j++){
                if(ys[j]%c[i]==0){
                    ysc[j]=1;
                }
            }
        }
        for(int i=1;i<ysn;i++){
            for(int j=0;j<i;j++){
                if(ys[i]%ys[j]==0){
                    ysc[i]-=ysc[j];
                }
            }
        }
        ll ans=0;
        for(int i=0;i<ysn;i++){
            if(ysc[i]){
                ll tmp;
                tmp=(m-ys[i])*(m/ys[i])/2;
                ans+=ysc[i]*tmp;
            }
        }
        cas++;
        printf("Case #%d: %I64d\n",cas,ans);
    }
    return 0;
}

