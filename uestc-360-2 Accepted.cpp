
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
        if(tree[left].isone&&tree[right].isone){
            tree[rt].isone=true;
            tree[rt].len=tree[rt].llen=tree[rt].rlen=tree[left].len+tree[right].len;
        }else if(tree[left].isone){
            tree[rt].isone=false;
            tree[rt].llen=tree[left].len+tree[right].llen;
            tree[rt].rlen=tree[right].rlen;
            tree[rt].len=max(tree[rt].llen,tree[right].len);
        }else if(tree[right].isone){
            tree[rt].isone=false;
            tree[rt].llen=tree[left].llen;
            tree[rt].rlen=tree[left].rlen+tree[right].len;
            tree[rt].len=max(tree[left].len,tree[rt].rlen);
        }else{
            tree[rt].isone=false;
            tree[rt].llen=tree[left].llen;
            tree[rt].rlen=tree[right].rlen;
            tree[rt].len=max(max(tree[left].len,tree[right].len),tree[left].rlen+tree[right].llen);
        }
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
    tree[rt].val=0;
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void pushdown(int rt){
    int left=rt<<1,right=rt<<1|1;
    tree[left].val+=tree[rt].val;
    tree[left].lv+=tree[rt].val;
    tree[left].rv+=tree[rt].val;
    tree[right].val+=tree[rt].val;
    tree[right].lv+=tree[rt].val;
    tree[right].rv+=tree[rt].val;
    tree[rt].val=0;
}
void update(int from,int to,int v,int l,int r,int rt){
    if(from<=l&&to>=r){
        tree[rt].val+=v;
        tree[rt].lv+=v;
        tree[rt].rv+=v;
        return;
    }
    int mid=(l+r)>>1;
    if(tree[rt].val)pushdown(rt);
    if(from<=mid)update(from,to,v,lson);
    if(to>mid)update(from,to,v,rson);
    pushup(rt);
}
int query(int from,int to,int l,int r,int rt){
   // printf("%d %d %d %d %d\n",from,to,l,r,rt);
    if(from<=l&&to>=r){
       // printf("len2=%d\n",tree[rt].len);
        return tree[rt].len;
    }
    int mid=(l+r)>>1;
    int ret=0;
    bool need=false;
    if(tree[rt].val){
        pushdown(rt);
        need=true;
    }
    if(from<=mid)ret=max(ret,query(from,to,lson));
    if(to>mid)ret=max(ret,query(from,to,rson));
    if(need)pushup(rt);
    if(from<=mid&&to>mid&&tree[rt<<1].rv<tree[rt<<1|1].lv){
        int left=min(mid-from+1,tree[rt<<1].rlen);
        int right=min(to-mid,tree[rt<<1|1].llen);
        ret=max(ret,left+right);
    }
  //  printf("ret=%d\n",ret);
    return ret;
}
int main(){
  //  freopen("in.txt","r",stdin);
 //   freopen("out.txt","w+",stdout);
    int n,q,t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d%d",&n,&q);
        build(1,n,1);
        printf("Case #%d:\n",z);
        char in[5];
        int a,b,c;
        while(q--){
            scanf("%s",in);
            if(in[0]=='a'){
                scanf("%d%d%d",&a,&b,&c);
                update(a,b,c,1,n,1);
            }else{
                scanf("%d%d",&a,&b);
                printf("%d\n",query(a,b,1,n,1));
            }
        }
    }
    return 0;
}
/*
10
10 100
1 9 2 3 10 8 7 6 5 4
q 2 7
*/

