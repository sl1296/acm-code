
#include<cstdio>
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;++z){
        int a,b,c,d,e,n,x;
        long long sum=0;
        scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&n);
        for(int i=0;i<n;++i){
            scanf("%d",&x);
            if(x<49){
                sum+=a;
            }else if(x<57){
                sum+=b;
            }else if(x<61){
                sum+=c;
            }else if(x<63){
                sum+=d;
            }else{
                sum+=e;
            }
        }
        printf("Case #%d: %lld0000\n",z,sum);
    }
    return 0;
}

