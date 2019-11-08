
#include<bits/stdc++.h>
using namespace std;
long long a[200010],b[200010];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++)scanf("%lld",&a[i]);
        for(int i=0;i<n;i++)scanf("%lld",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        long long sum=0;
        for(int i=0;i<n;i++){
            long long tmp=a[i]+b[n-i-1];
            sum+=tmp*tmp;
        }
        printf("%lld\n",sum);
    }
    return 0;
}

