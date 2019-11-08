
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
int tree[2100][2100];
int treemin[2100][2100];
int n;
int a[810][810];
int maxrt;
int INF=2147483640;
void pushup2(int prt,int rt){
    tree[prt][rt]=max(tree[prt][rt<<1],tree[prt][rt<<1|1]);
    treemin[prt][rt]=min(treemin[prt][rt<<1],treemin[prt][rt<<1|1]);
}
void pushup(int rt){
    for(int i=0;i<maxrt;i++){
        tree[rt][i]=max(tree[rt<<1][i],tree[rt<<1|1][i]);
        treemin[rt][i]=min(treemin[rt<<1][i],treemin[rt<<1|1][i]);
    }
}
void build2(int x,int prt,int l,int r,int rt){
    maxrt=max(maxrt,rt);
    if(l==r){
        tree[prt][rt]=a[x][l];
        treemin[prt][rt]=a[x][l];
        return;
    }
    int mid=(l+r)/2;
    build2(x,prt,lson);
    build2(x,prt,rson);
    pushup2(prt,rt);
}
void build(int l,int r,int rt){
    if(l==r){
        build2(l,rt,1,n,1);
        return;
    }
    int mid=(l+r)/2;
    build(lson);
    build(rson);
    pushup(rt);
}
int querymax2(int prt,int x,int y,int l,int r,int rt){
    int ret=-1;
    if(l==r){
        return tree[prt][rt];
    }
    int mid=(l+r)/2;
    if(x<=mid)ret=max(ret,querymax2(prt,x,y,lson));
    if(y>mid)ret=max(ret,querymax2(prt,x,y,rson));
    return ret;
}
int querymax(int sx,int sy,int ex,int ey,int l,int r,int rt){
    int ret=-1;
    if(l==r){
        return querymax2(rt,ex,ey,1,n,1);
    }
    int mid=(l+r)/2;
    if(sx<=mid)ret=max(ret,querymax(sx,sy,ex,ey,lson));
    if(sy>mid)ret=max(ret,querymax(sx,sy,ex,ey,rson));
    return ret;
}
int querymin2(int prt,int x,int y,int l,int r,int rt){
    int ret=INF;
    if(l==r){
        return treemin[prt][rt];
    }
    int mid=(l+r)/2;
    if(x<=mid)ret=min(ret,querymin2(prt,x,y,lson));
    if(y>mid)ret=min(ret,querymin2(prt,x,y,rson));
    return ret;
}
int querymin(int sx,int sy,int ex,int ey,int l,int r,int rt){
    int ret=INF;
    if(l==r){
        return querymin2(rt,ex,ey,1,n,1);
    }
    int mid=(l+r)/2;
    if(sx<=mid)ret=min(ret,querymin(sx,sy,ex,ey,lson));
    if(sy>mid)ret=min(ret,querymin(sx,sy,ex,ey,rson));
    return ret;
}
void update2(int prt,int y,int v,int l,int r,int rt){
   // printf("update2:%d %d %d %d %d %d\n",prt,y,v,l,r,rt);
    if(l==r){
        tree[prt][rt]=v;
        treemin[prt][rt]=v;
        return;
    }
    int mid=(l+r)/2;
    if(y<=mid)update2(prt,y,v,lson);
    else update2(prt,y,v,rson);
    pushup2(prt,rt);
}
void pushup3(int prt,int y,int l,int r,int rt){
    if(l==r){
        treemin[prt][rt]=min(treemin[prt<<1][rt],treemin[prt<<1|1][rt]);
        tree[prt][rt]=max(tree[prt<<1][rt],tree[prt<<1|1][rt]);
        return;
    }
    int mid=(l+r)/2;
    if(l<=mid)pushup3(prt,y,lson);
    else pushup3(prt,y,rson);
    pushup2(prt,rt);
}
void update(int x,int y,int v,int l,int r,int rt){
 //   printf("update:%d %d %d %d %d %d\n",x,y,v,l,r,rt);
    if(l==r){
        update2(rt,y,v,1,n,1);
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid)update(x,y,v,lson);
    else update(x,y,v,rson);
    pushup3(rt,y,1,n,1);
}
int main(){
    int t;
    scanf("%d",&t);
    for(int zz=1;zz<=t;zz++){
        maxrt=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        build(1,n,1);
        int q;
        printf("Case #%d:\n",zz);
        scanf("%d",&q);
        while(q--){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            z/=2;
            int xs=max(1,x-z);
            int xe=min(n,x+z);
            int ys=max(1,y-z);
            int ye=min(n,y+z);
          //  printf("%d %d %d %d\n",xs,xe,ys,ye);
            int k1=querymin(xs,xe,ys,ye,1,n,1);
            int k2=querymax(xs,xe,ys,ye,1,n,1);
          //  printf("%d %d\n",k1,k2);
            k1=(k1+k2)/2;
            update(x,y,k1,1,n,1);
            printf("%d\n",k1);
        }
    }
    return 0;
}

