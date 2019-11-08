
#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int euler[100010];
int main(){
    for(int i=1;i<100005;i++)euler[i]=i;
    for(int i=2;i<100005;i++)if(euler[i]==i)for(int j=i;j<100005;j+=i)euler[j]=euler[j]/i*(i-1);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        if(n>m)swap(n,m);
        ll ans=0;
        for(int i=1;i<=n;i++){
            int re=m%i,cnt=m/i;
            ans=ans+cnt*euler[i];
            for(int j=1;j<=re;j++)if(__gcd(j,i)==1)ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

