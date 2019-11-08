
#include<cstdio>
#include<algorithm>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
struct node{
    int val,lv,rv,llen,rlen,len;
    bool isone;
};
node tree[400010];
void pushup(int rt){
    int left=rt<<1,right=rt<<1|1;
    tree[rt].lv=tree[left].lv;
    tree[rt].rv=tree[right].rv;
    if(tree[left].rv<tree[right].lv){
        tree[rt].llen=tree[left].llen;
        if(tree[left].isone)tree[rt].llen+=tree[right].llen;
        tree[rt].rlen=tree[right].rlen;
        if(tree[right].isone)tree[rt].rlen+=tree[left].rlen;
        tree[rt].len=max(max(tree[left].len,tree[right].len),tree[left].rlen+tree[right].llen);
        if(tree[left].isone&&tree[right].isone)tree[rt].isone=true;else tree[rt].isone=false;
    }else{
        tree[rt].llen=tree[left].llen;
        tree[rt].rlen=tree[right].rlen;
        tree[rt].len=max(tree[left].len,tree[right].len);
        tree[rt].isone=false;
    }
}
void build(int l,int r,int rt){
    if(l==r){
        scanf("%d",&tree[rt].val);
        tree[rt].lv=tree[rt].rv=tree[rt].val;
        tree[rt].llen=tree[rt].rlen=tree[rt].len=1;
        tree[rt].isone=true;
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int pos,int v,int l,int r,int rt){
    if(l==r){
        tree[rt].val=tree[rt].lv=tree[rt].rv=v;
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)update(pos,v,lson);else update(pos,v,rson);
    pushup(rt);
}
int query(int from,int to,int l,int r,int rt){
    if(from<=l&&to>=r)return tree[rt].len;
    int mid=(l+r)>>1;
    int ret=0;
    if(from<=mid)ret=max(ret,query(from,to,lson));
    if(to>mid)ret=max(ret,query(from,to,rson));
    if(from<=mid&&to>mid&&tree[rt<<1].rv<tree[rt<<1|1].lv){
        int left=min(mid-from+1,tree[rt<<1].rlen);
        int right=min(to-mid,tree[rt<<1|1].llen);
        ret=max(ret,left+right);
    }
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d%d",&n,&q);
        build(1,n,1);
        char in[5];
        int a,b;
        while(q--){
            scanf("%s%d%d",in,&a,&b);
            if(in[0]=='U'){
                update(a+1,b,1,n,1);
            }else{
                printf("%d\n",query(a+1,b+1,1,n,1));
            }
        }
    }
    return 0;
}

