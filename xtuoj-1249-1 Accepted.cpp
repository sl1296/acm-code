
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn = 100005 ;
int a[maxn] ;
int main(){
    int n,m ;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]) ;
        }
        double sum = 0 ;
        double ssum = 0 ;
        for(int i=0;i<m;i++){
            sum+=a[i] ;
            ssum+=a[i]*a[i] ;
        }
        double temp ;
        temp =sqrt((ssum-2*sum/m*(sum)+m*(sum/m)*(sum/m))/(m-1)) ;
        printf("%.8f\n",temp);
        for(int i=m;i<n;i++){
            double ans = 0;
            ssum = ssum - a[i-m]*a[i-m] +a[i]*a[i];
            sum = sum - a[i-m] +a[i];
            ans = sqrt((ssum-2*sum/m*(sum)+m*(sum/m)*(sum/m))/(m-1)) ;
            printf("%.8f\n",ans);
        }
    }
    return 0;

}


