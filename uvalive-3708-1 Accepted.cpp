
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        double ans=0;
        int tmp=n+m;
        for(int i=0;i<n;i++){
            double pos=(double)i/n*tmp;
            ans+=fabs(pos-floor(pos+0.5))/tmp;
        }
        printf("%.4f\n",ans*10000);
    }
    return 0;
}

