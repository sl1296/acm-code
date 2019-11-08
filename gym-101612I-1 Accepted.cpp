
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("intel.in","r",stdin);
    freopen("intel.out","w",stdout);
    int n,s=0;
    scanf("%d",&n);
    int x0,y0,x,y;
    scanf("%d%d",&x0,&y0);
    int l=x0,r=x0,u=y0,d=y0;
    int px=x0,py=y0;
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        l=min(l,x);
        r=max(r,x);
        u=max(u,y);
        d=min(d,y);
        s+=abs(x-px)+abs(y-py);
        px=x;py=y;
    }
    s+=abs(x-x0)+abs(y-y0);
    printf("%d\n",s-2*(r-l)-2*(u-d));
    return 0;
}

