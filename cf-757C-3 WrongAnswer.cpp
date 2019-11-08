
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int x[1000010];
int cc[1000010];
int cnum;
int in[100010];
ll mod=1e9+7;
ll jc[1000010];
struct po{
    int type,num;
    bool operator < (const po &p) const{
        if(p.num==num)return x[p.type]<x[type];
        return p.num<num;
    }
};
po inn[100010];
int cnt;
int t;
int main(){
    int n,m;
    jc[1]=1;
    for(ll i=2;i<1000002;i++)jc[i]=(jc[i-1]*i)%mod;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int g;
        scanf("%d",&g);
        for(int i=0;i<g;i++)scanf("%d",&in[i]);
        sort(in,in+g);
        int now=-2;
        cnt=0;
        for(int i=0;i<g;i++){
            if(in[i]!=now){
                now=inn[cnt].type=in[i];
                inn[cnt].num=1;
                cnt++;
            }else{
                inn[cnt-1].num++;
            }
        }
        sort(inn,inn+cnt);
        now=-2;
        int bef=-2;
        for(int i=0;i<cnt;i++){
            if(inn[i].num==now && x[inn[i].type]==bef){
                x[inn[i].type]=t;
            }else{
                t++;
                now=inn[i].num;
                bef=x[inn[i].type];
                x[inn[i].type]=t;
            }
        }
    }
   // for(int i=1;i<=m;i++)printf("%d ",x[i]);
   // printf("\n");
    sort(x,x+m);
   // for(int i=1;i<=m;i++)printf("%d ",x[i]);
   // printf("\n");
    int nnn=-1;
    for(int i=1;i<=m;i++){
        if(x[i]==nnn){
            cc[cnum-1]++;
        }else{
            nnn=x[i];
            cc[cnum]=1;
            cnum++;
        }
    }
   // for(int i=0;i<cnum;i++)printf("%d ",cc[i]);
   // printf("\n");
    ll ans=1;
    for(int i=0;i<cnum;i++)ans=(ans*jc[cc[i]])%mod;
    printf("%lld\n",ans);
    return 0;
}

