
#include<cstdio>
#define ll long long
#define N 40000001
int phi[N],prim[N];
ll ans[20000001];
int main(){
    phi[1]=1;
    int id=0;
    for(int i=2;i<N;++i){
        if(!phi[i]){
            phi[i]=i-1;
            prim[id++]=i;
        }
        for(int j=0;j<id&&prim[j]*i<N;++j){
            if(i%prim[j]){
                phi[i*prim[j]]=phi[i]*(prim[j]-1);
            }else{
                phi[i*prim[j]]=phi[i]*prim[j];
                break;
            }
        }
    }
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w+",stdout);
    for(int i=1;i<20000001;++i){
        ans[i]=ans[i-1]+(phi[i<<1]>>1);
    }
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}

