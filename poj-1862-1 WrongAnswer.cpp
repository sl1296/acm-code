
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
double a[110];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%lf",&a[i]);
        }
        if(n==1){
            printf("%.3f\n",a[0]);
        }
        sort(a,a+n);
        double ans=2*sqrt(a[n-1]*a[n-2]);
        for(int i=n-3;i>=0;i--){
            ans=2*sqrt(ans*a[i]);
        }
        printf("%.3f\n",ans);
    }
    return 0;
}

