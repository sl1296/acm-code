
#include<cstdio>
#include<cstring>
#define ll long long
int n,k;
struct jz{
    ll x[35][35];
};
jz one;
jz mul(jz a,jz b){
    int i,j,k;
    jz c;
    memset(c.x,0,sizeof(c.x));
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
        if(a.x[i][k]==0)continue;
            for(j=0;j<n;j++){
                if(b.x[k][j]==0)continue;
                c.x[i][j]=c.x[i][j]+a.x[i][k]*b.x[k][j];
            }
        }
    }
    return c;
}
jz qpow(jz a,jz o,int x){
    while(x){
        if(x&1)o=mul(o,a);
        x>>=1;
        a=mul(a,a);
    }
    return o;
}
int main(){
    scanf("%d%d",&n,&k);
    memset(one.x,0,sizeof(one.x));
    for(int i=0;i<n;i++)one.x[i][i]=1;
    jz s;
    memset(s.x,0,sizeof(s.x));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%lld",&s.x[i][j]);
        }
    }
    s=qpow(s,one,k);
    printf("%lld\n",s.x[n-1][0]);
    return 0;
}

