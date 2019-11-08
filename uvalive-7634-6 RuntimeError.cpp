
#pragma comment(linker,"/STACK:102400000,102400000")
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll mod=342307123;
char s[100010];
char xl[100010],xr[100010];
ll zq[100010];
ll cnt0[4][100010]; //00 01 10 11
ll cnt1[4][100010];
ll sum0[100010];
ll sum1[100010];
void cal(char* s,int g,int left,int right,ll& r0,ll& r1,bool ad){
//    printf("%d %d %s %d\n",left,right,s,g);
    if(g==0){
        if(ad){
            if(left==0)r0=(r0+1)%mod;else r1=(r1+1)%mod;
        }
        return;
    }
    if(s[0]=='D'){
        cal(&s[1],g-1,left,left^right,r0,r1,ad);
    }else{
        int add=left^right,id;
        if(left==0&&add==0)id=0;
        else if(left==0&&add==1)id=1;
        else if(left==1&&add==0)id=2;
        else if(left==1&&add==1)id=3;
        if(id<0||id>3)while(1);
//        printf("R %d\n",id);
        r0=(r0+cnt0[id][g-1])%mod;
        r1=(r1+cnt1[id][g-1])%mod;
//        printf("%lld %lld\n",r0,r1);
        cal(&s[1],g-1,add,right,r0,r1,ad);
    }
}
int main(){
    int cas=1;
    for(int i=1;i<100010;i++){
        if(i&1)zq[i]=zq[i-1]*2%mod;
        else zq[i]=(zq[i-1]*2+1)%mod;
    }
    cnt0[0][0]=cnt0[1][0]=1;
    cnt1[2][0]=cnt1[3][0]=1;
    for(int i=1;i<100010;i++){
        cnt0[0][i]=cnt0[0][i-1]*2%mod;

        cnt0[1][i]=(zq[i]+1)%mod;
        cnt1[1][i]=zq[i]*2%mod;
        if(i&1)cnt1[1][i]=(cnt1[1][i]+1)%mod;

        cnt0[2][i]=zq[i];
        if(i&1){
            cnt1[2][i]=(zq[i]*2+2)%mod;
        }else{
            cnt1[2][i]=(zq[i]*2+1)%mod;
        }

        if(i&1){
            cnt0[3][i]=(zq[i]+1)%mod;
            cnt1[3][i]=(zq[i]*2+1)%mod;
        }else{
            cnt0[3][i]=zq[i];
            cnt1[3][i]=(zq[i]*2+1)%mod;
        }
    }
//    for(int i=0;i<20;i++){
//        printf("%d ",cnt1[3][i]);
//    }
//    printf("\n");
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int g,l,r;
        scanf("%s%d%d%s%d%s",&s[1],&g,&l,xl,&r,xr);
        l++;r++;
        g--;
        int len=strlen(&s[1])+1;
        for(int i=1;i<len-1;i++){
            int id;
            if(s[i]=='0'&&s[i+1]=='0')id=0;
            else if(s[i]=='0'&&s[i+1]=='1')id=1;
            else if(s[i]=='1'&&s[i+1]=='0')id=2;
            else if(s[i]=='1'&&s[i+1]=='1')id=3;
            if(id<0||id>3)while(1);
            sum0[i]=(sum0[i-1]+cnt0[id][g])%mod;
            sum1[i]=(sum1[i-1]+cnt1[id][g])%mod;
          //  printf("%lld %lld\n",sum0[i],sum1[i]);
        }
        ll ans1=(sum1[r-1]-sum1[l-1])%mod,ans0=(sum0[r-1]-sum0[l-1])%mod;
//        printf("%lld %lld\n",ans0,ans1);
        ll r0=0,r1=0;
        if(r==len-1){
            if(s[len-1]=='0')r0++;
            else r1++;
        }else{
            cal(xr,g,s[r+1]-48,s[r]-48,r0,r1,true);
//            printf("r0=%lld r1=%lld\n",r0,r1);
        }
        ans1=(ans1+r1)%mod;
        ans0=(ans0+r0)%mod;
//        printf("%lld %lld\n",ans0,ans1);
        r0=0;r1=0;
        if(l!=len-1){
            cal(xl,g,s[l+1]-48,s[l]-48,r0,r1,false);
        }
        ans1=(ans1-r1)%mod;
        ans0=(ans0-r0)%mod;
        ans0=(ans0+mod)%mod;
        ans1=(ans1+mod)%mod;
        printf("Case %d: %lld %lld\n",cas++,ans0,ans1);
    }
    return 0;
}
/*
2
10010 4
0 DRR
1 RDD
01001 2
0 D
4 D
*/


