
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define N 100
#define M 20
const int inf=0x3f3f3f3f;
char g[N][M];
int people[N],d[N];
int Left,Right,c,e1,e2,e3;
int n,m;
bool doing1(int i,int x,int y)
{
    if(g[i][x]!='-'&&g[i][y]!='-') return false;
    if(g[i][x]=='-'&&g[i][y]=='-')
    {
        if(Left<=Right)
        {
            g[i][x]=c+'a';Left++;
        }
        else
        {
            g[i][y]=c+'a';Right++;
        }
    }
    else if(g[i][x]=='-')
    {
        g[i][x]=c+'a';Left++;
    }
    else
    {
        g[i][y]=c+'a';Right++;
    }
    return true;
}
bool doing2(int i,int x)
{
    if(g[i][x]=='-')
    {
        g[i][x]=c+'a';
        return true;
    }
    else return false;
}
bool doing3(int x,int y)
{
    if(g[e1+1][x]!='-'&&g[e2+1][x]!='-'&&g[e1+1][y]!='-'&&g[e2+1][y]!='-') return false;
    if((g[e1+1][x]=='-'||g[e2+1][x]=='-')&&(g[e1+1][y]=='-'||g[e2+1][y]=='-'))
    {
        if(left<=right)
        {
            if(g[e1+1][x]=='-') g[e1+1][x]=c+'a';
            else g[e2+1][x]=c+'a';
        }
        else
        {
            if(g[e1+1][y]=='-') g[e1+1][y]=c+'a';
            else g[e2+1][y]=c+'a';
        }
    }
    else if(g[e1+1][x]=='-'||g[e2+1][x]=='-')
    {
        if(g[e1+1][x]=='-') g[e1+1][x]=c+'a';
        else g[e2+1][x]=c+'a';
    }
    else
    {
        if(g[e1+1][y]=='-') g[e1+1][y]=c+'a';
        else g[e2+1][y]=c+'a';
    }
}
bool doing4(int x)
{
    if(g[e1+1][x]=='-')
    {
        g[e1+1][x]=c+'a';return true;
    }
    else if(g[e2+1][x]=='-')
    {
        g[e2+1][x]=c+'a';return true;
    }
    return false;
}
void doing(int row)
{
//    if(doing3(4,6)) return true;
//    else if(doing3(2,8)) return true;
//    else if(doing3(0,10)) return true;
//    else if(doing4(5)) return true;
//    else if(doing3(1,9)) return true;
//    return false;
    if(doing1(row,4,6));
    else if(doing1(row,2,8));
    else if(doing1(row,0,10));
    else if(doing2(row,5));
    else if(doing1(row,1,9));
    ++people[row];
}

int main()
{
    scanf("%d%d",&n,&m);
    e1=1;e2=n/2+2;e3=n+3;
    for(int i=1;i<=n+3;++i)
    {
        scanf("%s",g[i]);
        if(i==e1||i==e2||i==e3) continue;
        for(int j=0;j<=10;++j)
        {
            if(g[i][j]=='#')
            {
                ++people[i];
                if(j<5) ++Left;
                if(j>5) ++Right;
            }
        }
        d[i]=min(abs(i-e1),min(abs(i-e2),abs(i-e3)));
    }
    for(c=0;c<m;++c)
    {
        pii p={inf,inf};
        int row;
        if(people[e1+1]<9||people[e2+1]<9)
        {
            if(people[e1+1]<=people[e2+1])
                doing(e1+1);
            else doing(e2+1);
            continue;
        }
        for(int i=1;i<=n+3;++i)
        {
            if(i==e1||i==e2||i==e3) continue;
            pii tmp={people[i],d[i]};
            if(tmp<p)
            {
                p=tmp;row=i;
            }
        }
        doing(row);
//        if(doing1(row,4,6));
//        else if(doing1(row,2,8));
//        else if(doing1(row,0,10));
//        else if(doing2(row,5));
//        else if(doing1(row,1,9));
    }
    for(int i=1;i<=n+3;++i)
        puts(g[i]);
    return 0;
}
/*
2 17
...........
---.#--.---
...........
---.---.---
...........

6 26
...........
---.---.###
#-#.---.---
---.###.---
...........
---.###.---
#--.#-#.--#
#--.--#.#-#
...........
*/

