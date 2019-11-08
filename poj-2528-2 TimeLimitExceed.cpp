
#include<cstdio>
#include<map>
#include<algorithm>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
int tree[80010],so[20010],soc;
int l[20010],r[20010];
bool ans[80010];
void build(int l,int r,int rt){
    tree[rt]=0;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
}
void pushdown(int rt){
    tree[rt<<1]=tree[rt<<1|1]=tree[rt];
    tree[rt]=0;
}
void update(int from,int to,int v,int l,int r,int rt){
    if(from<=l&&to>=r){
        tree[rt]=v;
        return;
    }
    int mid=(l+r)>>1;
    if(tree[rt])pushdown(rt);
    if(from<=mid)update(from,to,v,lson);
    if(to>mid)update(from,to,v,rson);
}
void query(int l,int r,int rt){
    if(tree[rt]){
        ans[tree[rt]]=true;
        return;
    }
    if(l==r)return;
    int mid=(l+r)>>1;
    query(lson);
    query(rson);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        soc=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&l[i],&r[i]);
            so[soc++]=l[i];
            so[soc++]=r[i];
            ans[i]=false;
        }
        sort(so,so+soc);
        map<int,int> ma;
        int cnt=1;
        for(int i=0;i<soc;i++){
            ma[so[i]]=cnt++;
            while(i+1<soc&&so[i+1]==so[i])i++;
        }
        cnt--;
        build(1,cnt,1);
        for(int i=1;i<=n;i++)update(ma[l[i]],ma[r[i]],i,1,cnt,1);
        query(1,cnt,1);
        int ret=0;
        for(int i=1;i<=n;i++)if(ans[i])ret++;
        printf("%d\n",ret);
    }
    return 0;
}

