
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
bool use[20000010],ca[20000010];
int num[20000010];
int c1[20000010];
long long ans[20000010];
int main(){
    for(int i=2;i<20000010;i++)num[i]=i;
    for(int i=2;i<20000005;++i){
        if(!use[i]){
            for(int j=i;j<20000005;j+=i){
                if(!ca[j]){
                    use[j]=true;
                    num[j]/=i;
                    if(num[j]%i==0){
                        num[j]/=i;
                        if(num[j]%i==0)ca[j]=true;
                    }else{
                        c1[j]++;
                    }
                }
            }
        }
    }
    ans[1]=1;
    for(int i=2;i<20000005;++i){
        ans[i]=ans[i-1];
        if(!ca[i])ans[i]+=(1LL<<c1[i]);
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

