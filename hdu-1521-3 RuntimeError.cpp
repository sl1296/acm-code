
#include <iostream>
#include <cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int inf=10056;
const int maxn=1005;
int  a[15],b[15];
int sum=0;
int n,m;
int jie(int x)
{
    int s=1;
    for(int i=2;i<=x;i++)
        s=s*i;
    return s;
}
void DFS(int x,int y)
{
    if(x==(n-1)&&y+a[n-1]<m)
        return ;
    for(int i=0;i<=a[x];i++)
    {
        y=y+i;
        b[x]=i;
        if(y==m)
        {
            int q=jie(m);
            for(int i=0;i<=x;i++)
            {
                if(b[i]>0)
                    q=q/jie(b[i]);
            }

            sum+=q;
            return ;
        }
        if(y<m)
            DFS(x+1,y+i);
    }

}

void cal()
{

    sum=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    DFS(0,0);
    cout<<sum<<endl;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF)cal();
    return 0;
}

