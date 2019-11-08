
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
const double f=(sqrt(5.0)+1)/2.0;
int fac[21]={0,1,1};
int main(){
    int n;
    for(int i=3;i<=20;i++)fac[i]=fac[i-1]+fac[i-2];
    while(scanf("%d",&n)!=EOF){
        if(n<=20){
            printf("%d\n",fac[n]);
            continue;
        }
        double ans=-0.5*log(5.0)/log(10.0)+n*log(f)/log(10.0);
        ans-=floor(ans);
        ans=pow(10.0,ans);
        int ans1=int(ans*1000);
        printf("%d\n",ans1);
    }
    return 0;
}

