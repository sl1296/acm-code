

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#define EPS 1e-10
using namespace std;
const int maxnode = 10*10+5 ;
const int sigma_size = 6 ;
const int maxn = 20 ;
int str[maxn] ;
int l;
double cnt[maxnode][maxnode] ;
struct AC {
    int ch[maxnode][7] ;
    int cnt[maxnode];
    int val[maxnode];
    int last[maxnode] ;
    int f[maxnode];
    int sz;
    void init() {
        sz=1 ;
        memset(f,0,sizeof(f)) ;
        memset(val,0,sizeof(val)) ;
        memset(ch[0],0,sizeof(ch[0])) ;
        memset(last,0,sizeof(last)) ;
    }
    int insert(int v) {
        int u = 0 ;
        for(int i=0; i<l; i++) {
            int c = str[i] ;
            if(!ch[u][c]) {
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz ;
                sz++ ;
            }
            u = ch[u][c] ;
        }
        val[u]=v ;
        return u ;
    }
    void getfail() {
        queue<int> qq ;
        f[0]=0 ;
        for(int c=1; c<=sigma_size; c++) {
            int u = ch[0][c];
            if(u) {
                f[u] = 0 ;
                qq.push(u) ;
                last[u]=0 ;
            }
        }
        while(!qq.empty()) {
            int r = qq.front();
            qq.pop() ;
            for(int c = 1; c<=sigma_size; c++) {
                int u = ch[r][c];
                if (!u) { ch[r][c] = ch[f[r]][c]; continue; }
                qq.push(u) ;
                int v = f[r] ;
                while(v&&!ch[v][c])v = f[v];
                f[u] = ch[v][c];
                last[u] = val[f[u]]?f[u]:last[f[u]] ;
            }
        }
    }

} ac;
int num[maxn] ;
bool isl[maxnode];
double ans[maxnode];
int Gauss(double a[][maxnode],bool l[],double ans[],const int& n,const int& len){
    int res=0,r=0;
    for(int i=0;i<n;++i)
        l[i]=false;
    for(int i=0;i<n;++i){
        for(int j=r;j<len;++j)
            if(fabs(a[j][i])>EPS){
                for(int k=i;k<=n;++k)
                    swap(a[j][k],a[r][k]);
                break;
            }
        if(fabs(a[r][i])<EPS){
            ++res;
            continue;
        }
        for(int j=0;j<len;++j)
            if(j!=r&&fabs(a[j][i])>EPS){
                double tmp=a[j][i]/a[r][i];
                for(int k=i;k<=n;++k)
                    a[j][k]-=tmp*a[r][k];
            }
        l[i]=true;++r;
    }
    for(int i=0;i<n;++i)
        if(l[i])
            for(int j=0;j<len;++j)
                if(fabs(a[j][i])>EPS)
                    ans[i]=a[j][n]/a[j][i];
    return res;
}
bool vis[maxnode];
int main() {
    int t ;
    scanf("%d",&t);
    while(t--) {
        int n;
        ac.init();
        scanf("%d%d",&n,&l);
        memset(vis,false,sizeof(vis));
        for(int i=1; i<=n; i++) {
            for(int j=0; j<l; j++) {
                scanf("%d",&str[j]) ;
            }
            num[i] = ac.insert(1) ;
            vis[num[i]]=true;
//            printf("num = %d\n",num[i]) ;
        }
        ac.getfail() ;
//        printf("yes\n") ;
//        printf("sz = %d\n",ac.sz) ;
        memset(cnt,0,sizeof(cnt));
        memset(ans,0,sizeof(ans));
        memset(isl,false,sizeof(isl));
        for(int i=0;i<ac.sz;i++){
            cnt[i][i]=1;
        }
        cnt[0][ac.sz]=1;
        for(int i=0;i<ac.sz;i++){
            if(vis[i]){
                continue;
            }
            for(int j=1;j<=6;j++){
                cnt[ac.ch[i][j]][i]-=1.0/6;
            }
        }
        Gauss(cnt,isl,ans,ac.sz,ac.sz);
        double all=0;
        for(int i=1;i<=n;i++)all+=ans[num[i]];
        for(int i=1;i<=n;i++){
            if(i>1)printf(" ");
            printf("%.6f",ans[num[i]]/all);
        }
        printf("\n");
    }
    return 0;
}
/*
3
5 1
1
2
3
4
5

6 2
1 1
2 1
3 1
4 1
5 1
6 1

4 3
1 2 3
2 3 4
3 4 5
4 5 6
*/

