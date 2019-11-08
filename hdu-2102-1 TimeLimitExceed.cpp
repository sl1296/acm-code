
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;
struct no
{
    int c,x,y;
};
queue<no> qu;
int xx[5]={1,-1,0,0};
int yy[5]={0,0,1,-1};
char map[3][15][15];
bool is[3][15][15];
int main()
{
    int x,y,t,i,j,k,ti;
    no ls,ad;
    bool exit;
    scanf("%d",&ti);
    while(ti--)
    {
        scanf("%d%d%d",&x,&y,&t);
        exit=false;
        memset(map,0,sizeof(map));
        memset(is,false,sizeof(is));
        while(!qu.empty())qu.pop();
        for(i=0;i<2;i++)
        {
            for(j=1;j<=x;j++)
            {
                scanf("%s",map[i][j]);
            }
        }
        ls.c=0;
        ls.x=ls.y=1;
        qu.push(ls);
        while(!qu.empty())
        {
            ls=qu.front();
            qu.pop();
            is[ls.c][ls.x][ls.y]=true;
            for(i=0;i<4;i++)
            {
                ad.c=ls.c;
                ad.x=ls.x+xx[i];
                ad.y=ls.y+yy[i];
                if(is[ad.c][ad.x][ad.y])continue;
                if(map[ad.c][ad.x][ad.y]=='.')
                {
                    qu.push(ad);
                }else if(map[ad.c][ad.x][ad.y]=='#')
                {
                    ad.c=(ad.c+1)%2;
                    qu.push(ad);
                }else if(map[ad.c][ad.x][ad.y]=='P')
                {
                    exit=true;
                    break;
                }
            }
            if(exit)break;
        }
        if(exit)printf("YES\n"); else printf("NO\n");
    }
    return 0;
}

