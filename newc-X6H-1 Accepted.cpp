
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
    int a,b,v;
    bool operator < (const node &p) const{
        return v<p.v;
    }
};
node a[500010];
int fa[100010];
int ffind(int x){
    return x==fa[x]?x:fa[x]=ffind(fa[x]);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].v);
    }
    sort(a,a+m);
    for(int i=1;i<=n;++i)fa[i]=i;
    int cnt=0,ans=0;
    for(int i=0;i<m;++i){
        int u=ffind(a[i].a);
        int v=ffind(a[i].b);
        if(u!=v){
            fa[u]=v;
            ans+=a[i].v;//
            ++cnt;
            if(cnt==n-1)break;
        }
    }
    printf("%d\n",ans);
    return 0;
}

