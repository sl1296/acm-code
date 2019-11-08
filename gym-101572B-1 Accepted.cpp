
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define N 510
struct rec{
    double v;
    string st;
}q[N];
char st[N][30];
double a[N],b[N];
int n;
vector<string> v;
bool cmp(rec &a,rec &b)
{
    return a.v<b.v;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%s%lf%lf",st[i],&a[i],&b[i]);
    }
    double ans=1e9,tmp;
    vector<string> vec;
    for(int i=1;i<=n;++i)
    {
        int t=0;
        tmp=a[i];
        vec.clear();
        vec.push_back(st[i]);
        for(int j=1;j<=n;++j)
            if(i!=j)
            {
                q[++t].v=b[j];
                q[t].st=st[j];
            }
        sort(q+1,q+t+1,cmp);
        for(int i=1;i<=3;++i)
        {
            tmp+=q[i].v;
            vec.push_back(q[i].st);
        }
        if(tmp<ans)
        {
            ans=tmp;
            v=vec;
        }
    }
    printf("%.2f\n",ans);
    for(int i=0;i<v.size();++i)
        cout<<v[i]<<endl;
    return 0;
}
/*
6
ASHMEADE 9.90 8.85
BLAKE 9.69 8.72
BOLT 9.58 8.43
CARTER 9.78 8.93
FRATER 9.88 8.92
PLWELL 9.72 8.61
*/

