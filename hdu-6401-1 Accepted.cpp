
#include <bits/stdc++.h>
using namespace std;
char g[10][10];
void Rotate(int z,char c)
{
    int x,y;
    if(z==1) {x=0;y=0;}
    else if(z==2) {x=0;y=1;}
    else if(z==3) {x=1;y=0;}
    else {x=1;y=1;}
    if(c=='C')
    {
        char tmp=g[x][y];
        g[x][y]=g[x+1][y];
        g[x+1][y]=g[x+1][y+1];
        g[x+1][y+1]=g[x][y+1];
        g[x][y+1]=tmp;
    }
    else
    {
        char tmp=g[x][y];
        g[x][y]=g[x][y+1];
        g[x][y+1]=g[x+1][y+1];
        g[x+1][y+1]=g[x+1][y];
        g[x+1][y]=tmp;
    }
}
int main()
{
    int ca,n;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        for(int i=0;i<3;++i)
            scanf("%s",g[i]);
        char st[10];
        for(int i=1;i<=n;++i)
        {
            scanf("%s",st);
            Rotate(st[0]-'0',st[1]);
        }
        for(int i=0;i<3;++i)
        {
            printf("%s\n",g[i]);
        }
    }
    return 0;
}

