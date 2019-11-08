


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    int a,b,w;
    char c[2];
    bool operator < (const node &p) const{
        return w<p.w;
    }
};
node e[110];
int mx[110];
bool use[110];
int fa[110];
int ffind(int x){
    return x==fa[x]?x:fa[x]=ffind(fa[x]);
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d%d%s",&e[i].a,&e[i].b,&e[i].w,e[i].c);
        }
        sort(e,e+m);
        for(int i=1;i<=m;i++)mx[i]=9999999;
        memset(use,false,sizeof(use));
        for(int i=1;i<=n;i++)fa[i]=i;
        int ans=0,cnt=0;
        for(int i=0;i<m;i++){
            if(e[i].c[0]=='R'||e[i].c[0]=='G'){
                int k1=ffind(e[i].a);
                int k2=ffind(e[i].b);
//                printf("k1=%d k2=%d\n",k1,k2);
                if(k1!=k2){
                    fa[k1]=k2;
                    ans+=e[i].w;
                    use[i]=true;
                    cnt++;
//                    printf("%d %d %d %s\n",e[i].a,e[i].b,e[i].w,e[i].c);
                }
            }
        }
//        printf("cnt=%d\n",cnt);
        if(cnt==n-1){
            mx[cnt]=min(mx[cnt],ans);
            for(int i=0;i<m;i++){
                if(!use[i]){
                    ans+=e[i].w;
                    cnt++;
                    mx[cnt]=min(mx[cnt],ans);
                }
            }
        }
        memset(use,false,sizeof(use));
        for(int i=1;i<=n;i++)fa[i]=i;
        ans=0;cnt=0;
        for(int i=0;i<m;i++){
            if(e[i].c[0]=='G'||e[i].c[0]=='B'){
                int k1=ffind(e[i].a);
                int k2=ffind(e[i].b);
                if(k1!=k2){
                    fa[k1]=k2;
                    ans+=e[i].w;
                    use[i]=true;
                    cnt++;
                }
            }
        }
        if(cnt==n-1){
            mx[cnt]=min(mx[cnt],ans);
            for(int i=0;i<m;i++){
                if(!use[i]){
                    ans+=e[i].w;
                    cnt++;
                    mx[cnt]=min(mx[cnt],ans);
                }
            }
        }
        printf("Case #%d:\n",z);
        for(int i=1;i<=m;i++){
            if(mx[i]==9999999)printf("-1\n");
            else printf("%d\n",mx[i]);
        }
    }
    return 0;
}



