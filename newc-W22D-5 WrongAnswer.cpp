
#include<cstdio>
#include<cmath>
#define ll long long
#define lson l,mid,LL
#define rson mid+1,r,RR
ll tree[800010];
double rsin[800010],rcos[800010];
//inline char nc(){
//    static char buf[100000],*p1=buf,*p2=buf;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
//inline bool rea(int &x){
//    char c=nc();x=0;
//    if(c==EOF)return false;
//    for(;c>'9'||c<'0';c=nc());
//    for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc());
//    return true;
//}
void build(int l,int r,int rt){
    if(l==r){
        scanf("%lld",&tree[rt]);
        rsin[rt]=sin(tree[rt]);
        rcos[rt]=cos(tree[rt]);
        return;
    }
    int mid=(l+r)>>1,LL=rt<<1,RR=rt<<1|1;
    build(lson);
    build(rson);
    rsin[rt]=rsin[LL]+rsin[RR];
}
void update(int l,int r,int rt,int from,int to,int v){
//    printf("%d %d %d\n",l,r,rt);
    if(from<=l&&r<=to){
        tree[rt]+=v;
        if(l==r){
            rsin[rt]=sin(tree[rt]);
            rcos[rt]=cos(tree[rt]);
        }else{
            double ss=rsin[rt],cc=rcos[rt];
            rsin[rt]=ss*cos(v)+cc*sin(v);
            rcos[rt]=cc*cos(v)-ss*sin(v);
        }
//        printf("%d %d %d:%f %f\n",l,r,rt,rsin[rt],rcos[rt]);
        return;
    }
    int mid=(l+r)>>1,LL=rt<<1,RR=rt<<1|1;
    if(tree[rt]){
        tree[LL]+=tree[rt];
        tree[RR]+=tree[rt];
        double ss,cc;
        if(from>mid){
            if(l==mid){
                rsin[LL]=sin(tree[LL]);
                rcos[LL]=cos(tree[LL]);
            }else{
                ss=rsin[LL];cc=rcos[LL];
                rsin[LL]=ss*cos(tree[rt])+cc*sin(tree[rt]);
                rcos[LL]=cc*cos(tree[rt])-ss*sin(tree[rt]);
            }
        }
        if(to<=mid){
            if(mid+1==r){
                rsin[RR]=sin(tree[RR]);
                rcos[RR]=cos(tree[RR]);
            }else{
                ss=rsin[RR];cc=rcos[RR];
                rsin[RR]=ss*cos(tree[rt])+cc*sin(tree[rt]);
                rcos[RR]=cc*cos(tree[rt])-ss*sin(tree[rt]);
            }
        }
        tree[rt]=0;
    }
    if(from<=mid)update(lson,from,to,v);
    if(to>mid)update(rson,from,to,v);
    rsin[rt]=rsin[LL]+rsin[RR];
    rcos[rt]=rcos[LL]+rcos[RR];
//    printf("%d %d %d:%f %f\n",l,r,rt,rsin[rt],rcos[rt]);
}
double query(int l,int r,int rt,int from,int to,bool cal){
//    printf("%d %d %d %d %d\n",l,r,rt,from,to);
    if(from<=l&&r<=to){
        if(cal){
            if(l==r){
                rsin[rt]=sin(tree[rt]);
                rcos[rt]=cos(tree[rt]);
            }else{
                int LL=rt<<1,RR=rt<<1|1;
                double ss=rsin[LL]+rsin[RR],cc=rcos[LL]+rcos[RR];
                rsin[rt]=ss*cos(tree[rt])+cc*sin(tree[rt]);
                rcos[rt]=cc*cos(tree[rt])-ss*sin(tree[rt]);
            }
        }
        return rsin[rt];
    }
    double ret=0;
    int mid=(l+r)>>1,LL=rt<<1,RR=rt<<1|1;
    if(tree[rt]){
        cal=true;
        tree[LL]+=tree[rt];
        tree[RR]+=tree[rt];
        double ss,cc;
        if(from>mid){
            if(l==mid){
                rsin[LL]=sin(tree[LL]);
                rcos[LL]=cos(tree[LL]);
            }else{
                ss=rsin[LL];cc=rcos[LL];
                rsin[LL]=ss*cos(tree[rt])+cc*sin(tree[rt]);
                rcos[LL]=cc*cos(tree[rt])-ss*sin(tree[rt]);
            }
        }
        if(to<=mid){
            if(mid+1==r){
                rsin[RR]=sin(tree[RR]);
                rcos[RR]=cos(tree[RR]);
            }else{
                ss=rsin[RR];cc=rcos[RR];
                rsin[RR]=ss*cos(tree[rt])+cc*sin(tree[rt]);
                rcos[RR]=cc*cos(tree[rt])-ss*sin(tree[rt]);
            }
        }
        tree[rt]=0;
    }
    if(from<=mid)ret+=query(lson,from,to,cal);
    if(to>mid)ret+=query(rson,from,to,cal);
    return ret;
}
int main(){
//    printf("%f %f %f %f\n",sin(1),sin(2),sin(3),sin(4));
//    printf("%f %f %f %f\n",cos(1),cos(2),cos(3),cos(4));
    int n,m;
    scanf("%d",&n);
//    rea(n);
    build(1,n,1);
    scanf("%d",&m);
//    rea(m);
    while(m--){
        int op,l,r,v;
        scanf("%d%d%d",&op,&l,&r);
//        rea(op);rea(l);rea(r);
        if(op==1){
            scanf("%d",&v);
//            rea(v);
            update(1,n,1,l,r,v);
        }else{
            printf("%.1f\n",query(1,n,1,l,r,false));
        }
    }
    return 0;
}

