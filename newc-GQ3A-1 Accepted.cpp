
#include<bits/stdc++.h>
using namespace std;
int a[200][200];
bool vis[200][200];
int xx[8]={2,2,1,1,-1,-1,-2,-2};
int yy[8]={-1,1,-2,2,-2,2,-1,1};
struct node{
    int x,y,step;
};
int main(){
    queue<node> qu;
    qu.push((node){100,100,0});
    vis[100][100]=true;
    while(!qu.empty()){
        node now=qu.front();
        qu.pop();
        a[now.x][now.y]=now.step;
        for(int i=0;i<8;++i){
            int tx=now.x+xx[i],ty=now.y+yy[i];
            if(tx<0 || ty<0 || tx>199 || ty>199 || vis[tx][ty])continue;
            node add=(node){tx,ty,now.step+1};
            vis[tx][ty]=true;
            qu.push(add);
        }
    }
//    for(int i=160;i>=100;--i){
//        for(int j=100;j<=160;++j){
//            if(i>j || (i+j-200)%3!=2)printf(" - ");else
//            printf("%2d ",a[i][j]);
//        }
//        printf("\n");
//    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        if(n<50 && m<50 && n>-50 && m>-50){
            printf("%d\n",a[n+100][m+100]);
        }else{
            if(n<0)n=-n;
            if(m<0)m=-m;
            if(n<m)swap(n,m);
            int id=m+n;
            int ix=id%3;
            if(ix==0){
                int ans=id/3;
                int pos=(n-m)/2+1;
                int hv=ans/2+1;
                if(pos>hv){
                    ans+=((pos-hv-1)/4+1)*2;
                }
                printf("%d\n",ans);
            }else if(ix==1){
                int ans=id/3+1;
                int pos=(n-m)/2+1;
                int hv=ans/2+2;
                if(pos>hv){
                    ans+=((pos-hv-1)/4+1)*2;
                }
                printf("%d\n",ans);
            }else if(ix==2){
                int ans=id/3+2;
                int pos=(n-m)/2+1;
                int hv=ans/2+3;
                if(pos>hv){
                    ans+=((pos-hv-1)/4+1)*2;
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

