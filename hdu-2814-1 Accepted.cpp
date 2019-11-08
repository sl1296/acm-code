
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef unsigned long long LL;
int c;
LL a,b,n;
LL f[5500];
int search(int c){
    int loop;
    f[0]=0;f[1]=1;
    for(int i=2;i<2005;i++){
        f[i]=(f[i-1]%c+f[i-2]%c)%c;
        if(f[i]==1&&f[i-1]==0){
            loop=i;
            break;
        }
    }
    return loop-1;
}
int phi(int n){
    int rea=n,i;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            rea=rea-rea/i;
            while(n%i==0) n/=i;
        }
    }
    if(n>1)rea=rea-rea/n;
    return rea;
}
LL multi(LL a,LL b,LL m){
    LL ans=0;
    while(b){
        if(b&1){
            ans=(ans+a)%m;
            b--;
        }
        b>>=1;
        a=(a+a)%m;
    }
    return ans;
}
LL quick_mod(LL a,LL b,LL m){
    LL ans=1;
    a%=m;
    while(b){
        if(b&1){
            ans=multi(ans,a,m);
            b--;
        }
        b>>=1;
        a=multi(a,a,m);
    }
    return ans;
}
int main(){
    int t,tt=1;
    LL tmp1,tmp2;
    LL t1,t2;
    scanf("%d",&t);
    while(t--){
        scanf("%I64u%I64u%I64u%d",&a,&b,&n,&c);
        printf("Case %d: ",tt++);
        if(c==1){
            printf("0\n");
            continue;
        }
        int p=phi(c);
        int loop1=search(c);
        t1=quick_mod(a,b,loop1);
        tmp1=f[t1]%c;
        int loop2=search(p);
        t2=quick_mod(a,b,loop2);
        tmp2=f[t2]%p;
        tmp2=quick_mod(tmp2,n-1,p);
        tmp2+=p;
        tmp1=quick_mod(tmp1,tmp2,c);
        printf("%I64u\n",tmp1);
    }
    return 0;
}

