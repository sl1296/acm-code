
#include <bits/stdc++.h>
using namespace std;
int n;
char st[20];
int main()
{
    scanf("%d",&n);
    bool flag=true;
    for(int i=1;i<=n;++i)
    {
        scanf("%s",st);
        if(st[0]=='m') continue;
        int x=atoi(st);
        if(x!=i)
        {
            flag=false;break;
        }
    }
    if(flag) puts("makes sense");
    else puts("something is fishy");
    return 0;
}

