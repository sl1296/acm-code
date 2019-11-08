
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int se[100010];
int ss[100010];
int ee[100010];
int pre[100010];
int cc;

int en[100010];
int ys[100010];
bool ap[100010];
int szsz[100010];
int cnt;
int n,m;
void dfs(int x,int f){
    ys[x]=cnt++;
    for(int i=se[x];i!=-1;i=pre[i]){
        int ne=ee[i];
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
        cc=0;
        for(int i=1;i<=n;i++)se[i]=-1;
        for(int i=1;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            ss[cc]=a;
            ee[cc]=b;
            pre[cc]=se[a];
            se[a]=cc++;
            ss[cc]=b;
            ee[cc]=a;
            pre[cc]=se[b];
            se[b]=cc++;
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

