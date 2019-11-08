
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll a[100010];
ll b,n,f,bx,nx,fx,m;
inline bool check(ll xx){
    int xa=b,xb=n,xc=f;
    if(nx+nx>bx+fx){//2+2>1+3 3+3 3+2 2+2 1+3 1+2 1+1
        for(int i=0;i<m;++i){
            if((bx+bx)*a[i]>=xx){
                if(xa>=2){

                    xa-=2;
                }else if(xa>=1 && xb>=1){

                    xa--;
                    xb--;
                }else if(xa>=1 && xc>=1){

                    xa--;
                    xc--;
                }else if(xb>=2){

                    xb-=2;
                }else if(xc>=1 && xb>=1){

                    xc--;
                    xb--;
                }else if(xc>=2){

                    xc-=2;
                }else{
                    return false;
                }
            }else if((bx+nx)*a[i]>=xx){
                if(xa>=1 && xb>=1){

                    xa--;
                    xb--;
                }else if(xa>=1 && xc>=1){

                    xa--;
                    xc--;
                }else if(xb>=2){

                    xb-=2;
                }else if(xc>=1 && xb>=1){

                    xc--;
                    xb--;
                }else if(xc>=2){

                    xc-=2;
                }else{
                    return false;
                }
            }else if((bx+fx)*a[i]>=xx){
                if(xa>=1 && xc>=1){

                    xa--;
                    xc--;
                }else if(xb>=2){

                    xb-=2;
                }else if(xc>=1 && xb>=1){

                    xc--;
                    xb--;
                }else if(xc>=2){

                    xc-=2;
                }else{
                    return false;
                }
            }else if((nx+nx)*a[i]>=xx){
                if(xb>=2){

                    xb-=2;
                }else if(xc>=1 && xb>=1){

                    xc--;
                    xb--;
                }else if(xc>=2){

                    xc-=2;
                }else{
                    return false;
                }
            }else if((nx+fx)*a[i]>=xx){
                if(xc>=1 && xb>=1){

                    xc--;
                    xb--;
                }else if(xc>=2){

                    xc-=2;
                }else{
                    return false;
                }
            }else if((fx+fx)*a[i]>=xx){
                if(xc>=2){

                    xc-=2;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
    }else{
        for(int i=0;i<m;++i){
            if((bx+bx)*a[i]>=xx){//2+2<1+3 3+3 3+2 3+1 2+2 1+2 1+1
                if(xa>=2){

                    xa-=2;
                }else if(xa>=1 && xb>=1){

                    xa--;
                    xb--;
                }else if(xb>=2){

                    xb-=2;
                }else if(xa>=1 && xc>=1){

                    xa--;
                    xc--;
                }else if(xc>=1 && xb>=1){

                    xc--;
                    xb--;
                }else if(xc>=2){

                    xc-=2;
                }else{
                    return false;
                }
            }else if((bx+nx)*a[i]>=xx){
                if(xa>=1 && xb>=1){

                    xa--;
                    xb--;
                }else if(xb>=2){

                    xb-=2;
                }else if(xa>=1 && xc>=1){

                    xa--;
                    xc--;
                }else if(xc>=1 && xb>=1){

                    xc--;
                    xb--;
                }else if(xc>=2){

                    xc-=2;
                }else{
                    return false;
                }
            }else if((nx+nx)*a[i]>=xx){
                if(xb>=2){

                    xb-=2;
                }else if(xa>=1 && xc>=1){

                    xa--;
                    xc--;
                }else if(xc>=1 && xb>=1){

                    xc--;
                    xb--;
                }else if(xc>=2){

                    xc-=2;
                }else{
                    return false;
                }
            }else if((bx+fx)*a[i]>=xx){
                if(xa>=1 && xc>=1){

                    xa--;
                    xc--;
                }else if(xc>=1 && xb>=1){

                    xc--;
                    xb--;
                }else if(xc>=2){

                    xc-=2;
                }else{
                    return false;
                }
            }else if((nx+fx)*a[i]>=xx){
                if(xc>=1 && xb>=1){

                    xc--;
                    xb--;
                }else if(xc>=2){

                    xc-=2;
                }else{
                    return false;
                }
            }else if((fx+fx)*a[i]>=xx){
                if(xc>=2){

                    xc-=2;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
    }
}
int main(){
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&b,&n,&f,&bx,&nx,&fx);
    m=(b+n+f)/2;
    ll mx=0;
    for(int i=0;i<m;++i){
        scanf("%I64d",&a[i]);
        mx=max(mx,a[i]);
    }
    sort(a,a+m);
    ll s=1,e=mx*(fx+fx),mid;
    while(s<e){
        mid=e-(e-s)/2;
        if(check(mid)){
            s=mid;
        }else{
            e=mid-1;
        }
    }
    printf("%I64d\n",s);
    return 0;
}

