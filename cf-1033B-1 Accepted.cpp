
#include<cstdio>
#define ll long long
bool ch(ll x){
    if(x<2)return false;
    for(ll i=2;i*i<=x;++i){
        if(x%i==0)return false;
    }
    return true;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll a,b;
        scanf("%I64d%I64d",&a,&b);
        if(a-b==1 && ch(a+b)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}

