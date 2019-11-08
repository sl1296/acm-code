
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <list>
using namespace std;

struct node{
    int a,b,idx;
}p[50005];
bool cmp(node a, node b)
{
    if (a.a != b.a) return a.a < b.a;
    else return a.b < b.b;
}
bool cmp2(node a, node b)
{
    if (a.b != b.b) return a.b > b.b;
    else return a.a < b.a;  //可以不需要
}
bool isIntervals(node x, node y, node z)  //判断这三个集合是否相交
{
    int f1 = y.a <= x.b;  //x与y相交
    int f2 = (z.a <= x.b) && (z.a <= y.b);  //z与x,y相交
    if (f1 && f2) return 1;
    else return 0;
}

int ans[50005];
int main()
{
   // freopen("in.txt","r",stdin);
  //  freopen("out+.txt","w+",stdout);
    int _;
    cin >> _;
    while(_--)
    {
        int n;
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d",&p[i].a,&p[i].b);
            p[i].idx = i + 1;
        }
        sort(p, p + n, cmp);
        node x[5];
        x[0] = p[0]; x[1] = p[1];
        int pos = 0;
        //====
        for (int i = 2; i < n; i++)
        {
            x[2] = p[i];
            sort(x, x + 3, cmp);
            int f = isIntervals(x[0],x[1],x[2]); //如果这三个集合相交

            sort(x, x + 3, cmp2);
            if (f)
            {
                ans[pos++] = x[0].idx;
                swap(x[0],x[2]);  //删去y最大的那个
            }

        }
        //====
        sort(ans, ans + pos);
        cout << pos << endl;
        if (pos > 0) cout << ans[0];
        for (int i = 1; i < pos; i++) cout << " " << ans[i];
        cout << endl;
    }
    return 0;
}

