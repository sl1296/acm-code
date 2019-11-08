
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
int tag[10000],fw[10000],w[5];
struct hao
{
    int num,step;
};
void init()//筛法求质数
{
    memset(tag,0,sizeof(tag));
    for(int i=2; i<=9999; i++)
    {
        if(!tag[i])
        {
            for(int j=2*i; j<=9999; j=j+i)
            {
                tag[j]=1;
            }
        }
    }
    for(int i=2; i<=999; i++)
        tag[i]=1;
}
int main()
{
    init();
//    for(int i=1000;i<=9999;i++)
//        if(!tag[i])cout<<i<<" ";
    queue<hao>q;
    int t;
    scanf("%d",&t);
    while(t--)
    {

        int n,m,l=1;
        while(!q.empty())q.pop();
        scanf("%d%d",&n,&m);
        memset(fw,0,sizeof(fw));
        hao h,hh;
        h.num=n,h.step=0;
        q.push(h);
        fw[n]=1;
        while(!q.empty())
        {
            //cout<<"s"<<endl;
            hh=q.front();
            q.pop();
            int s=hh.num;
            if(hh.num==m)
            {
                l=0;
                printf("%d\n",hh.step);
                break;
            }
            // cout<<h.num<<endl;
            for(int i=0; i<=3; i++)
            {
                w[i]=(s%10);
                s=s/10;
            }

            for(int i=0; i<=9; i++)//个位
            {
                if(w[0]!=i)
                {
                    h=hh;
                    int a=i+w[1]*10+w[2]*100+w[3]*1000;
                    if((a>=1000)&&(a<=9999)&&(!tag[a])&&(!fw[a]))
                    {
                        //cout<<a1<<"d"<<endl;
                        fw[a]=1;
                        h.num=a;
                        h.step++;
                        q.push(h);
                    }
                }
            }
            for(int i=0; i<=9; i++)//十位
            {
                if(w[1]!=i)
                {
                    h=hh;
                    int b=w[0]+i*10+w[2]*100+w[3]*1000;
                    if(b>=1000&&b<=9999&&(!tag[b])&&(!fw[b]))
                    {
                        fw[b]=1;
                        h.step++;
                        h.num=b;
                        q.push(h);
                    }
                }
            }
            for(int i=0; i<=9; i++)//百位
            {

                if(w[2]!=i)
                {
                    h=hh;
                    int c=w[0]+w[1]*10+i*100+w[3]*1000;
                    if(c>=1000&&c<=9999&&(!tag[c])&&(!fw[c]))
                    {
                        fw[c]=1;
                        h.num=c;
                        h.step++;
                        //cout<<c<<" ss"<<endl;
                        q.push(h);

                    }
                }
            }
            for(int i=1; i<=9; i++)//千位
            {

                if(w[3]!=i)
                {
                    h=hh;
                    int d=w[0]+w[1]*10+w[2]*100+i*1000;
                    if(d>=1000&&d<=9999&&!tag[d]&&!fw[d])
                    {
                        fw[d]=1;
                        h.num=d;
                        h.step++;
                        q.push(h);
                    }
                }
            }


        }
        // cout<<"a"<<endl;
//        if(l)
//            printf("Impossible\n");

    }
    return 0;
}

