
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll a,b,c,x,y,z;
        scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&x,&y,&z);
        ll aa=x*c+y*a+z*b-x*b-y*c-z*a;
        ll bb=a+b+c;
        ll gcd=__gcd(aa>=0?aa:-aa,bb);
        aa/=gcd;bb/=gcd;
        if(bb==1){
            printf("%lld\n",aa);
        }else{
            printf("%lld/%lld\n",aa,bb);
        }
    }
    return 0;
}

