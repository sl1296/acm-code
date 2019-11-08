
#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

const int N = 300000005;

bool prime[N];

int main ()
{
    int left,right,i;
    scanf("%d%d",&left,&right);
  //  prime.set();  //À˘”–Œª÷√÷√1
    for (i=3;i*i<=right;i+=2) if (!prime[i])
        for (int j=i*i;j<=right;j+=2*i)
            prime[j]=true;

    int cnt=(left<=2 && 2<=right);
    for (i=5;i<=right;i+=4)
        if (i>=left && !prime[i])
            cnt++;
    printf("%d\n",cnt);
    return 0;
}

