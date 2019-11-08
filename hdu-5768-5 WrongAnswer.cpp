
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll __int64
ll m[20],a[20],r,M;
int n;
__int64 exgcd(__int64 a,__int64 b,__int64 &x,__int64 &y){
    if (b==0){
        x=1,y=0;
        return a;
    }
    __int64 q=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return q;
}
__int64 c1(int xx){
    __int64 i,Mi,sum=0,x,y;
    M=7;
    for(i=0;i<n;i++)if(xx&(1<<i))M*=m[i];
    for(i=0;i<n;i++){
        if(xx&(1<<i)){
            Mi=M/m[i];
            exgcd(Mi,m[i],x,y);
            sum=(sum+x*Mi*a[i])%M;
        }
    }
    return (sum+M)%M;
}
__int64 c(__int64 x){
    __int64 ans=x/7,r;
    int i,j,k,k2,l;
    for(i=1;i<1<<n;i++){
        k=0;k2=1;
      //  printf("%d ",i);
        for(j=0;j<n;j++){
            if(i&(1<<j)){
                k++;
                for(l=j+1;l<n;l++){
                    if(i&(1<<l) && m[j]==m[l]){
                        k2=0;
                        break;
                    }
                }
            }
        }
        if(!k2)continue;
        if(k&1)k=-1; else k=1;
        r=c1(i);
        r=x/M+(x%M>=r?1:0);
   //     printf(" %d\n",r);
        ans=ans+r*k;
    }
    return ans;
}
int main(){
    int t,z,i,j,k;
    ll x,y,r;
    scanf("%d",&t);
    for(z=1;z<=t;z++){
        scanf("%d%I64d%I64d",&n,&x,&y);
        for(i=0;i<n;i++)scanf("%I64d%I64d",&m[i],&a[i]);
      //  for(i=0;i<n;i++)printf("%I64d %I64d\n",m[i],a[i]);
       for(i=0;i<n;i++){
            for(j=i+1;j<n;j++)
        if(m[i]==m[j] && a[i]==a[j]){
            for(k=j+1;k<n;k++){
                printf("%d:%d ",i,k);
                m[k-1]=m[k];
                a[k-1]=a[k];
            }
            j--;
            n--;
        }

        //for(j=0;j<n;j++)printf("%d %d\n",m[j],a[j]);
        }
        //for(i=0;i<n;i++)printf("%d %d\n",m[i],a[i]);
        r=c(y)-c(x-1);
        printf("Case #%d: %I64d\n",z,r);
    }
    return 0;
}

