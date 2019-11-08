
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define EPS 1e-10
using namespace std;
int Gauss(double a[][110],bool l[],double ans[],const int& n,const int& len){
    int res=0,r=0;
    for(int i=0;i<n;++i)l[i]=false;
    for(int i=0;i<n;++i){
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
    for(int i=0;i<n;++i){
        if(l[i]){
            for(int j=0;j<len;++j){
                if(fabs(a[j][i])>EPS)ans[i]=a[j][n]/a[j][i];
            }
        }
    }
    return res;
}
double a[110][110];
bool l[110];
double ans[110];
double mp[110][110];
int id[110][110];
double out[110][110];
int main(){
    int w,h,d,cas=0;
    while(1){
        scanf("%d%d%d",&w,&h,&d);
        if(!w&&!h&&!d)break;
        int sid=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                scanf("%lf",&mp[i][j]);
                id[i][j]=sid++;
            }
        }
        memset(a,0,sizeof(a));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                int cnt=0;
                int si=max(i-d,0),ei=min(h-1,i+d),sj=max(0,j-d),ej=min(w-1,j+d);
                int now=id[i][j];
                for(int ii=si;ii<=ei;ii++){
                    for(int jj=sj;jj<=ej;jj++){
                        if(abs(ii-i)+abs(jj-j)<=d){
                            int to=id[ii][jj];
                            cnt++;
                            a[now][to]=1;
                        }
                    }
                }
                a[now][sid]=mp[i][j]*cnt;
            }
        }
        Gauss(a,l,ans,sid,sid);
        for(int i=0;i<sid;i++){
            out[i/w][i%w]=ans[i];
        }
        if(cas)printf("\n");
        cas++;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                printf("%8.2f",out[i][j]);
            }
            printf("\n");
        }
    }
}

