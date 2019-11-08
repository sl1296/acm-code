
#include<cstdio>
#include<algorithm>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
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
int tree[80010],soc;
int l[20010],r[20010];
bool ans[80010];
struct node{
    int val,id,pos;
    bool operator < (const node &p) const{
        return val<p.val;
    }
};
node so[20010];
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
    rea(t);
    while(t--){
        int n;
        rea(n);
        soc=0;
        for(int i=1;i<=n;i++){
            rea(l[i]);rea(r[i]);
            so[soc++]=(node){l[i],i,1};
            so[soc++]=(node){r[i],i,2};
            ans[i]=false;
        }
        sort(so,so+soc);
        int cnt=1;
        for(int i=0;i<soc;i++){
            if(so[i].pos==1){
                l[so[i].id]=cnt;
            }else{
                r[so[i].id]=cnt;
            }
            while(i+1<soc&&so[i+1].val==so[i].val){
                i++;
                if(so[i].pos==1){
                    l[so[i].id]=cnt;
                }else{
                    r[so[i].id]=cnt;
                }
            }
            cnt++;
        }
        cnt--;
        build(1,cnt,1);
        for(int i=1;i<=n;i++)update(l[i],r[i],i,1,cnt,1);
        query(1,cnt,1);
        int ret=0;
        for(int i=1;i<=n;i++)if(ans[i])ret++;
        printf("%d\n",ret);
    }
    return 0;
}

