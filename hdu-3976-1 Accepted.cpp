
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define EPS 1e-10
using namespace std;
double a[100][100];
bool l[100];
double ans[100];
int Gauss(const int& n,const int& len){
    int res=0,r=0;
    for(int i=0;i<n;++i){
        l[i]=false;
        ans[i]=0;
    }
    for(int i=0;i<n;++i){
        if(r>=len){
            ++res;
            continue;
        }
        for(int j=r;j<len;++j){
            if(fabs(a[j][i])>EPS){
                for(int k=i;k<=n;++k)swap(a[j][k],a[r][k]);
                break;
            }
        }
        if(fabs(a[r][i])<EPS){
            ++res;
            continue;
        }
        for(int j=0;j<len;++j){
            if(j!=r&&fabs(a[j][i])>EPS){
                double tmp=a[j][i]/a[r][i];
                for(int k=i;k<=n;++k)a[j][k]-=tmp*a[r][k];
            }
        }
        l[i]=true;++r;
    }
    for(int i=r;i<len;i++){
        if(fabs(a[i][n])>EPS)return -1;
    }
    for(int i=0;i<n;++i){
        if(l[i]){
            for(int j=0;j<len;++j){
                if(fabs(a[j][i])>EPS)ans[i]=a[j][n]/a[j][i];
            }
        }
    }
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n,m;
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            u--;v--;
            a[u][u]+=1.0/w;
            a[u][v]-=1.0/w;
            a[v][v]+=1.0/w;
            a[v][u]-=1.0/w;
        }
        a[0][n]=-1;
        a[n-1][n]=1;
        int re=Gauss(n,n);
        printf("Case #%d: %.2f\n",z,ans[n-1]-ans[0]);
    }
    return 0;
}

