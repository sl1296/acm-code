
#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n,a,b;
    while(scanf("%d%d",&n,&m)!=EOF){
        int s=1,e=n;
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            s=max(s,min(a,b));
            e=min(e,max(a,b));
        }
        int ans=e-s;
        if(ans<0)ans=0;
        printf("%d\n",ans);
    }
    return 0;
}

