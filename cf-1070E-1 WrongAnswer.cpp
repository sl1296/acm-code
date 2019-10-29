
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200010];
ll n,m,t;
ll cal(ll d){
    ll sum=0,now=0,cs=0,cnt=0;
    for(int i=0;i<n;++i){
        if(a[i]<=d){
            if(sum+a[i]>t)break;
            ++cnt;
            now+=a[i];
            sum+=a[i];
            ++cs;
            if(cs==m){
                cs=0;
                sum+=now;
                now=0;
            }
        }
    }
    return cnt;
}
int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        scanf("%lld%lld%lld",&n,&m,&t);
        ll mx=0;
        for(int i=0;i<n;++i){
            scanf("%lld",&a[i]);
            mx=max(mx,a[i]);
        }
        ll s=1,e=mx,mid;
        while(s<e){
            mid=e-(e-s)/2;
            ll sum=0,now=0,cs=0;
            bool ch=true;
            for(int i=0;i<n;++i){
                if(a[i]<=mid){
                    now+=a[i];
                    sum+=a[i];
                    ++cs;
                    if(cs==m){
                        cs=0;
                        sum+=now;
                        now=0;
                    }
                    if(sum>t){
                        ch=false;
                        break;
                    }
                }
            }
            if(ch)s=mid;
            else e=mid-1;
        }
        ll ka=cal(s);
        ll kb=cal(s+1);
        if(ka>kb){
            printf("%lld %lld\n",ka,s);
        }else{
            printf("%lld %lld\n",kb,s+1);
        }
    }
    return 0;
}
/*
4
5 2 16
5 6 1 4 7
5 3 30
5 6 1 4 7
6 4 15
12 5 15 7 20 17
1 1 50
100

3
11 1 29
6 4 3 7 5 3 4 7 3 5 3
7 1 5
1 1 1 1 1 1 1
5 2 18
2 3 3 7 5
*/

