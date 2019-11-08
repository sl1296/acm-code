
#include<bits/stdc++.h>
using namespace std;
void ad(double x,double a,double w,double &L,double &R){
    if(a==0){
        if(x<=0 || x>=w)R=L-1;
    }else if(a>0){
        L=max(L,-x/a);
        R=min(R,(w-x)/a);
    }else{
        L=max(L,(w-x)/a);
        R=min(R,-x/a);
    }
}
struct po{
    double x;
    bool st;
    bool operator < (const po &p) const{
        return x<p.x || (p.x==x && st>p.st);
    }
}ev[200100];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int w,h,n;
        int cc=0;
        scanf("%d%d%d",&w,&h,&n);
        for(int i=0;i<n;i++){
            double a,b,x,y;
            scanf("%lf%lf%lf%lf",&x,&y,&a,&b);
            double L=0,R=1e9;
            ad(x,a,w,L,R);ad(y,b,h,L,R);
            if(L<R){
                ev[cc]=(po){L,false};cc++;
                ev[cc]=(po){R,true};cc++;
            }
        }
        sort(ev,ev+cc);
        int ans=0,zt=0;
        for(int i=0;i<cc;i++){
            if(ev[i].st){
                zt--;
            }else{
                zt++;
                ans=max(ans,zt);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

