
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int a[20010];
int main(){
    int n;
    while(~scanf("%d",&n)){
        ll ans=0;
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=1;i<n;i++){
            sort(a+i-1,a+n);
            a[i]+=a[i-1];
            ans+=a[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}

