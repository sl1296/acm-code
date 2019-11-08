
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
struct node{
    int x,y;
    bool operator < (const node &p) const{
        if(x!=p.x)return x<p.x;
        return y<p.y;
    }
};
int n,m,k;
node a[1000010];
ll sz[1010];
int lowbit(int x){
    return x&(-x);
}
void add(int x,int v){
    for(int i=x;i<=m;i+=lowbit(i))sz[i]+=v;
}
ll sum(int x){
    ll r=0;
    for(int i=x;i>0;i-=lowbit(i))r+=sz[i];
    return r;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        memset(sz,0,sizeof(sz));
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<k;i++){
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        sort(a,a+k);
        ll ans=0;
        for(int i=0;i<k;i++){
            ans=ans+i-sum(a[i].y);
            add(a[i].y,1);
        }
        printf("Test case %d: %lld\n",z,ans);
    }
    return 0;
}

