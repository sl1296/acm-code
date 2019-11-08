
#include<stdio.h>
#define mm 3000300
int s[mm];//表示前i轮死了的人的和，i从0开始
int dijilun[mm];//表示在第几轮死的，i从0开始
int dijige[mm];//表示在它死的那一轮是第几个
int death[mm];//表示i死的序号；
int dead[mm];//表示第i个死的人的序号；
int solve(int n,int k)
{
    int temp,i;
    temp=n;
    s[0]=0;
    int top=0;
    while(temp)
    {
        top++;
        s[top]=s[top-1]+(temp-1)/k+1;
        temp=temp-((temp-1)/k+1);
    }
    dijilun[0]=0;
    for(i=0;i<n;i++)
    {
        dijilun[i]=i%k?dijilun[i-(i/k+1)]+1:0;//i这一轮没死，则下一轮序号为i-（i/k+1）
        dijige[i]=i%k?dijige[i-(i/k+1)]:i/k+1;
    }
    for(i=0;i<n;i++)
    {
        death[i]=s[dijilun[i]]+dijige[i];
        dead[death[i]]=i+1;//printf("%d %d\n",death[i],i+1);
    }
}
int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,m;
        scanf("%d%d%d",&n,&k,&m);
        int q;
        solve(n,k);
        for(i=0;i<m;i++)
            {scanf("%d",&q);
            printf("%d\n",dead[q]);
            }
    }
    return 0;
}

