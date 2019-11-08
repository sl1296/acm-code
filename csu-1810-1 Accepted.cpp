
#include<cstdio>
#define ll long long
const ll mod=1e9+7;
char s[100010];
ll p10[100010],num[100010],cnt[100010];
int main(){
    p10[0]=1;
    for(int i=1;i<100005;++i)p10[i]=p10[i-1]*10%mod;
    int n;
    while(~scanf("%d%s",&n,s)){
        ll sum=0,now=n,all=(n+1)*(ll)n/2%mod,ans=0;
        for(int i=0;i<n;++i){
            s[i]-=48;
            sum+=s[i];
        }
        int en=(n+1)/2;
        for(int i=0;i<n;++i){
            if(i<en){
                num[i]=num[i-1]+sum;
                if(num[i]>=mod)num[i]-=mod;
                sum-=s[i];
                sum-=s[n-i-1];
                cnt[i]=cnt[i-1]+now;
                if(cnt[i]>=mod)cnt[i]-=mod;
                now-=2;
                ans+=((all-cnt[i]+mod)%mod*s[i]%mod+num[i])%mod*p10[n-i-1]%mod;
                if(ans>=mod)ans-=mod;
            }else{
                ans+=((all-cnt[n-i-1]+mod)%mod*s[i]%mod+num[n-i-1])%mod*p10[n-i-1]%mod;
                if(ans>=mod)ans-=mod;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

