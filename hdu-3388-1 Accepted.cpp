
#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int n,m,k;
int ys[100],ysn;
ll cal(ll x){
    ll r=0;
    for(int i=1;i<(1<<ysn);i++){
        ll bs=1;
        int cnt=0;
        for(int j=0;j<ysn;j++){
            if(i&(1<<j)){
                bs*=ys[j];
                cnt++;
            }
        }
        cnt=cnt&1?1:-1;
        r=r+x/bs*cnt;
    }
    return x-r;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        ysn=0;
        scanf("%d%d%d",&m,&n,&k);
        int tmp=m;
        for(int i=2;i*i<=tmp;i++){
            if(tmp%i==0){
                ys[ysn++]=i;
                do{
                    tmp/=i;
                }while(tmp%i==0);
            }
        }
        if(tmp>1)ys[ysn++]=tmp;
        tmp=n;
        for(int i=2;i*i<=tmp;i++){
            if(tmp%i==0){
                ys[ysn++]=i;
                do{
                    tmp/=i;
                }while(tmp%i==0);
            }
        }
        if(tmp>1)ys[ysn++]=tmp;
        sort(ys,ys+ysn);
        tmp=0;
        for(int i=0;i<ysn;i++){
            while(i+1<ysn&&ys[i]==ys[i+1])i++;
            ys[tmp++]=ys[i];
        }
        ysn=tmp;
        ll s=1,e=1LL<<62,m;
        ll ans=-1;
        while(e-s>0){
            m=s+(e-s)/2;
            ll r=cal(m);
            if(r==k){
                if(cal(m-1)==k)e=m-1;else{
                    ans=m;
                    break;
                }
            }else if(r>k){
                e=m-1;
            }else{
                s=m+1;
            }
        }
        if(ans==-1)ans=s;
        printf("Case %d: %lld\n",z,ans);
    }
    return 0;
}

