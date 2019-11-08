
#include<cstdio>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
const int maxn=200010;
int pos[maxn],val[maxn],ans[maxn];
int tree[maxn<<2];
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline bool rea(int & x)
{
    char c=nc();x=0;
    if(c==EOF)    return false;
    for(;c>'9'||c<'0';c=nc());
    for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc());
    return true;
}
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
int query(int v,int l,int r,int rt){
    tree[rt]--;
    if(l==r)return l;
    int mid=(l+r)>>1;
    if(v<=tree[rt<<1])return query(v,lson);else return query(v-tree[rt<<1],rson);
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d%d",&pos[i],&val[i]);
        }
        build(1,n,1);
        for(int i=n;i>0;i--){
            int p=query(pos[i]+1,1,n,1);
            ans[p]=val[i];
        }
        for(int i=1;i<=n;i++){
            if(i>1)printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}

