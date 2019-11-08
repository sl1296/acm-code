
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> ve[50010],vx[50010];
vector<char> vv[50010];
int du[50010];
unsigned ans,ca[50010],cb[50010],cc[50010];
queue<int> qu;
int main(){
    int n,m,u,v;
    char s[5];
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d%s",&u,&v,s);
        ve[u].push_back(v);
        vx[v].push_back(u);
        vv[v].push_back(s[0]);
        ++du[v];
    }
    for(int i=1;i<=n;++i)if(!du[i])qu.push(i);
    while(!qu.empty()){
        int now=qu.front();
        qu.pop();
        int sz=ve[now].size();
        for(int i=0;i<sz;++i){
           --du[ve[now][i]];
           if(!du[ve[now][i]])qu.push(ve[now][i]);
        }
        sz=vx[now].size();
        for(int i=0;i<sz;++i){
            int tmp=vx[now][i];
            if(vv[now][i]=='_'){
                ca[now]+=ca[tmp];
                cb[now]+=cb[tmp]+1;
                cc[now]+=cc[tmp];
            }else if(vv[now][i]=='.'){
                cc[now]+=ca[tmp]+cc[tmp];
            }else if(vv[now][i]>='a'){
                ca[now]+=ca[tmp];
            }else{
                ca[now]+=cb[tmp]+1;
            }
        }
        ans+=cc[now];
    }
    printf("%u\n",ans);
}

