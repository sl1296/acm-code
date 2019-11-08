
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9;
int D;
struct Matrix{
    ll a[1<<8][1<<8];
    void init()
    {
        memset(a,0,sizeof(a));
    }
    void E()
    {
        init();
        for(int i=0;i<D;++i)
            a[i][i]=1;
    }
}A,mat,ans_m,ans_p;
int fib[10];
inline void Add(ll &x,ll y)
{
    x+=y;
    if(x>=mod) x-=mod;
}
Matrix mul(Matrix &m1,Matrix &m2)
{
    ans_m.init();
    for(int i=0;i<D;++i)
        for(int j=0;j<D;++j)
            for(int k=0;k<D;++k)
                if(m1.a[i][k]&&m2.a[k][j])
                    Add(ans_m.a[i][j],m1.a[i][k]*m2.a[k][j]%mod);
    return ans_m;
}
Matrix Pow(Matrix &m,ll n)
{
    ans_p.E();
    while(n)
    {
        if(n&1) ans_p=mul(ans_p,m);
        m=mul(m,m);
        n>>=1;
    }
    return ans_p;
}
int main()
{
    fib[0]=fib[1]=1;
    for(int i=2;i<10;++i)
        fib[i]=fib[i-1]+fib[i-2];
    int n;
    ll m;
    scanf("%d%I64d",&n,&m);
    A.init();
    D=1<<n;
    int rev=(1<<n)-1;

    for(int s1=0;s1<D;++s1)
        for(int s2=0;s2<D;++s2)
            if((s1&(s2^rev))==s1)
            {
                int ss=s1|s2,cnt=0,tmp=1;
                for(int i=0;i<n;++i)
                    if((ss>>i)&1)
                    {
                        tmp*=fib[cnt];
                        cnt=0;
                    }
                    else ++cnt;
                tmp*=fib[cnt];
                A.a[s1][s2]=tmp;
            }
    mat.init();
    mat.a[0][0]=1;
    A=Pow(A,m);
    mat=mul(mat,A);
    printf("%I64d\n",mat.a[0][0]);
    return 0;
}

