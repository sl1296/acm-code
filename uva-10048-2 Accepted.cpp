
#include<cstdio>
#include<algorithm>
using namespace std;
int dis[110][110];
const int INF=2147483600;
int main(){
    int c,s,q,cas=1;
    while(~scanf("%d%d%d",&c,&s,&q)){
        if(c==0&&q==0&&s==0)break;
        for(int i=1;i<=c;i++){
            for(int j=1;j<=c;j++){
                dis[i][j]=INF;
            }
        }
        for(int i=0;i<s;i++){
            int a,b,cc;
            scanf("%d%d%d",&a,&b,&cc);
            dis[a][b]=dis[b][a]=cc;
        }
        for(int k=1;k<=c;k++){
            for(int i=1;i<=c;i++){
                for(int j=1;j<=c;j++){
                    dis[i][j]=min(dis[i][j],max(dis[i][k],dis[k][j]));
                }
            }
        }
        if(cas>1)printf("\n");
        printf("Case #%d\n",cas++);
        for(int i=0;i<q;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            if(dis[a][b]>=INF){
                printf("no path\n");
            }else{
                printf("%d\n",dis[a][b]);
            }
        }
    }
}

