
#include<bits/stdc++.h>
using namespace std;
int main(){
    int ca,kase=0;
    scanf("%d",&ca);
    while(ca--){
        int n,t;
        scanf("%d",&n);
        double ans=0;
        for(int i=0;i<=n;i++){
            scanf("%d",&t);
            ans+=t;
        }
        int a,b,maxx=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            maxx=max(maxx,b);
        }
        printf("Case #%d: %.6f\n",++kase,ans+maxx);
    }
    return 0;
}

