
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int isOne(__int64 n)  //例如：456计算450-456有没有符合条件的数
{
    int s=0;
    __int64 i=n/10*10;
    __int64 m = n;
    for(;i<=m;i++)
    {
        n=i;
        s=0;
        while(n)
        {
            s+=n%10;
            n/=10;
        }
        if(s%10==0) return 1;
    }
    return 0;
}

__int64 getNum(__int64 n)
{
    if(n<0) return 0;
    if(n<=10)   return 1;
    return n/10+isOne(n);
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        __int64 a,b;
        scanf("%I64d%I64d",&a,&b);
        printf("Case #%d: %I64d\n",cas++,getNum(b)-getNum(a-1));
    }
    return 0;
}

