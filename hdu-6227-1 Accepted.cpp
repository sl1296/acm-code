
#include<cstdio>
#include<algorithm>
using namespace std;
int a[510];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,sum=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
            if(i)sum+=a[i]-a[i-1]-1;
        }
        sum-=min(a[1]-a[0]-1,a[n-1]-a[n-2]-1);
        printf("%d\n",sum);
    }
    return 0;
}

