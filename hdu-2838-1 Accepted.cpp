
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n;
struct node{
    int x,id;
    bool operator < (const node &p) const{
        if(x!=p.x)return x<p.x;
        return id<p.id;
    }
};
node a[100010];
ll sz[100010],cnt[100010];
int lowbit(int x){
    return x&(-x);
}
void add(int x,int v){
    for(int i=x;i<=n;i+=lowbit(i))sz[i]+=v;
}
ll sum(int x){
    ll r=0;
    for(int i=x;i>0;i-=lowbit(i))r+=sz[i];
    return r;
}
void add2(int x,int v){
    for(int i=x;i<=n;i+=lowbit(i))cnt[i]+=v;
}
ll sum2(int x){
    ll r=0;
    for(int i=x;i>0;i-=lowbit(i))r+=cnt[i];
    return r;
}
int main(){
    while(~scanf("%d",&n)){
        memset(cnt,0,sizeof(cnt));
        memset(sz,0,sizeof(sz));
        for(int i=0;i<n;i++){
            scanf("%d",&a[i].x);
            a[i].id=i+1;
            add(i+1,a[i].x);
            add2(i+1,1);
        }
        sort(a,a+n);
        ll ans=0;
        for(int i=0;i<n;i++){
            add(a[i].id,-a[i].x);
            add2(a[i].id,-1);
            ll cc=sum2(a[i].id-1);
            ll tt=sum(a[i].id-1);
            ans=ans+cc*a[i].x+tt;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

