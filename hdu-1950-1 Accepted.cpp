
#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int a[40010];
int b[40010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            b[i]=INF;
        }
        for(int i=0;i<n;i++){
            *(lower_bound(b,b+n,a[i]))=a[i];
        }
        int ans=lower_bound(b,b+n,INF)-b;
        printf("%d\n",ans);
    }
    return 0;
}


