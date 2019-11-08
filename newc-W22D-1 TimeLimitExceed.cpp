
#include<cstdio>
#include<cmath>
#define ll long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
ll tree[800010];
double rsin[800010],rcos[800010];
inline void pushup(int LL,int RR,int rt){
    double ss=rsin[LL]+rsin[RR];
    double cc=rcos[LL]+rcos[RR];
    rsin[rt]=ss*cos(tree[rt])+cc*sin(tree[rt]);
    rcos[rt]=cc*cos(tree[rt])-ss*sin(tree[rt]);
}
inline void pushdown(int LL,int RR,int rt,int l,int mid,int r){
    tree[LL]+=tree[rt];
    tree[RR]+=tree[rt];
    tree[rt]=0;
    if(l==mid){
        rsin[LL]=sin(tree[LL]);
        rcos[LL]=cos(tree[LL]);
    }else{
        pushup(LL<<1,LL<<1|1,LL);
    }
    if(mid+1==r){
        rsin[RR]=sin(tree[RR]);
        rcos[RR]=cos(tree[RR]);
    }else{
        pushup(RR<<1,RR<<1|1,RR);
    }
}
void build(int l,int r,int rt){
    if(l==r){
        scanf("%lld",&tree[rt]);
        rsin[rt]=sin(tree[rt]);
        rcos[rt]=cos(tree[rt]);
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt<<1,rt<<1|1,rt);
}
void update(int l,int r,int rt,int from,int to,int v){
//    printf("%d %d %d\n",l,r,rt);
    if(from<=l&&r<=to){
        tree[rt]+=v;
        if(l==r){
            rsin[rt]=sin(tree[rt]);
            rcos[rt]=cos(tree[rt]);
        }else{
            pushup(rt<<1,rt<<1|1,rt);
        }
//        printf("%d %d %d:%f %f\n",l,r,rt,rsin[rt],rcos[rt]);
        return;
    }
    int mid=(l+r)>>1;
    if(tree[rt])pushdown(rt<<1,rt<<1|1,rt,l,mid,r);
    if(from<=mid)update(lson,from,to,v);
    if(to>mid)update(rson,from,to,v);
    pushup(rt<<1,rt<<1|1,rt);
//    printf("%d %d %d:%f %f\n",l,r,rt,rsin[rt],rcos[rt]);
}
double query(int l,int r,int rt,int from,int to){
//    printf("%d %d %d %d %d\n",l,r,rt,from,to);
    if(from<=l&&r<=to){
        return rsin[rt];
    }
    double ret=0;
    int mid=(l+r)>>1;
    if(tree[rt])pushdown(rt<<1,rt<<1|1,rt,l,mid,r);
    if(from<=mid)ret+=query(lson,from,to);
    if(to>mid)ret+=query(rson,from,to);
    return ret;
}
int main(){
//    printf("%f %f %f %f\n",sin(1),sin(2),sin(3),sin(4));
//    printf("%f %f %f %f\n",cos(1),cos(2),cos(3),cos(4));
    int n,m;
    scanf("%d",&n);
    build(1,n,1);
    scanf("%d",&m);
    while(m--){
        int op,l,r,v;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1){
            scanf("%d",&v);
            update(1,n,1,l,r,v);
        }else{
            printf("%.1f\n",query(1,n,1,l,r));
        }
    }
    return 0;
}

