
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
__int64 a[15], b[15], n;
void extend_gcd(__int64 a, __int64 b, __int64 &d, __int64 &x, __int64 &y)
{
    if(b == 0) { d = a, x = 1, y = 0; }
    else { extend_gcd(b, a%b, d, y, x), y -= x*(a/b); }
}
void extend_chinese_reminder(__int64 &a1, __int64 &b1)
{
	__int64 x, y, g, tmp, i, a2, b2;
	a1=a[0];b1=b[0];
	for(i = 1; i < n; i++) {
		a2 = a[i], b2 = b[i];
		extend_gcd(a1, a2, g, x, y);
		tmp = a2/g;
		x = x*(b2-b1)/g;
		x = (x%tmp+tmp)%tmp;
		b1 = a1*x+b1;
		a1 = (a1*a2)/g;
		b1 = (b1%a1+a1)%a1;
	}
}
int main(){
    __int64 t,i,m,r,z,a1,b1;
    scanf("%I64d",&t);
    for(z=0;z<t;z++){
        scanf("%I64d%I64d",&m,&n);
        r=0;
        for(i=0;i<n;i++)scanf("%I64d",&a[i]);
        for(i=0;i<n;i++)scanf("%I64d",&b[i]);
        extend_chinese_reminder(a1,b1);
        for(i=b1;i<=m;i+=a1)r++;
        printf("%I64d\n",r);
    }
    return 0;
}

