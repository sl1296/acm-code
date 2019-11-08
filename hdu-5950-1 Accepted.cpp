
#include<bits/stdc++.h>
#define LL long long
const LL mod =2147493647;
const int n=7;
using namespace std;
struct jz{
    LL x[n][n];
};
LL s[10][10]={
{0, 1, 0, 0, 0, 0, 0},
{2, 1, 1, 4, 6, 4, 1},
{0, 0 ,1 ,4 ,6 ,4 ,1},
{0, 0 ,0 ,1, 3, 3, 1},
{0, 0, 0, 0, 1, 2, 1},
{0, 0, 0, 0, 0, 1, 1},
{0, 0, 0, 0, 0, 0, 1}
};

LL multi(LL a,LL b){
    LL ans=0;
    while(b){
        if(b&1){
            ans=(ans+a)%mod;
            b--;
        }
        b>>=1;
        a=(a+a)%mod;
    }
    return ans;
}
jz mul(jz a,jz b){
    int i,j,k;
    jz c;
    memset(c.x,0,sizeof(c.x));
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
	    if(a.x[i][k]==0)continue;
            for(j=0;j<n;j++){
                if(b.x[k][j]==0)continue;
                c.x[i][j]=(c.x[i][j]+multi(a.x[i][k],b.x[k][j]))%mod;
            }
        }
    }
    return c;
}
jz qpow(jz a,jz o,int x){
    int i,j;
    while(x){
        if(x&1)o=mul(o,a);
        x>>=1;
        a=mul(a,a);
    }
    return o;
}
jz one;
int main(){
    int t;
    scanf("%d",&t);
    jz x;
    for(int i=0;i<n;i++)one.x[i][i]=1;
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            x.x[i][j]=s[i][j];
        }
    }
    while(t--){
        int nn,a,b;
        scanf("%d%d%d",&nn,&a,&b);
        jz re=qpow(x,one,nn-2);
        LL tt[10]={a,b,16,8,4,2,1};
        LL ans=0;
        for(int i=0;i<7;i++){
            ans=(ans+multi(tt[i],re.x[1][i]))%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

