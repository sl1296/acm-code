
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
string stt[10010];
struct Hash{
    static const int mod=100007;
    static const int M=600000;
    int e;
    int head[mod],pre[M];
    ull to[M];
    vector<int> g[M];
    void init()
    {
        for(int i=0;i<mod;++i) head[i]=-1;
        e=0;
    }
    ull get_hash(const string &st)
    {
        ull h=0;
        for(int i=0;i<st.size();++i)
            h=h*1007+st[i];
        return h;
    }
    void insert(string st,int z)
    {
        ull h=get_hash(st);
        ull k=h%mod;
        for(int i=head[k];i!=-1;i=pre[i])
            if(to[i]==h)
            {
                g[i].push_back(z);
                return;
            }
        to[e]=h;g[e].push_back(z);pre[e]=head[k];head[k]=e++;
    }
    void doing()
    {
        for(int i=0;i<M;++i)
            if(g[i].size())
            {
                sort(g[i].begin(),g[i].end());
                int t=unique(g[i].begin(),g[i].end())-g[i].begin();
                while(g[i].size()>t) g[i].pop_back();
            }
    }
    int count(string st,string &ans)
    {
        ull h=get_hash(st);
        ull k=h%mod;
        for(int i=head[k];i!=-1;i=pre[i])
            if(to[i]==h)
            {
                ans=stt[g[i][0]];return g[i].size();
            }
        return 0;
    }
}ha;
char st[20];

int main()
{
    int n,m;
    scanf("%d",&n);
    ha.init();
    for(int i=1;i<=n;++i)
    {
        scanf("%s",st);
        stt[i]=st;
        int len=strlen(st);
        for(int l=1;l<=len;++l)
        {
            for(int j=0;j+l<=len;++j)
            {
                string ss="";
                for(int k=j;k<j+l;++k)
                    ss+=st[k];
                ha.insert(ss,i);
            }
        }
    }
    ha.doing();
    scanf("%d",&m);
    while(m--)
    {
        scanf("%s",st);
        string ans;
        int k=ha.count(st,ans);
        if(k==0) printf("%d -\n",0);
        else printf("%d %s\n",k,ans.c_str());
    }
    return 0;
}
/*
4
test
contests
test.
.test
6
ts
.
.test
contes.
st
*/

