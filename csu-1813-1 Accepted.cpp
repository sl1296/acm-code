
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
const ll mod=1e9+7;
char a[4][1010][1010];
int pre[4][1010][1010];
int rr[4],cc[4],stak[1010],sn;
ll coun[4][1010][1010];
ll sum[4][1010][1010];
int main(){
    while(~scanf("%d%d",&rr[0],&cc[0])){
        memset(a,0,sizeof(a));
        for(int i=1;i<=rr[0];++i){
            scanf("%s",&a[0][i][1]);
        }
        for(int z=1,r=rr[0],c=cc[0];z<4;++z){
            for(int i=1;i<=r;++i){
                for(int j=1;j<=c;++j){
                    a[z][j][r-i+1]=a[z-1][i][j];
                }
            }
            swap(r,c);
            rr[z]=r;
            cc[z]=c;
        }
//        for(int z=0;z<4;++z){
//            printf("%d %d\n",rr[z],cc[z]);
//            for(int i=1;i<=rr[z];++i){
//                for(int j=1;j<=cc[z];++j){
//                    printf("%c",a[z][i][j]);
//                }
//                printf("\n");
//            }
//        }
        ll ans=0;
        for(int z=0;z<4;++z){
//            printf("pre:\n");
            for(int i=1;i<=rr[z];++i){
                for(int j=1;j<=cc[z];++j){
                    if(a[z][i][j]!='0'){
                        pre[z][i][j]=0;
                    }else{
                        pre[z][i][j]=pre[z][i-1][j]+1;
                    }
//                    printf("%d ",pre[z][i][j]);
                }
//                printf("\n");
            }
//            printf("coun:\n");
            for(int i=1;i<=rr[z];++i){
                sn=1;
                stak[0]=0;
                ll now=0;
                for(int j=1;j<=cc[z];++j){
                    while(sn>1 && pre[z][i][stak[sn-1]]>=pre[z][i][j]){
                        now=(now-(ll)pre[z][i][stak[sn-1]]*(stak[sn-1]-stak[sn-2])%mod+mod)%mod;
                        --sn;
                    }
                    now=(now+(ll)pre[z][i][j]*(j-stak[sn-1])%mod)%mod;
                    stak[sn++]=j;
                    coun[z][i][j]=now;
//                    printf("%lld ",coun[z][i][j]);
                }
//                printf("\n");
            }
            if(z<2){
//                printf("sum:\n");
                for(int i=1;i<=rr[z];++i){
                    for(int j=1;j<=cc[z];++j){
                        sum[z][i][j]=(coun[z][i][j]+sum[z][i-1][j]+sum[z][i][j-1]-sum[z][i-1][j-1]+mod)%mod;
//                        printf("%lld ",sum[z][i][j]);
                    }
//                    printf("\n");
                }
            }else{
                for(int i=1;i<rr[z];++i){
                    for(int j=1;j<=cc[z];++j){
                        ans=(ans+sum[z-2][i][cc[z]]*coun[z][rr[z]-i][j]%mod+mod-sum[z-2][i][j]*coun[z][rr[z]-i][cc[z]-j]%mod)%mod;
//                        printf("i=%d j=%d add=%lld dec=%lld ans=%lld\n",i,j,sum[z-2][i][cc[z]]*coun[z][rr[z]-i][j]%mod,sum[z-2][i][j]*coun[z][rr[z]-i][cc[z]-j]%mod,ans);
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

