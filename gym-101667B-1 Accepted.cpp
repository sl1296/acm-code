
#include <bits/stdc++.h>
using namespace std;
#define M 45000000
const int fx[4][2][2]={{{-1,-1},{1,1}},
                       {{-1,0},{1,0}},
                       {{-1,1},{1,-1}},
                       {{0,-1},{0,1}}};
bool vis[M];
int tx,ty,ans;
int encode(int a[][4])
{
    int code=0,p=1;
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
        {
            code+=a[i][j]*p;
            p*=3;
        }
    return code;
}
void decode(int code,int a[][4])
{
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
        {
            a[i][j]=code%3;
            code/=3;
        }
}
bool check(int x,int y)
{
    return 0<=x&&x<4&&0<=y&&y<4;
}
bool win(int a[][4])
{
    for(int x=0;x<4;++x)
        for(int y=0;y<4;++y)
            if(a[x][y])
                for(int i=0;i<4;++i)
                {
                    int x1=x+fx[i][0][0],y1=y+fx[i][0][1];
                    int x2=x+fx[i][1][0],y2=y+fx[i][1][1];
                    if(check(x1,y1)&&check(x2,y2)&&a[x1][y1]&&a[x2][y2])
                    {
                        int cnt=2-a[x1][y1]+2-a[x][y]+2-a[x2][y2];
                        if(cnt==0||cnt==3)
                        {
//                            printf("%d %d %d %d %d %d %d %d ?\n",x,y,x1,y1,x2,y2,i,cnt);
                            return true;
                        }
                    }
                }
    return false;
}
void dfs(int code,int k)
{
    if(vis[code]) return;
    int a[4][4];
    decode(code,a);
//    for(int i=0;i<4;++i)
//    {
//        for(int j=0;j<4;++j)
//            printf("%d ",a[i][j]);
//        printf("\n");
//    }
//    printf("%d -------------\n",win(a));
    if(a[tx][ty])
    {
        if(a[tx][ty]==2&&win(a))
        {
            if(!vis[code]) ++ans;
        }
        vis[code]=true;
        return;
    }
    vis[code]=true;
    if(win(a)) return;
    for(int j=0;j<4;++j)
    {
        int i;
        for(i=0;i<4;++i)
            if(a[i][j]==0) break;
        if(i<4)
        {
            a[i][j]=k;
            int tmp=encode(a);
            dfs(tmp,3-k);
            a[i][j]=0;
        }
    }
}
int main()
{
    int y;
    scanf("%d",&y);
    scanf("%d%d",&tx,&ty);
    --y;--tx;--ty;
    int a[4][4];
    memset(a,0,sizeof(a));
    a[0][y]=1;
//    int code=encode(a);
//    printf("%d\n",code);
//    decode(code,a);
//    for(int i=0;i<4;++i)
//    {
//        for(int j=0;j<4;++j)
//            printf("%d ",a[i][j]);
//        printf("\n");
//    }
    ans=0;
    dfs(encode(a),2);
    printf("%d\n",ans);
    return 0;
}

