
#include<cstdio>
#include<algorithm>
int a[200010];
int main(){
    int n,mx=0;
    long long c=1;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        mx=std::max(mx,a[i]);
        if(i && a[i]<=a[i-1])++c;
    }
    long long r=c*(mx+1)-a[0]-(mx-a[n-1]);
    printf("%lld\n",r);
    return 0;
}

