
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;
int xc,yc;
typedef struct kkk{
    char x[22],y[22];
    int n,fx,fy;
}kkk;
kkk kk[40010];
int dp[40010];
char rex[210][40010];
char rey[210][40010];
int l,start,endd;
map<string,int> lb;
map<string,int> cc;
int cmp(const void *a,const void *b){
    kkk *aa=(kkk*)a,*bb=(kkk*)b;
    return aa->n-bb->n;
}
int main(){
    int n,m,k,i,j;
 //   lb["a"]="A";
 //   printf("%d ",lb.begin()->second[0]);
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        xc=yc=1;
        lb.erase(lb.begin(),lb.end());
        cc.erase(cc.begin(),cc.end());
        for(i=1;i<=k;i++){
            scanf("%s%s%d",kk[i].x,kk[i].y,&kk[i].n);
            if(lb.find(kk[i].x)==lb.end()){
                lb[kk[i].x]=xc;
                kk[i].fx=xc;
                xc++;
            }else{
                kk[i].fx=lb[kk[i].x];
            }
            if(cc.find(kk[i].y)==cc.end()){
                cc[kk[i].y]=yc;
                kk[i].fy=yc;
                yc++;
            }else{
                kk[i].fy=cc[kk[i].y];
            }
        }
        qsort(&kk[1],k,sizeof(kkk),*cmp);
       // for(i=1;i<=k;i++)printf("%s %s %d\n",kk[i].x,kk[i].y,kk[i].n);
        dp[0]=0;
        for(i=1;i<=k;i++)dp[i]=2147483640;
        for(i=1;i<=k;i++){
            start=((n-k+i-1>0)?0:(n-k+i-1));endd=n>i?i:n;
            for(j=endd;j>start;j--){
                if(rex[kk[i].fx][j-1]==0 && rey[kk[i].fy][j-1]==0){
                  //  printf("%d %d:%d %d\n",i,j,dp[j-1]+kk[i].n,dp[j]);
                    if(dp[j-1]+kk[i].n<dp[j]){
                        dp[j]=dp[j-1]+kk[i].n;
                        for(l=1;l<xc;l++){
                            rex[l][j]=rex[l][j-1];
                        }
                        for(l=0;l<yc;l++){
                            rey[l][j]=rey[l][j-1];
                        }
                        rex[kk[i].fx][j]=1;
                        rey[kk[i].fy][j]=1;
                    }
                }
            }
       //     printf("%d:",i);
       //     for(j=0;j<=k;j++)printf("%d ",dp[j]);printf("\n");
        }
        printf("%d\n",dp[n]);
        for(i=0;i<xc;i++)for(j=0;j<=k;j++)rex[i][j]=0;
        for(i=0;i<yc;i++)for(j=0;j<=k;j++)rey[i][j]=0;
    }
}

