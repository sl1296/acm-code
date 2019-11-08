
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int num[10];
ll val[10];
int point[10][1010];
ll x[1010],y[1010];
struct ee{
    int u,v;
    ll w;
    bool operator < (const ee &p) const{
        return w<p.w;
    }
};
ee edge[1000010];
int cnt;
ll dis(int a,int b){
    ll t1=x[a]-x[b],t2=y[a]-y[b];
    return t1*t1+t2*t2;
}
int fa[1010];
ee enew[1000010];
int cc;
int ffind(int x){
    return x==fa[x]?x:fa[x]=ffind(fa[x]);
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=0;z<t;z++){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%lld",&num[i],&val[i]);
            for(int j=0;j<num[i];j++){
                scanf("%d",&point[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            scanf("%lld%lld",&x[i],&y[i]);
        }
        cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                edge[cnt++]=(ee){i,j,dis(i,j)};
            }
        }
        sort(edge,edge+cnt);
        cc=0;
        ll ans=0;
        for(int i=1;i<=n;i++)fa[i]=i;
        for(int i=0;i<cnt;i++){
            int xx=ffind(edge[i].u);
            int yy=ffind(edge[i].v);
            if(xx!=yy){
                fa[xx]=yy;
                enew[cc++]=edge[i];
                ans+=edge[i].w;
                if(cc==n-1)break;
            }
        }
        for(int i=1;i<(1<<m);i++){
            for(int j=1;j<=n;j++)fa[j]=j;
            ll tmp=0;
            for(int j=0;j<m;j++){
                if(i&(1<<j)){
                    int xx=ffind(point[j][0]);
                    for(int k=1;k<num[j];k++){
                        int yy=ffind(point[j][k]);
                        if(yy!=xx)fa[yy]=xx;
                    }
                    tmp+=val[j];
                }
            }
            for(int j=0;j<cc;j++){
                int xx=ffind(enew[j].u);
                int yy=ffind(enew[j].v);
                if(xx!=yy){
                    tmp+=enew[j].w;
                    fa[xx]=yy;
                }
            }
            ans=min(ans,tmp);
        }
        if(z)printf("\n");
        printf("%lld\n",ans);
    }
    return 0;
}

