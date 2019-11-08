
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,a,mx,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans=-999999;
        scanf("%d",&a);
        mx=a;
        for(int i=1;i<n;i++){
            scanf("%d",&a);
            ans=max(ans,mx-a);
            mx=max(mx,a);
        }
        printf("%d\n",ans);
    }
    return 0;
}

