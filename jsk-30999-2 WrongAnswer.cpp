
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
//bool use[20000010],ca[20000010];
//int num[20000010];
//int c1[20000010];
bool use[20000010];
ll cal[20000010];
ll prime[20000010],tot;
ll ans[20000010];
int main(){
    cal[1]=1;
    for(ll i=2;i<20000010;++i){
//        if(i>7750)printf("i=%lld\n",i);
        if(!use[i]){
            prime[tot++]=i;
            cal[i]=2;
            if(i*i<20000010)cal[i*i]=1;
//            if(i>7750)printf("f:%lld %d %lld %d\n",i,2,i*i,1);
        }
//        if(i>7750)printf("cal=%lld\n",cal[i]);
        for(ll j=0;j<tot;++j){
            ll ka=i*prime[j];
//            if(i>7750)printf("j=%lld ka=%lld %lld\n",j,ka,prime[j]);
            if(ka<20000010){
                use[ka]=true;
                if(cal[i] && i%prime[j]){
                    cal[ka]=cal[i]*2;
//                    if(i>7750)printf("f:%lld %lld\n",ka,cal[i]*2);
                    ka*=prime[j];
                    if(ka<20000010){
                        cal[ka]=cal[i];
//                        if(i>7750)printf("f:%lld %lld\n",ka,cal[i]);
                    }
                }else{
                    break;
                }
            }else{
                break;
            }
        }
    }
//    for(int i=2;i<20000010;i++)num[i]=i;
//    for(int i=2;i<20000005;++i){
//        if(!use[i]){
//            for(int j=i;j<20000005;j+=i){
//                if(!ca[j]){
//                    use[j]=true;
//                    num[j]/=i;
//                    if(num[j]%i==0){
//                        num[j]/=i;
//                        if(num[j]%i==0)ca[j]=true;
//                    }else{
//                        c1[j]++;
//                    }
//                }
//            }
//        }
//    }
    ans[1]=1;
    for(int i=2;i<20000005;++i){
        ans[i]=ans[i-1]+cal[i];
//        if(!ca[i])ans[i]+=(1LL<<c1[i]);
//        printf("%lld\n",ans[i]);
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}

