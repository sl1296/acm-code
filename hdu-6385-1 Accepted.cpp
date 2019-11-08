
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int mx,my,n;
        scanf("%d%d%d",&mx,&my,&n);
        ll ans=0;
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            int now=min(min(x,mx-x),min(y,my-y));
            ans+=now;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

