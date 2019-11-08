
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
int tree[20010];
int a[5010];
int so[5010];
void pushup(int rt){
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
void update(int x,int v,int l,int r,int rt){
    if(l==r){
        tree[rt]+=v;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)update(x,v,lson);else update(x,v,rson);
    pushup(rt);
}
int query(int f,int t,int l,int r,int rt){
    if(f>t)return 0;
    if(l>=f&&r<=t){
        return tree[rt];
    }
    int re=0;
    int mid=(l+r)>>1;
    if(f<=mid)re+=query(f,t,lson);
    if(t>mid)re+=query(f,t,rson);
    return re;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        memset(tree,0,sizeof(tree));
        map<int,int> ma;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            so[i]=a[i];
        }
        sort(so+1,so+n+1);
        int cnt=1;
        for(int i=1;i<=n;i++){
            ma[so[i]]=cnt++;
            while(i+1<=n&&so[i+1]==so[i])i++;
        }
        int sum=0;
        cnt--;
        for(int i=1;i<=n;i++){
            a[i]=ma[a[i]];
            sum+=query(a[i]+1,cnt,1,cnt,1);
            update(a[i],1,1,cnt,1);
        }
        int ans=sum;
        for(int i=1;i<n;i++){
            sum-=query(1,a[i]-1,1,cnt,1);
            sum+=query(a[i]+1,cnt,1,cnt,1);
            ans=min(ans,sum);
        }
        printf("%d\n",ans);
    }
    return 0;
}

