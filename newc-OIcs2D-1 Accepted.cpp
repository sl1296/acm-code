
#include<cstdio>
#define ll long long
int main(){
    ll n;
    scanf("%lld",&n);
    if(n<=0){
        printf("0\n");
    }else{
        ll s=1,e=1e9+5,mid;
        while(s<e){
            mid=e-(e-s)/2;
            if(mid*mid<=n){
                s=mid;
            }else{
                e=mid-1;
            }
        }
        printf("%lld\n",s);
    }
    return 0;
}

