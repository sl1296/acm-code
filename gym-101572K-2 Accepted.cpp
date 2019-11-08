
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll a[100010];
ll b,n,f,bx,nx,fx,m;
inline bool check(ll xx){
    bool out=false;
    if(xx==1966)out=true;
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
//            if(out)printf("i=%d %d %d %d\n",i,xa,xb,xc);
        }
    }
    return true;
}
int main(){
//    freopen("in+.txt","r",stdin);
//    freopen("out+.txt","w",stdout);
    while(~scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&b,&n,&f,&bx,&nx,&fx)){
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
//            printf("%lld %lld %lld\n",s,e,mid);
            if(check(mid)){
                s=mid;
            }else{
                e=mid-1;
            }
        }
//        printf("%d\n",check(1966)?1:0);
        printf("%I64d\n",s);
    }
    return 0;
}
/*
1 7 14
725 170 501
11478 29358 26962 24464 5705 28145 23281 16827 9961 491 2995

601966
*/
/*
mid=32206030
mid=16103015
mid=8051508
mid=4025754
mid=2012877
mid=1006439
mid=503220
mid=251610
mid=125805
mid=62903
mid=31452
mid=15726
mid=7863
mid=3932
mid=1966 --

mid=2949
mid=2457
mid=2211
mid=2088
mid=2027
mid=1996
mid=1981
mid=1973
mid=1969
mid=1967
*/

