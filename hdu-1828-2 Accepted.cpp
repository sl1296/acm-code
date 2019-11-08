
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
struct edge{
    int l,r,h,v;
    bool operator < (const edge &p) const{
        if(h!=p.h)return h<p.h;
        return v>p.v;
    }
};
edge a[10010];
struct node{
    int val,len,num,l,r;
};
node tree[80010];
void build(int l,int r,int rt){
    tree[rt]=(node){0,0,0,0,0};
    if(l==r)return;
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
}
void pushup(int l,int r,int rt){
    if(tree[rt].val){
        tree[rt].len=r-l+1;
        tree[rt].num=tree[rt].l=tree[rt].r=1;
    }else if(l==r){
        tree[rt]=(node){0,0,0,0,0};
    }else{
        tree[rt].num=tree[rt<<1].num+tree[rt<<1|1].num-(tree[rt<<1].r&&tree[rt<<1|1].l);
        tree[rt].l=tree[rt<<1].l;
        tree[rt].r=tree[rt<<1|1].r;
        tree[rt].len=tree[rt<<1].len+tree[rt<<1|1].len;
    }
}
void update(int from,int to,int v,int l,int r,int rt){
  //  printf("%d %d %d %d %d %d\n",from,to,v,l,r,rt);
    if(from<=l&&to>=r){
        tree[rt].val+=v;
        pushup(l,r,rt);
        return;
    }
    int mid=(l+r)>>1;
    if(from<=mid)update(from,to,v,lson);
    if(to>mid)update(from,to,v,rson);
    pushup(l,r,rt);
}
int main(){
    int n,N=20010;
    while(~scanf("%d",&n)){
        int cnt=0;
        for(int i=0;i<n;i++){
            int aa,bb,cc,dd;
            scanf("%d%d%d%d",&aa,&bb,&cc,&dd);
            aa+=10001;bb+=10001;cc+=10001;dd+=10001;
            a[cnt++]=(edge){aa,cc-1,bb,1};
            a[cnt++]=(edge){aa,cc-1,dd,-1};
        }
        sort(a,a+cnt);
        build(1,N,1);
        int ans=0;
        int prelen=0,preh=0;
        for(int i=0;i<cnt;i++){
         //   printf("i=%d\n",i);
            if(i)ans+=tree[1].num*2*(a[i].h-preh);
        //    printf("%d %d %d\n",tree[1].num,a[i].h,preh);
        //    printf("ans=%d\n",ans);
        //    printf("l=%d r=%d\n",a[i].l,a[i].r);
            update(a[i].l,a[i].r,a[i].v,1,N,1);
            ans+=abs(tree[1].len-prelen);
        //    printf("%d %d\n",tree[1].len,prelen);
        //    printf("ans=%d\n",ans);
            prelen=tree[1].len;
            preh=a[i].h;
        }
        printf("%d\n",ans);
    }
    return 0;
}

