
#include <bits/stdc++.h>
using namespace std;
#define N 20
#define M 400010
struct Hash{
    const static int mod=(1<<17)-1;
    int head[mod+1],val[M],pre[M],e;
    void init()
    {
        memset(head,-1,sizeof(head));
        e=0;
    }
    bool insert(int x)
    {
        int h=x&mod;
        for(int i=head[h];i!=-1;i=pre[i])
            if(val[i]==x) return false;
        val[e]=x;pre[e]=head[h];head[h]=e++;
        assert(e<M);
        return true;
    }
}ha;
int a[N];
int n,k,minn,maxx,mi,mx;
int que[M],step[M],nn[20];
int get_bit(int x,int a[])
{
    int t=0;
    while(x)
    {
        a[++t]=x%10;
        x/=10;
    }
    return t;
}
int get_num(int a[],int t)
{
    int x=0;
    for(int i=t;i>0;--i)
        x=x*10+a[i];
    return x;
}
void bfs(int x,int m)
{
    int s=0,t=0;
    ha.init();
    que[s]=x;step[s]=0;
    ha.insert(x);
    minn=maxx=x;
    while(s<=t)
    {
        int x=que[s],z=step[s];++s;
        if(z==m) continue;
        int len=get_bit(x,a);
        for(int i=1;i<=len;++i)
            for(int j=i+1;j<=len;++j)
            {
                if(a[i]==a[j]||(j==len&&a[i]==0)) continue;
                int y=x-a[i]*nn[i]-a[j]*nn[j]+a[i]*nn[j]+a[j]*nn[i];
                if(ha.insert(y))
                {
                    ++t;que[t]=y;step[t]=z+1;
                    minn=min(minn,y);
                    maxx=max(maxx,y);
                    if(minn==mi&&maxx==mx) return;
                }
            }
    }
}
int main()
{
    nn[1]=1;
    for(int i=2;i<=10;++i) nn[i]=nn[i-1]*10;
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&k);
        int len=get_bit(n,a);
        sort(a+1,a+len+1,greater<int>());
        for(int j=len;j>0;--j)
            if(a[j]!=0)
            {
                swap(a[len],a[j]);
                break;
            }
//        for(int i=len;i>0;--i) printf("%d",a[i]);
//        printf("\n");
        mi=get_num(a,len);
        len=get_bit(n,a);
        sort(a+1,a+len+1,less<int>());
//        for(int i=len;i>0;--i) printf("%d",a[i]);
//        printf("\n");
        mx=get_num(a,len);
        if(k>=len-1)
        {
            minn=mi;maxx=mx;
//            printf("ok\n");
        }
        else bfs(n,k);
        printf("%d %d\n",minn,maxx);
    }
    return 0;
}
/*
100
12 1
213 2
998244353 1
998244353 2
998244353 3
102345813 8
102345813 7
102345813 6
102345813 5
102345813 4
102345813 3
*/

