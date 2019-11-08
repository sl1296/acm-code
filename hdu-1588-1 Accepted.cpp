
#include <stdio.h>
#define ll __int64
typedef struct jz{
    ll x[2][2];
}jz;
jz one,f;
int mod;
jz mul(jz a,jz b){
    int i,j,k;
    jz c;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            c.x[i][j]=0;
            for(k=0;k<2;k++){
                c.x[i][j]=(c.x[i][j]+a.x[i][k]*b.x[k][j])%mod;
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
jz add(jz a,jz b){
    int i,j;
    for(i=0;i<2;i++)for(j=0;j<2;j++)a.x[i][j]=(a.x[i][j]+b.x[i][j])%mod;
    return a;
}
jz sumdb(jz s,jz o,int k){
    if(k==1)return s;
    o=add(o,qpow(s,one,k>>1));
    o=mul(o,sumdb(s,one,k>>1));
    if(k&1)o=add(o,qpow(s,one,k));
    return o;
}
int main(){
    int k,b,n;
    jz re;
    one.x[0][0]=one.x[1][1]=1;
    f.x[0][0]=f.x[0][1]=f.x[1][0]=1;
    while(scanf("%d%d%d%d",&k,&b,&n,&mod)!=EOF){
        re=mul(add(one,sumdb(qpow(f,one,k),one,n-1)),qpow(f,one,b));
        printf("%I64d\n",re.x[0][1]);
    }
    return 0;
}

