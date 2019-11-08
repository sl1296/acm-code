
#include <bits/stdc++.h>
using namespace std;
#define N 210
char g[N][N];
int main()
{
//    for(int n=2;n<=200;n+=2)
//        for(int m=2;m<=n;m+=2)
//            if(n+m-4<n+(m-2)/2)
//                printf("%d %d !\n",n,m);
    int ca,n,m;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        if(n%2==1&&m%2==1)
        {
            for(int i=1;i<=n;++i)
                for(int j=1;j<=m;++j)
                    g[i][j]='(';
        }
        else if(n%2==1)
        {
            for(int i=1;i<=n;++i)
                for(int j=1;j<=m;++j)
                    if(j&1) g[i][j]='(';
                    else g[i][j]=')';
        }
        else if(m%2==1)
        {
            for(int j=1;j<=m;++j)
                for(int i=1;i<=n;++i)
                    if(i&1) g[i][j]='(';
                    else g[i][j]=')';
        }
        else if(max(n,m)+(min(n,m)-2)/2>=n+m-4)
        {
            if(n>m)
            {
                for(int i=1;i<=n;++i)
                    for(int j=1;j<=m;++j)
                        if(i&1)
                        {
                            if((j==1||j%2==0)&&j!=m) g[i][j]='(';
                            else g[i][j]=')';
                        }
                        else
                        {
                            if(j&1) g[i][j]='(';
                            else g[i][j]=')';
                        }
            }
            else
            {
                for(int j=1;j<=m;++j)
                    for(int i=1;i<=n;++i)
                        if(j&1)
                        {
                            if((i==1||i%2==0)&&i!=n) g[i][j]='(';
                            else g[i][j]=')';
                        }
                        else
                        {
                            if(i&1) g[i][j]='(';
                            else g[i][j]=')';
                        }
            }
        }
        else
        {
            for(int i=1;i<=m;++i) g[1][i]='(';
            for(int i=2;i<=n;++i) g[i][1]='(';
            for(int i=2;i<=m;++i) g[n][i]=')';
            for(int i=2;i<n;++i) g[i][m]=')';
            for(int i=2;i<n;++i)
                for(int j=2;j<m;++j)
                    if(i&1)
                    {
                        if(j&1) g[i][j]=')';
                        else g[i][j]='(';
                    }
                    else
                    {
                        if(j&1) g[i][j]='(';
                        else g[i][j]=')';
                    }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
                printf("%c",g[i][j]);
            printf("\n");
        }
    }
    return 0;
}

