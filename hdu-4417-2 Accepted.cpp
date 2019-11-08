
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    int x,v;
    bool operator < (const node &p){
        return v<p.v;
    }
};
struct que{
    int id,l,r,h;
    bool operator < (const que &p){
        return h<p.h;
    }
};
node a[100010];
que q[100010];
int sz[100010];
int ans[100010];
int n,m;
int lowbit(int x){
    return x&(-x);
}
void add(int x,int v){
    for(int i=x;i<=n;i+=lowbit(i))sz[i]+=v;
}
int sum(int x){
    int r=0;
    for(int i=x;i>0;i-=lowbit(i))r+=sz[i];
    return r;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        memset(sz,0,sizeof(sz));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i].v);
            a[i].x=i+1;
        }
        sort(a,a+n);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].h);
            q[i].id=i;
        }
        sort(q,q+m);
        int p=0;
        for(int i=0;i<m;i++){
            while(p<n&&a[p].v<=q[i].h){
                add(a[p].x,1);
                p++;
            }
            ans[q[i].id]=sum(q[i].r+1)-sum(q[i].l);
        }
        printf("Case %d:\n",z);
        for(int i=0;i<m;i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}

