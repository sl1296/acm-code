
/*
code.c:1:9: fatal error: cstdio: No such file or directory
 #include
         ^~~~~~~~
compilation terminated.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
int num[10];
LL val[10];
int point[10][1010];
LL x[1010],y[1010];
LL dis(int a,int b){
    LL t1=x[a]-x[b],t2=y[a]-y[b];
    return t1*t1+t2*t2;
}
struct edge{
    int u,v;
    LL w;
    bool operator < (const edge &p) const{
        return w<p.w;
    }
};
edge all[1000010];
int fu[1010];
edge tree[1010];
edge cal[500010];
int ffind(int x){
    return x==fu[x]?x:fu[x]=ffind(fu[x]);
}
int main(){
    int t;
    scanf("%d",&t);
    for(int zz=0;zz<t;zz++){
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=0;i<q;i++){
            scanf("%d%lld",&num[i],&val[i]);
            for(int j=0;j<num[i];j++){
                scanf("%d",&point[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            scanf("%lld%lld",&x[i],&y[i]);
        }
        if(n==1){
            printf("0\n");
            continue;
        }
        int cc=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                all[cc++]=(edge){i+1,j+1,dis(i,j)};
            }
        }
        sort(all,all+cc);
        for(int i=1;i<=n;i++)fu[i]=i;
        int cnt=0;
        for(int i=0;i<cc;i++){
            int xx=ffind(all[i].u);
            int yy=ffind(all[i].v);
            if(xx!=yy){
                fu[xx]=yy;
                tree[cnt]=all[i];
                printf("%d %d %lld\n",all[i].u,all[i].v,all[i].w);
                cnt++;
                if(cnt==n-1)break;
            }
        }
        LL ans=1e18;
        for(int i=0;i<(1<<q);i++){
            LL now=0;
            int dc=cnt;
            for(int j=0;j<cnt;j++){
                cal[j]=tree[j];
            }
            for(int j=0;j<q;j++){
                if(i&(1<<j)){
                    now+=val[j];
                    for(int k=0;k<num[j];k++){
                        cal[dc++]=(edge){point[j][k-1],point[j][k],0};
                    }
                }
            }
            sort(cal,cal+dc);
            for(int j=1;j<=n;j++)fu[j]=j;
            for(int j=0;j<dc;j++){
                int xx=ffind(cal[j].u);
                int yy=ffind(cal[j].v);
                if(xx!=yy){
                    now+=cal[j].w;
                    fu[xx]=yy;
                }
            }
            ans=min(ans,now);
        }
        printf("%lld\n\n",ans);
    }
    return 0;
}

