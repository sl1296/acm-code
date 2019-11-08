
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> ve[100010];
int en[100010];
int ys[100010];
bool ap[100010];
int szsz[100010];
int cnt;
int n,m;
void dfs(int x,int f){
    ys[x]=cnt++;
    int sz=ve[x].size();
    for(int i=0;i<sz;i++){
        int ne=ve[x][i];
        if(ne==f)continue;
        dfs(ne,x);
    }
    en[x]=cnt;
}
int lowbit(int x){
    return x&(-x);
}
void add(int x,int v){
    for(int i=x;i<=n;i+=lowbit(i))szsz[i]+=v;
}
int sum(int x){
    int r=0;
    for(int i=x;i>0;i-=lowbit(i))r+=szsz[i];
    return r;
}
int main(){
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++)ve[i].clear();
        for(int i=1;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            ve[a].push_back(b);
            ve[b].push_back(a);
        }
        cnt=1;
        dfs(1,-1);
        scanf("%d",&m);
        for(int i=1;i<=n;i++){
            ap[i]=true;
            szsz[i]=lowbit(i);
        }
        for(int i=0;i<m;i++){
            char s[5];int no;
            scanf("%s%d",s,&no);
            if(s[0]=='Q'){
                printf("%d\n",sum(en[no]-1)-sum(ys[no]-1));
            }else{
                if(ap[no]){
                    ap[no]=false;
                    add(ys[no],-1);
                }else{
                    ap[no]=true;
                    add(ys[no],1);
                }
            }
        }
    }
    return 0;
}

