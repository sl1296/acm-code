
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;
typedef struct kkk{
    char x[22],y[22];
    int n;
}kkk;
kkk kk[40010];
int dp[40010];
char ls[40010];
map<string,string> lb;
map<string,string> cc;
map<string,string>::iterator l;
int cmp(const void *a,const void *b){
    kkk *aa=(kkk*)a,*bb=(kkk*)b;
    return aa->n-bb->n;
}
int main(){
    int n,m,k,i,j;
 //   lb["a"]="A";
 //   printf("%d ",lb.begin()->second[0]);
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        lb.erase(lb.begin(),lb.end());
        cc.erase(cc.begin(),cc.end());
        for(i=1;i<=k;i++){
            scanf("%s%s%d",kk[i].x,kk[i].y,&kk[i].n);
            lb[kk[i].x]=ls;
            cc[kk[i].y]=ls;
        }
        qsort(&kk[1],k,sizeof(kkk),*cmp);
       // for(i=1;i<=k;i++)printf("%s %s %d\n",kk[i].x,kk[i].y,kk[i].n);
        dp[0]=0;
        for(i=1;i<=k;i++)dp[i]=2147483640;
        for(i=1;i<=k;i++){
            for(j=i;j>0;j--){
                if(lb[kk[i].x][j-1]==0 && cc[kk[i].y][j-1]==0){
                  //  printf("%d %d:%d %d\n",i,j,dp[j-1]+kk[i].n,dp[j]);
                    if(dp[j-1]+kk[i].n<dp[j]){
                        dp[j]=dp[j-1]+kk[i].n;
                        for(l=lb.begin();l!=lb.end();l++){
                            l->second[j]=l->second[j-1];
                        }
                        for(l=cc.begin();l!=cc.end();l++){
                            l->second[j]=l->second[j-1];
                        }
                        lb[kk[i].x][j]=1;
                        cc[kk[i].y][j]=1;
                    }
                }
            }
       //     printf("%d:",i);
       //     for(j=0;j<=k;j++)printf("%d ",dp[j]);printf("\n");
        }
        printf("%d\n",dp[n]);
    }
}

