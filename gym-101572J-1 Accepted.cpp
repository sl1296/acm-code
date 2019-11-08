
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int l,r;
int main()
{
    scanf("%d%d",&l,&r);
    if(l==0&&r==0) printf("Not a moose\n");
    else if(l==r) printf("Even %d\n",l+r);
    else printf("Odd %d\n",max(l,r)*2);
    return 0;
}

