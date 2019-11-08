
#include<cstdio>
#include<cstring>
char in[50];
int son[2000010][26];
int f[2000010];
int sg[2000010];
int use;
int add(){
    int len=strlen(in);
    int now=0;
    for(int i=0;i<len;i++){
        int & ne=son[now][in[i]-'a'];
        if(ne){
            now=ne;
        }else{
            ne=++use;
            f[ne]=now;
            now=ne;
        }
    }
    return now;
}
void cal(int x){
    sg[x]=0;
    for(int i=0;i<26;i++){
        if(son[x][i]){
            sg[x]^=sg[son[x][i]]+1;
        }
    }
}
void dfs(int x){
    for(int i=0;i<26;i++){
        if(son[x][i]){
            dfs(son[x][i]);
        }
    }
    cal(x);
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        use=0;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",in);
            add();
        }
        dfs(0);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",z);
        for(int i=0;i<q;i++){
            scanf("%s",in);
            int ee=add();
            while(ee){
                cal(ee);
                ee=f[ee];
            }
            cal(0);
            if(sg[0])printf("1\n");else printf("2\n");
        }
        memset(son,0,4*26*use+200);
    }
    return 0;
}

