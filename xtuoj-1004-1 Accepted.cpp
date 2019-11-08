
#include  <iostream>
#include  <cstdio>
#include  <set>
using namespace std;
const int maxn=1000005;
int n,T,A[maxn];
set<int> s;
int main()
{
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
        }
        int ans=0,L=0,R=0;
        s.clear();
        while(R<n)
        {
            if(!s.count(A[R]))
            {
                s.insert(A[R]);
                ans=max(R-L+1,ans);
                R++;
            }
            else
            {
                ans=max(R-L,ans);
                while(s.count(A[R]))
                {
                    s.erase(A[L]);
                    L++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

