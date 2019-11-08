
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll __int64
#define mod 10000007
typedef struct jz{
    ll x[2][2];
}jz;
jz f,one,r;
jz mul(jz a,jz b){
    int i,j,k;
    jz c;
    memset(c.x,0,sizeof(c.x));
    for(k=0;k<2;k++){
        for(i=0;i<2;i++){
	    if(a.x[i][k]==0)continue;
            for(j=0;j<2;j++){
                if(b.x[k][j]==0)continue;
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
int a[100100];
int main(){
    __int64 ans;
    int n,k,max1,max2,i;
    one.x[0][0]=one.x[1][1]=f.x[0][0]=f.x[0][1]=f.x[1][0]=1;
    while(scanf("%d%d",&n,&k)!=EOF){
        ans=0;max1=max2=-1;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]>max1){
                max2=max1;
                max1=a[i];
            }else if(a[i]>max2){
                max2=a[i];
            }
        }
        if(k==1){
            ans=(max1+max2)%mod;
        }else{
            r=sumdb(f,one,k-1);
            ans=(r.x[0][0]+1)*max2%mod;
            r=sumdb(f,one,k);
            ans=(ans+r.x[0][0]*max1)%mod;
        }
        for(i=0;i<n;i++)ans=(ans+a[i])%mod;
        printf("%I64d\n",ans);
    }
    return 0;
}

