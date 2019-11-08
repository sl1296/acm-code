
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long ans[50010];
int main(){
    long long n,m;
    while(1){
        scanf("%lld%lld",&n,&m);
        if(n==-1&&m==-1)break;
        long long i;
        long long c=0;
        for(i=1;i<=n;i++){
            long long now=i*(i-1)/2;
            if(now>=m)break;
        }
        for(long long j=1;j<=n-i;j++)ans[c++]=j;
        long long x=m+(n-i+1)-(i-1)*(i-2)/2;
        ans[c++]=x;
        for(long long j=n,cc=0;cc<i;j--,cc++){
            if(j==x){
                cc--;
            }else{
                ans[c++]=j;
            }
        }
        for(int i=0;i<n;i++){
            if(i)printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}

