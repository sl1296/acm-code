
#include<cstdio>
#define ll long long
int main(){
    int n,t,a;
    scanf("%d%d",&n,&t);
    ll now=0,add=0;
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        if(a>=add){
            add=a;
            if(t<=now){
                printf("1\n");
            }else{
                printf("%lld\n",(t-now)/add+1);
            }
            now+=a;
        }else{
            if(t<now+a){
                printf("1\n");
            }else{
                printf("%lld\n",(t-now-a)/add+2);
            }
            now+=a;
        }
    }
    return 0;
}

