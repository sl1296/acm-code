
#include <bits/stdc++.h>
using namespace std;
#define N 4000
#define M 2000
int c[N+10][N+10],a[N+10][N+10],b[N+10][N+10];
int main()
{
    int n;
    scanf("%d",&n);
    char st[3];
    int x,y,z;
    for(int i=1;i<=n;++i)
    {
        scanf("%s%d%d%d",st,&x,&y,&z);
        x+=M;y+=M;z/=2;
        if(st[0]=='A')
        {
            a[x-z][y-z]++;a[x+z][y+z]++;
            a[x-z][y+z]--;a[x+z][y-z]--;
        }
        else
        {
            b[x-z][y]++;b[x+z][y]++;
            b[x][y-z]--;b[x][y+z]--;
        }
    }
    for(int i=1;i<=N;++i)
        for(int j=1;j<=N;++j)   
        {
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            if(a[i][j]) c[i][j]|=15;
        }
    for(int i=1;i<=N;++i)
        for(int j=1;j<N;++j)
        {
            b[i][j]+=b[i-1][j-1]+b[i-1][j+1];
            if(i>=2) b[i][j]-=b[i-2][j];
            if(b[i][j])
            {
                c[i][j-1]|=6;
                c[i][j]|=12;
                c[i+1][j-1]|=3;
                c[i+1][j]|=9;
            }
        }
    int ans=0;
    for(int i=0;i<=N;++i)
        for(int j=0;j<=N;++j)
            for(int k=0;k<4;++k)
                if((c[i][j]>>k)&1) ++ans;
    printf("%.2f\n",ans/4.0);
    return 0;
}
/*
2
A 0 0 2
B 1 0 2      

8
A -7 10 4
B 3 10 8
A -6 6 6
A -2 5 8
B 3 -1 8
B -7 -4 8
A 3 9 2
B 8 6 6
*/

