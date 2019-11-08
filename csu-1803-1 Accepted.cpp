
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const ll mod=12345654321LL;
/*1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,
 1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,
 50400,55440,83160,110880,166320,221760,277200,332640,498960,
 554400,665280,720720,1081080,1441440,2162160,2882880,3603600,
 4324320,6486480,7207200,8648640,10810800,14414400,17297280,
 21621600,32432400,36756720,43243200,61261200,73513440,110270160,
 122522400,147026880,183783600,245044800,294053760,367567200,
 551350800,698377680,735134400,1102701600,1396755360,2000000000*/
int zs[31650],zsn,fj[10],fjc[10],fjn,ys[1450],ysf[1450][10],ysn,df[10];
void dfs(int n,int num){
  //  printf(":%d %d\n",n,num);
    if(n==fjn-1){
        for(int i=0;i<=fjc[n];i++){
            for(int j=0;j<n;j++)ysf[ysn][j]=df[j];
            ysf[ysn][n]=i;
        /*    printf("%d\n",num);
            for(int j=0;j<fjn;j++)printf("%d ",ysf[ysn][j]);printf("\n");*/
            ys[ysn++]=num;
            num*=fj[n];
        }
    }else{
        for(int i=0;i<=fjc[n];i++){
            df[n]=i;
            dfs(n+1,num);
            num*=fj[n];
        }
    }
}
ll lcm(ll a,ll b){
    return a/__gcd(a,b)*b;
}
ll multi(ll a,ll b){
    ll ans=0;
    while(b){
        if(b&1){
            ans=(ans+a);
            b--;
        }
        b>>=1;
        a=(a+a);
    }
    return ans;
}
int main(){
 /*   double sum=0;
    for(int i=1;i<256;i++)sum+=1.0/i;*/
//    printf("%f\n",pow(2,3.35));
    ll a,b,c;
    for(int i=2;i<31650;i++)if(!zs[i])for(int j=i*i;j<31650;j+=i)zs[j]=1;
    for(int i=2;i<31650;i++)if(!zs[i])zs[zsn++]=i;
    //printf("zsn=%d\n",zsn);zsn=3404
    while(scanf("%lld%lld",&b,&c)!=EOF){
        a=2016;
        ll t=a;
        fjn=ysn=0;
        memset(fjc,0,sizeof(fjc));
        for(int i=0;i<zsn;i++){
            if(t%zs[i]==0){
                while(t%zs[i]==0){
                    t/=zs[i];
                    fjc[fjn]++;
                }
                fj[fjn++]=zs[i];
                if(t==1)break;
            }
        }
        if(t>1){
            fj[fjn]=t;
            fjc[fjn++]=1;
        }
     //   printf("%d\n",fjn);
     //   for(int i=0;i<fjn;i++)printf("%d %d\n",fj[i],fjc[i]);
        dfs(0,1);
     //   printf("ysn=%d\n",ysn);
    //    for(int i=0;i<ysn;i++)printf("%d ",ys[i]);
    //    printf("\n");
        ll ans=0;
        for(int i=0;i<ysn;i++){
       //     printf("i=%d %d\n",i,ys[i]);
            ll an=b/ys[i],bn=c/(a/ys[i]),ax[10];
            int axn=0;
            for(int j=0;j<fjn;j++)if(fjc[j]-ysf[i][j])ax[axn++]=ys[i]*fj[j];
      //      printf("%lld %lld %d\nax:",an,bn,axn);
        //    for(int j=0;j<axn;j++)printf("%lld ",ax[j]);printf("\n");
            for(int j=1;j<(1<<axn);j++){
          //      printf("j=%d\n",j);
                int d=0;
                ll tmp=1;
                for(int k=0;k<axn;k++){
                    if((1<<k)&j){
                        d++;
                        tmp=lcm(tmp,ax[k]);
                    }
                }
                if(d&1)an-=b/tmp;else an+=b/tmp;
              //  printf("tmp=%lld an=%lld\n",tmp,an);
            }
            ans=(ans+multi(an,bn));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
2016 32 63
2016 2016 2016
2016 1000000000 1000000000

1
30576
7523146895502644
*/

