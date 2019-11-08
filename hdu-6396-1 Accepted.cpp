
#include <bits/stdc++.h>
using namespace std;
#define N 100010
namespace IO {
    const int MX = 4e7; //1e7Õ¼ÓÃÄÚ´æ11000kb
    char buf[MX]; int c, sz;
    void begin() {
        c = 0;
        sz = fread(buf, 1, MX, stdin);
    }
    inline bool read(int &t) {
        while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
        if(c >= sz) return false;
        bool flag = 0; if(buf[c] == '-') flag = 1, c++;
        for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
        if(flag) t = -t;
        return true;
    }
}
const int inf=0x3f3f3f3f;
int b[N][5],a[N][5],c[5];
struct rec{
    int id,k;
    rec(){}
    rec(int id,int k):id(id),k(k){}
    bool operator<(const rec &p)const
    {
        return a[id][k]>a[p.id][p.k];
    }
};
priority_queue<rec> que[5];
int n,k;
int main()
{
    IO::begin();
    int ca,x;
//    scanf("%d",&ca);
    IO::read(ca);
    while(ca--)
    {
//        scanf("%d%d",&n,&k);
        IO::read(n);IO::read(k);
        for(int i=0;i<k;++i)
//            scanf("%d",&c[i]);
            IO::read(c[i]);
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<k;++j)
//                scanf("%d",&a[i][j]);
                IO::read(a[i][j]);
            for(int j=0;j<k;++j)
//                scanf("%d",&b[i][j]);
                IO::read(b[i][j]);
            que[0].push(rec(i,0));
        }
        int ans=0;
        while(true)
        {
            for(int i=0;i<k-1;++i)
            {
                while(!que[i].empty()&&c[i]>=a[que[i].top().id][i])
                {
                    que[i+1].push(rec(que[i].top().id,i+1));
                    que[i].pop();
                }
            }
            int cnt=0;
            while(!que[k-1].empty()&&c[k-1]>=a[que[k-1].top().id][k-1])
            {
                ++cnt;
                for(int i=0;i<k;++i)
                    c[i]+=b[que[k-1].top().id][i];
                que[k-1].pop();
            }
            if(cnt==0) break;
            ans+=cnt;
        }
        printf("%d\n",ans);
        for(int i=0;i<k;++i)
        {
            printf("%d",c[i]);
            if(i==k-1) printf("\n");
            else printf(" ");
        }
        for(int i=0;i<k;++i)
            while(!que[i].empty()) que[i].pop();
    }
    return 0;
}

