
#include<cstdio>
#include<cstring>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
int tree[800010];
int bj[800010];
bool ans[150010];
int retl[150010],retr[150010],retc;
void pushdown(int rt){
    tree[rt<<1]=tree[rt<<1|1]=tree[rt];
    tree[rt]=-1;
    bj[rt<<1]=bj[rt<<1|1]=0;
}
void pushdown2(int rt){
    if(tree[rt<<1]==-1)bj[rt<<1]^=1;else tree[rt<<1]^=1;
    if(tree[rt<<1|1]==-1)bj[rt<<1|1]^=1;else tree[rt<<1|1]^=1;
    bj[rt]=0;
}
void update(int from,int to,int v,int l,int r,int rt){
    if(from<=l&&to>=r){
        tree[rt]=v;
        bj[rt]=0;
        return;
    }
    if(tree[rt]!=-1)pushdown(rt);
    if(bj[rt]==1)pushdown2(rt);
    int mid=(l+r)>>1;
    if(from<=mid)update(from,to,v,lson);
    if(to>mid)update(from,to,v,rson);
}
void update2(int from,int to,int l,int r,int rt){
    if(from<=l&&to>=r){
        if(tree[rt]==-1)bj[rt]^=1;else tree[rt]^=1;
        return;
    }
    if(tree[rt]!=-1)pushdown(rt);
    if(bj[rt]==1)pushdown2(rt);
    int mid=(l+r)>>1;
    if(from<=mid)update2(from,to,lson);
    if(to>mid)update2(from,to,rson);
}
void query(int l,int r,int rt){
    if(tree[rt]!=-1){
        if(tree[rt])for(int i=l;i<=r;i++)ans[i]=true;
        return;
    }
    if(bj[rt]==1)pushdown2(rt);
    int mid=(l+r)>>1;
    query(lson);
    query(rson);
}
int main(){
    char op,f,t;
    int a,b,n=150000;
    memset(tree,0,sizeof(tree));
    memset(bj,0,sizeof(bj));
    memset(ans,false,sizeof(ans));
    while(~scanf("%c %c%d,%d%c\n",&op,&f,&a,&b,&t)){
        int l=a*2+1,r=b*2+1;
        if(f=='(')l++;if(r==')')r--;
        if(op=='U'){
            update(l,r,1,1,n,1);
        }else if(op=='I'){
            if(1<=l-1)update(1,l-1,0,1,n,1);
            if(r+1<=n)update(r+1,n,0,1,n,1);
        }else if(op=='D'){
            update(l,r,0,1,n,1);
        }else if(op=='C'){
            if(1<=l-1)update(1,l-1,0,1,n,1);
            if(r+1<=n)update(r+1,n,0,1,n,1);
            update2(l,r,1,n,1);
        }else{
            update2(l,r,1,n,1);
        }
    }
    query(1,n,1);
    for(int i=1;i<=n;i++){
        if(ans[i]){
            retl[retc]=i;
            while(i+1<n&&ans[i+1])i++;
            retr[retc++]=i;
        }
    }
    if(retc){
        for(int i=0;i<retc;i++){
            if(i)printf(" ");
            if(retl[i]&1)printf("[");else printf("(");
            printf("%d",(retl[i]-1)/2);
            printf(",");
            printf("%d",retr[i]/2);
            if(retr[i]&1)printf("]");else printf(")");
        }
        printf("\n");
    }else{
        printf("empty set\n");
    }
    return 0;
}

