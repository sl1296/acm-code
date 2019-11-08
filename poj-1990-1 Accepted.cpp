
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
struct node{
    int v,x;
    bool operator < (const node &p) const{
        return v<p.v;
    }
};
node a[20010];
ll arr[20010];
ll cnt[20010];
ll asum;
int lowbit(int x){
    return x&(-x);
}
void add(int x,int v){
    asum+=v;
    for(int i=x;i<20005;i+=lowbit(i))arr[i]+=v;
}
ll sum(int x){
    ll r=0;
    for(int i=x;i>0;i-=lowbit(i))r+=arr[i];
    return r;
}
void add2(int x,int v){
    for(int i=x;i<20005;i+=lowbit(i))cnt[i]+=v;
}
ll sum2(int x){
    ll r=0;
    for(int i=x;i>0;i-=lowbit(i))r+=cnt[i];
    return r;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        memset(arr,0,sizeof(arr));
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].v,&a[i].x);
        }
        sort(a,a+n);
        asum=0;
        add(a[0].x,a[0].x);
        add2(a[0].x,1);
        ll ans=0;
        for(int i=1;i<n;i++){
            ll t1=sum(a[i].x-1);
            ll t2=asum-t1;
            ll n1=sum2(a[i].x-1);
            ll n2=i-n1;
            ans=ans+(a[i].x*n1-t1+t2-a[i].x*n2)*a[i].v;
            add(a[i].x,a[i].x);
            add2(a[i].x,1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

