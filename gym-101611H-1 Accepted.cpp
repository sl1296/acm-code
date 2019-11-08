
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll T,n;
    int m;
    scanf("%lld%lld%d",&T,&n,&m);
    ll x=0,y=0,b,pb;
    int a,pa;
    bool flag=true;
    for(int i=0;i<m;i++){
        scanf("%d%lld",&a,&b);
        if(!flag) continue;
        if(!i){
            if(b>=a) x=(ll)(b-a+1+b)*a/2;
            else x=(ll)(1+b)*b/2;
            y=(ll)(b+a+b-1)*a/2;
        }else{
            int al=abs(a-pa),bl=abs(b-pb);
            if(bl>al) flag=false;
            else{
                bool z=false;
                if(b<pb){
                    swap(b,pb);
                    z=true;
                }
                int v=b+(al-bl)/2;
                y+=(ll)(pb+v)*(v-pb+1)/2+(ll)(b+v)*(v-b+1)/2;
                if((al-bl)%2==0) y-=v;
                v=pb-(al-bl)/2;
                if(v<=0){
                    x+=(ll)(1+pb)*pb/2+(ll)(1+b)*b/2;
                }else{
                    x+=(ll)(pb+v)*(pb-v+1)/2+(ll)(b+v)*(b-v+1)/2;
                    if((al-bl)%2==0) x-=v;
                }
                if(z) swap(b,pb);
            }
        }
        x-=b;y-=b;
        pa=a;pb=b;
    }
    y+=(ll)(2*pb+(n-pa))*(n-pa+1)/2;
    if(pb>n-pa){
        x+=(ll)(2*pb-(n-pa))*(n-pa+1)/2;
    }else{
        x+=(ll)(1+pb)*pb/2;
    }
    if(flag&&x<=T&&T<=y) printf("Yes\n");
    else printf("No\n");
    return 0;
}

