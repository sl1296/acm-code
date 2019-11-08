
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int m,n;
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
    scanf("%d",&t);
    for(z=0;z<t;z++){
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)scanf("%d",&a[i]);
        for(i=0;i<m;i++)scanf("%d",&b[i]);
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
        r=(n-b1)/a1+1;
        if(b1==0)r--;
        if(flag || n<b1)r=0;
        printf("%d\n",r);
    }
    return 0;
}

