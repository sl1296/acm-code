
#include<cstdio>
#include<algorithm>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
struct node{
    int val,llen,rlen,len;
    bool isone;
};
node tree[200010];
void pushup(int rt){
    int left=rt<<1,right=rt<<1|1;
    tree[rt].llen=tree[left].llen;
    if(tree[left].isone)tree[rt].llen+=tree[right].llen;
    tree[rt].rlen=tree[right].rlen;
    if(tree[right].isone)tree[rt].rlen+=tree[left].rlen;
    tree[rt].len=max(max(tree[left].len,tree[right].len),tree[left].rlen+tree[right].llen);
    if(tree[left].isone&&tree[right].isone)tree[rt].isone=true;else tree[rt].isone=false;
}
void pushdown(int l,int r,int mid,int rt){
    int left=rt<<1,right=rt<<1|1;
    tree[left]=tree[right]=tree[rt];
    if(tree[rt].val==0){
        tree[left].llen=tree[left].rlen=tree[left].len=mid-l+1;
        tree[right].llen=tree[right].rlen=tree[right].len=r-mid;
    }
    tree[rt].val=-1;
}
void update(int from,int to,int v,int l,int r,int rt){
  //  printf("%d %d %d %d %d %d\n",from,to,v,l,r,rt);
    if(from<=l&&to>=r){
        tree[rt].val=v;
        if(v)tree[rt].llen=tree[rt].rlen=tree[rt].len=0;
        else tree[rt].llen=tree[rt].rlen=tree[rt].len=r-l+1;
        if(v)tree[rt].isone=false;else tree[rt].isone=true;
        return;
    }
    int mid=(l+r)>>1;
    if(tree[rt].val!=-1)pushdown(l,r,mid,rt);
    if(from<=mid)update(from,to,v,lson);
    if(to>mid)update(from,to,v,rson);
    pushup(rt);
}
int query(int len,int l,int r,int rt){
  //  printf("%d %d %d %d\n",len,l,r,rt);
    int mid=(l+r)>>1;
    if(tree[rt].val==0)return l;
    if(tree[rt<<1].len>=len)return query(len,lson);
   // printf("lren=%d rlen=%d\n",tree[rt<<1].rlen,tree[rt<<1|1].llen);
    if(tree[rt<<1].rlen+tree[rt<<1|1].llen>=len)return mid-tree[rt<<1].rlen+1;
    return query(len,rson);
}
int main(){
    int n,q;
    while(~scanf("%d%d",&n,&q)){
        tree[1]=(node){0,n,n,n,true};
        while(q--){
            int a,b,c;
            scanf("%d",&a);
            if(a==1){
                scanf("%d",&b);
                if(tree[1].len<b){
                    printf("0\n");
                }else{
                    c=query(b,1,n,1);
                    update(c,c+b-1,1,1,n,1);
                    printf("%d\n",c);
                }
            }else{
                scanf("%d%d",&b,&c);
                update(b,b+c-1,0,1,n,1);
            }
        }
    }
    return 0;
}

