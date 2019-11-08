
#include<stdio.h>
#define mm 3000300
int s[mm];//��ʾǰi�����˵��˵ĺͣ�i��0��ʼ
int dijilun[mm];//��ʾ�ڵڼ������ģ�i��0��ʼ
int dijige[mm];//��ʾ����������һ���ǵڼ���
int death[mm];//��ʾi������ţ�
int dead[mm];//��ʾ��i�������˵���ţ�
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
        dijilun[i]=i%k?dijilun[i-(i/k+1)]+1:0;//i��һ��û��������һ�����Ϊi-��i/k+1��
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

