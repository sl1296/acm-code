
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
//反素数打表
int s[40] = {1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,332640,498960,500001};
int b[40] = {1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,90,96,100,108,120,128,144,160,168,180,192,200,1314521};
int k,n;
char name[500111][11];
int val[500111];
struct node
{
    int l,r,n;
} a[2000100];
void init(int i,int l,int r)
{
    a[i].l = l;
    a[i].r = r;
    a[i].n = r-l+1;
    if(l!=r)
    {
        int mid = (l+r)>>1;
        init(2*i,l,mid);
        init(2*i+1,mid+1,r);
    }
}
int insert(int i,int x)
{
    a[i].n--;
    if(a[i].l == a[i].r)
    {
        return a[i].l;
    }
    if(x<=a[2*i].n)
        insert(2*i,x);
    else
        insert(2*i+1,x-a[2*i].n);
}
int main()
{
    int i,j,maxn,p,pos;
    while(~scanf("%d%d",&n,&k))
    {
        i = 0;
        while(s[i]<=n)i++;
        maxn = b[i-1];
        p = s[i-1];//第P个出队的必然是最多的并且是在得到同样多的MAX糖果中最早出队的，求得其因子数
        for(i = 1; i<=n; i++)
            scanf("%s%d",name[i],&val[i]);
        init(1,1,n);
        while(p--)//求P个熊孩子即可
        {
            n--;
            pos = insert(1,k);//出队的序号
            if(!n)
                break;
            if(val[pos]>=0)//顺时针
                k = (k-1+val[pos]-1)%n+1;//涉及模运算令代号从0开始，所以开始要减1,如同数空位线段树一样，k得到的是新树的第几个位置
            else//逆时针
                k = ((k-1+val[pos])%n+n)%n+1;
        }
        printf("%s %d\n",name[pos],maxn);
    }
    return 0;
}

