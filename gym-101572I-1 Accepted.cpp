
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 510
const int inf=0x3f3f3f3f;
int g[N][N],a[N][N],pre[N],d[N];
bool vis[N];
map<string,int> mp;
string to[N];
int n;
void bfs(int s)
{
    queue<int> que;
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[s]=0;que.push(s);vis[s]=true;
    while(!que.empty())
    {
        int x=que.front();que.pop();
        for(int y=1;y<=n;++y)
            if(!vis[y]&&g[x][y]<inf)
            {
                d[y]=d[x]+1;
                pre[y]=x;
                vis[y]=true;
                que.push(y);
            }
    }
}
void split(string &line,vector<string> &vec)
{
    string st="";
    int len=line.length();
    for(int i=0;i<len;++i)
    {
        if(line[i]==' '||line[i]==',')
        {
            if(st!="") vec.push_back(st);
            st="";
        }
        else st+=line[i];
    }
    if(st!="") vec.push_back(st);
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    string st;
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=n;++i)
    {
        cin>>st;
        mp[st]=i;to[i]=st;
    }
    int x,y,m,z=0;
    for(int i=1;i<=n;++i)
    {
        cin>>st>>m;
        x=mp[st];
        for(int j=1;j<=m;++j)
        {
            cin>>st;
            bool flag=false;
            string line;
            getline(cin, line);
            vector<string> vec;
            split(line,vec);
            for(int i=0;i<vec.size();++i)
            {
                y=mp[vec[i]];
                g[x][y]=1;
                if(x==y) z=x;
            }
        }
    }
    if(z)
    {
        cout<<to[z]<<endl;
        return 0;
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            a[i][j]=g[i][j];
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    int ans=inf,id,tmp;
    for(int i=1;i<=n;++i)
    {
        if(a[i][i]<ans)
        {
            ans=a[i][i];id=i;
        }

    }
    if(ans<inf){
        bfs(id);
        for(int i=1;i<=n;++i)
            if(i!=id&&d[i]+g[i][id]==ans)
            {
                vector<int> vec;
                x=i;vec.push_back(i);
                while(x!=id)
                {
                    x=pre[x];
                    vec.push_back(x);
                }
                for(int i=vec.size()-1;i>=0;--i)
                {
                    cout<<to[vec[i]];
                    if(i==0) cout<<endl;
                    else cout<<" ";
                }
                break;
            }
    }
    else cout<<"SHIP IT"<<endl;
    return 0;
}
/*
4
a b c d
a 1
import d, b, c
b 2
import d
import c
c 1
import c
d 0

5
classa classb myfilec execd libe
classa 2
import classb
import myfilec, libe
classb 1
import execd
myfilec 1
import libe
execd 1
import libe, classa
libe 0
*/

