
#include<cstdio>
using namespace std;
#define ll unsigned long long
int main(){
    ll a,b,c,d;
    int t;
    ll pd=1LL<<62;
//    printf("%llu",pd);
    scanf("%d",&t);
    while(t--){
        scanf("%llu%llu%llu%llu",&a,&b,&c,&d);
        ll s=a+b+c+d;
        if(a==pd && b==pd && c==pd && d==pd){
            printf("18446744073709551616\n");
        }else{
            printf("%llu\n",s);
        }
    }
    return 0;
}

