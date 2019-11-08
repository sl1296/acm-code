
#include<cstdio>
#include<algorithm>
using namespace std;
struct edge{
    int u,v,w;
    bool operator < (const edge &p) const{
        return w<p.w;
    }
};
edge e[10010];
int fu[110];
int ffind(int x){
    return x==fu[x]?x:fu[x]=ffind(fu[x]);
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(m==0&&n==0)break;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        }
        if(n==1){
            printf("0\n");
            continue;
        }
        sort(e,e+m);
        int ans=99999999;
        for(int i=0;i<m;i++){
            for(int j=1;j<=n;j++)fu[j]=j;
            int cnt=0;
            int val=e[i].w;
            for(int j=i;j<m;j++){
                int xx=ffind(e[j].u);
                int yy=ffind(e[j].v);
                if(xx!=yy){
                    cnt++;
                    fu[xx]=yy;
                    if(cnt==n-1){
                        val=e[j].w-val;
                        break;
                    }
                }
            }
            if(cnt==n-1)ans=min(ans,val);
        }
        if(ans==99999999)ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}

