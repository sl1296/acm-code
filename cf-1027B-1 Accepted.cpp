
#include<cstdio>
#define ll long long
int main(){
    ll n,q;
    scanf("%I64d%I64d",&n,&q);
    while(q--){
        ll x,y;
        scanf("%I64d%I64d",&x,&y);
        if((x+y)&1){
            if(n&1){
                if(x&1){
                    printf("%I64d\n",n*n/2+1+(x-1)/2*n+(y+1)/2);
                }else{
                    printf("%I64d\n",n*n/2+1+(x-2)/2*n+n/2+(y+1)/2);
                }
            }else{
                printf("%I64d\n",n*n/2+(x-1)*(n/2)+(y+1)/2);
            }
        }else{
            if(n&1){
                if(x&1){
                    printf("%I64d\n",(x-1)/2*n+(y+1)/2);
                }else{
                    printf("%I64d\n",(x-2)/2*n+n/2+1+(y+1)/2);
                }
            }else{
                printf("%I64d\n",(x-1)*(n/2)+(y+1)/2);
            }
        }
    }
}

