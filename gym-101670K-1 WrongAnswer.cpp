
#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define M 200010
vector<int> g[N];
vector<int> v_chu,v_ru;
int head[N],to[M],pre[M];
int dfn[N],low[N],sta[N],block[N],chu[N],ru[N],id[N],fa[N];
bool insta[N];
int n,m,e,cnt,scnt,top,num;
int a[N],b[N],edge;
void addedge(int x,int y)
{
    to[e]=y;pre[e]=head[x];head[x]=e++;
}
void tarjan(int x)
{
    dfn[x]=low[x]=++cnt;
    insta[x]=true;
    sta[++top]=x;
    int y;
    for(int i=head[x];i!=-1;i=pre[i])
    {
        y=to[i];
        if(!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(insta[y]) low[x]=min(low[x],dfn[y]);
    }
    if(low[x]==dfn[x])
    {
        ++scnt;
        id[scnt]=x;
        do
        {
            y=sta[top--];
            insta[y]=false;
            block[y]=scnt;
        }while(y!=x);
    }
}
void dfs2(int x)
{
//    printf("%d %d num\n",x,num);
    fa[x]=num;
    for(int i=0;i<g[x].size();++i)
    {
        int y=g[x][i];
        if(fa[y]) continue;
        dfs2(y);
    }
}
void ADD(int x,int y)
{
    ++edge;
    a[edge]=x;b[edge]=y;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        edge=0;
        memset(head,-1,sizeof(head));
        e=0;
        int x,y;
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d",&x,&y);
            addedge(x,y);
        }
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(insta,0,sizeof(insta));
        cnt=scnt=top=0;
        for(int i=1;i<=n;++i)
            if(!dfn[i]) tarjan(i);
        memset(chu,0,sizeof(chu));
        memset(ru,0,sizeof(ru));
        for(int i=1;i<=scnt;++i) g[i].clear();
        for(int i=1;i<=n;++i)
        {
            for(int j=head[i];j!=-1;j=pre[j])
            {
                x=block[i];y=block[to[j]];
                if(x!=y)
                {
                    ++chu[x];++ru[y];
                    g[x].push_back(y);
                    g[y].push_back(x);
//                    printf("%d %d !!!\n",x,y);
                }
            }
        }
        if(scnt==1)
        {
            printf("0\n");
            continue;
        }
//        printf("ok\n");
        int tot1=0,tot2=0;
        v_chu.clear();v_ru.clear();
        for(int i=1;i<=scnt;++i)
        {
            if(!chu[i]) {++tot1;v_chu.push_back(i);}
            if(!ru[i]) {++tot2;v_ru.push_back(i);}
            fa[i]=0;
        }
//        printf("ok\n");
        int ans=max(tot1,tot2);
        num=0;
        for(int i=1;i<=scnt;++i)
            if(fa[i]==0)
            {
//                printf("%d !!!!!!!\n",i);
                ++num;dfs2(i);
            }
//        printf("%d ok\n",num);
        vector<vector<int> > fru,fchu;
        vector<int> levchu,levru;
        int levchun=0,levrun=0;
        fru.resize(num+1);fchu.resize(num+1);;levchu.resize(ans);levru.resize(ans);
        for(int i=0;i<tot1;++i)fchu[fa[v_chu[i]]].push_back(v_chu[i]);
        for(int i=0;i<tot2;++i)fru[fa[v_ru[i]]].push_back(v_ru[i]);
//        for(int i=1;i<=num;++i){
//            printf("?%d %d\n",fru[i].size(),fchu[i].size());
//        }
        for(int i=1;i<num;++i){
            ADD(fchu[i][0],fru[i+1][0]);
        }
//        printf("?ok %d %d\n",fchu[num].size(),fru[1].size());
        ADD(fchu[num][0],fru[1][0]);
//        printf("sss\n");
        for(int i=1;i<=num;++i){
//            printf("i=%d\n",i);
            int sz1=fchu[i].size(),sz2=fru[i].size();
            for(int j=1;j<min(sz1,sz2);++j){
                ADD(fchu[i][j],fru[i][j]);
            }
            if(sz1<sz2){
                for(int j=min(sz1,sz2);j<sz2;++j){
                    levru[levrun++]=fru[i][j];
                }
            }else{
                for(int j=min(sz1,sz2);j<sz1;++j){
                    levchu[levchun++]=fchu[i][j];
                }
            }
        }
//        printf("ok\n");
        for(int i=0;i<min(levchun,levrun);++i){
            ADD(levchu[i],levru[i]);
        }
//        printf("oo\n");
        if(levchun>levrun){
            for(int i=min(levchun,levrun);i<levchun;++i){
                ADD(levchu[i],fru[1][0]);
            }
        }else{
//            printf("%d %d\n",levchun,levrun);
            for(int i=min(levchun,levrun);i<levrun;++i){
//                printf("i=%d %d\n",i,fchu[0].size());
                ADD(fchu[1][0],levru[i]);
            }
        }
        printf("%d\n",ans);
//        printf("%d %d ??\n",id[1],id[2]);
        for(int i=1;i<=edge;++i)
        {
            printf("%d %d\n",id[a[i]],id[b[i]]);
//            printf("%d %d !!\n",a[i],b[i]);
        }
    }
    return 0;
}

