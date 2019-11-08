
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int m;
__int64 extend_gcd(__int64 a,__int64 b,__int64 &x,__int64 &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    __int64 gcd=extend_gcd(b,a%b,x,y);
    __int64 tmp=x;
    x=y;
    y=tmp-a/b*x;
    return gcd;
}
int main(){
    int t,a[15],b[15],z,r,i;
    __int64 xgcd,xx,yy;
    scanf("%d",&t);
    for(z=0;z<t;z++){
        xgcd=1;
        scanf("%d",&m);
        for(i=0;i<m;i++)scanf("%d",&a[i]);
        for(i=0;i<m;i++)scanf("%d",&b[i]);
        for(i=0;i<m;i++)xgcd=xgcd*a[i]/extend_gcd(xgcd,a[i],xx,yy);
        __int64 x,y,a1,b1,a2,b2;
        a1=a[0];b1=b[0];
        bool flag=false;
        for(i=1;i<m;i++){
            a2=a[i];b2=b[i];
            __int64 gcd=extend_gcd(a1,a2,x,y);
            if((b2-b1)%gcd){
                flag=true;
                break;
            }
            __int64 t=a2/gcd;
            x=x*(b2-b1)/gcd;
            x=(x%t+t)%t;
            b1=a1*x+b1;
            a1=(a1*a2)/gcd;
            b1=(b1%a1+a1)%a1;
        }
        r=b1;
        if(flag)r=-1;
        if(!r)r=xgcd;
        printf("Case %d: %d\n",z+1,r);
    }
    return 0;
}

