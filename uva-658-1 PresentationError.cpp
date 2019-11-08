
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int time[110];
char pre[110][30],tt[110][30];
struct node{
    int id,len;
    bool operator < (const node &p) const{
        return len>p.len;
    }
};
bool vis[1100000];
int dis[1100000];
const int INF=2147483600;
int main(){
    int n,m,cas=1;
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0)break;
        for(int i=0;i<m;i++){
            scanf("%d%s%s",&time[i],pre[i],tt[i]);
        }
        if(cas>1)printf("\n");
        printf("Product %d\n",cas++);
        for(int i=0;i<(1<<n);i++){
            dis[i]=INF;
        }
        dis[(1<<n)-1]=0;
        memset(vis,false,sizeof(vis));
        priority_queue<node> qu;
        qu.push((node){(1<<n)-1,0});
        while(!qu.empty()){
            node tmp=qu.top();
            qu.pop();
          //  printf("get:%d %d\n",tmp.id,tmp.len);
            if(vis[tmp.id])continue;
            vis[tmp.id]=true;
            for(int i=0;i<m;i++){
             //   printf("i=%d\n",i);
                bool ch=true;
                int to=0;
                for(int j=0;j<n;j++){
                    int now=(1<<j)&tmp.id;
                 //   printf("j=%d now=%d\n",j,now);
                    if(now&&pre[i][j]=='+'||!now&&pre[i][j]=='-'||pre[i][j]=='0'){
                        if(tt[i][j]=='+')to|=(1<<j);
                        else if(tt[i][j]=='0')to|=now;
                    }else{
                        ch=false;
                        break;
                    }
                }
                if(ch){
                //    printf("check pass\n");
                    int add=dis[tmp.id]+time[i];
                    if(add<dis[to]){
                        dis[to]=dis[tmp.id]+time[i];
                        qu.push((node){to,dis[to]});
                   //     printf("add:%d %d\n",to,dis[to]);
                    }
                }
            }
        }
        if(dis[0]>=INF){
            printf("Bugs cannot be fixed.\n");
        }else{
            printf("Fastest sequence takes %d seconds.\n",dis[0]);
        }
    }
    return 0;
}

