
#include<cstdio>
#include<cstring>
struct ee{
    int next,to;
};
int n,m;
int head[10010];
ee edge[100010];
int ce;
int dfn[10010],low[10010];
int stack[10010],sp;
bool instack[10010];
int cnt,id;
void tarjan(int x){
    id++;
    dfn[x]=low[x]=id;
    stack[++sp]=x;
    instack[x]=true;
    for(int i=head[x];i!=-1;i=edge[i].next){
        int ne=edge[i].to;
        if(!dfn[ne]){
            tarjan(ne);
            if(low[ne]<low[x])low[x]=low[ne];
        }else{
            if(instack[x]&&dfn[ne]<low[x])low[x]=dfn[ne];
        }
    }
    if(dfn[x]==low[x]){
        cnt++;
        int tmp;
        do{
            tmp=stack[sp--];
            instack[tmp]=false;
        }while(tmp!=x);
    }
}
bool solve(){
    memset(dfn,0,sizeof(dfn));
    cnt=id=sp=0;
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    if(cnt==1)return true;
    return false;
}
int main(){
    while(1){
        scanf("%d%d",&n,&m);
        if(!n&&!m)break;
        int a,b;
        ce=0;
        memset(head,-1,sizeof(head));
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            edge[ce]=(ee){head[a],b};
            head[a]=ce;
            ce++;
        }
        if(solve()){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}

