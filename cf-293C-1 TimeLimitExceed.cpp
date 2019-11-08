
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int ys[100],ysn[100],ysc;
__int64 n,s;
__int64 ans;
void dfs(int i,__int64 x,__int64 y){
   // printf("%d %I64d %I64d\n",i,x,y);getchar();
    int j;
    if(i<ysc){
        for(j=0;j<=ysn[i];j++){
            ysn[i]-=j;
            dfs(i+1,x*floor(pow(ys[i],j)+0.5),y);
            ysn[i]+=j;
        }
    }else if(i<ysc*2){
        for(j=0;j<=ysn[i-ysc];j++){
            ysn[i-ysc]-=j;
        //    printf("%d %d:\n",ys[i-ysc],j);
            dfs(i+1,x,y*floor(pow(ys[i-ysc],j)+0.5));
            ysn[i-ysc]+=j;
        }
    }else{
        __int64 z=n/3/x/y;
        if(y<x || z<y)return;
        __int64 a=(x+y+z)/2-x;
        __int64 b=(x+y+z)/2-y;
        __int64 c=(x+y+z)/2-z;
        __int64 l,mod=1000000007;
        if(a<0 || b<0 || c<0)return;
        l=(a+b+c)%mod;
        if((a*a%mod*a%mod+b*b%mod*b%mod+c*c%mod*c%mod+n)%mod==l*l%mod*l%mod){
        //printf("%I64d %I64d %I64d\n",a,b,c);
            if(a==b && a==c)ans++;
            else if(a==b || a==c || b==c)ans+=3;
            else ans+=6;
        }
    }
}
int main(){
    __int64 i;
    scanf("%I64d",&n);
    s=n/3;
    for(i=2;i*i<=s;i++){
        if(s%i==0){
            ys[ysc]=i;
            ysn[ysc]++;
            s/=i;
            while(s%i==0){
                ysn[ysc]++;
                s/=i;
            }
            ysc++;
        //    printf("%I64d %I64d\n",ys[ysc-1],ysn[ysc-1]);
        }
    }
    if(s>1){
        ys[ysc]=s;
        ysn[ysc]++;
        ysc++;
    //*    printf("%I64d %I64d\n",ys[ysc-1],ysn[ysc-1]);
    }
    dfs(0,1,1);
    printf("%I64d\n",ans);
    return 0;
}

