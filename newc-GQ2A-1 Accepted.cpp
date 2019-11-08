
#include <bits/stdc++.h>
using namespace std;
#define N 5000
#define P 70
typedef unsigned long long ull;
int const mod=10007;
int n,p,m;
int a[N][P],sum[N],to[mod];
int c[2][N][P],num[2][N];
ull b[N];
int bit[N];
char st[P];
int calc(int x,int y,int k)
{
    int ans=0;
    for(int i=1;i<=num[k][y];++i)
        ans+=a[x][c[k][y][i]];
    return ans;
}
int change(char c)
{
    if('0'<=c&&c<='9') return c-'0';
    else return c-'A'+10;
}
int main()
{
    scanf("%d%d%d",&n,&p,&m);
    for(int i=0;i<n;++i)
        for(int j=0;j<p;++j)
        {
            scanf("%x",&a[i][j]);
            sum[i]+=a[i][j];
        }
    for(int i=0;i<m;++i)
    {
        scanf("%s",st);
        bit[i]=0;
        for(int j=0;j<p;++j)
        {
            int x=st[j]-'0';
            b[i]|=(ull)x<<j;
            ++num[x][i];
            c[x][i][num[x][i]]=j;
        }
    }
    // for(int i=0;i<m;++i)
    // {
    //     printf("%d %d %d ?\n",i,num[0][i],num[1][i]);
    //     for(int j=1;j<=num[0][i];++j) printf("%d ",c[0][i][j]);
    //     printf("\n");
    //     for(int j=1;j<=num[1][i];++j) printf("%d ",c[1][i][j]);
    //     printf("\n");
    // }
    int ans=0,z=p/2;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(num[0][j]<=z)
            {
                ans^=sum[i]-calc(i,j,0);
            }
            else
            {
                ans^=calc(i,j,1);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

