
#include<cstdio>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
const int maxn=200010;
int pos[maxn],val[maxn],ans[maxn];
int tree[maxn<<2];
void build(int l,int r,int rt){
    if(l==r){
        tree[rt]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
void update(int x,int l,int r,int rt){
    tree[rt]--;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(x<=mid)update(x,lson);else update(x,rson);
}
int query(int v,int l,int r,int rt){
    if(l==r)return l;
    int mid=(l+r)>>1;
    if(v<=tree[rt<<1])return query(v,lson);else return query(v-tree[rt<<1],rson);
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++)scanf("%d%d",&pos[i],&val[i]);
        build(1,n,1);
        for(int i=n;i>0;i--){
            int p=query(pos[i]+1,1,n,1);
            ans[p]=val[i];
            update(p,1,n,1);
        }
        for(int i=1;i<=n;i++){
            if(i>1)printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}

