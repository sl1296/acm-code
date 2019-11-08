
#include<cstdio>
#include<cstring>
char s[110][110];
bool is[110][110];
int tx[5]={0,0,1,-1};
int ty[5]={1,-1,0,0};
void dfs1(int x,int y){
    is[x][y]=true;
    for(int i=0;i<4;i++){
        int nx=x+tx[i];
        int ny=y+ty[i];
        if(!is[nx][ny]&&s[nx][ny]=='1')dfs1(nx,ny);
    }
}
int n,m;
bool pd;
void dfs2(int x,int y){
    is[x][y]=true;
    if(x==1||x==n||y==1||y==m)pd=true;
    for(int i=0;i<4;i++){
        int nx=x+tx[i];
        int ny=y+ty[i];
        if(!is[nx][ny]&&s[nx][ny]=='0')dfs2(nx,ny);
    }
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        memset(s,0,sizeof(s));
        memset(is,false,sizeof(is));
        for(int i=1;i<=n;i++){
            scanf("%s",&s[i][1]);
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!is[i][j]&&s[i][j]=='1'){
                    dfs1(i,j);
                    cnt++;
                }
            }
        }
        if(cnt!=1){
            printf("-1\n");
            continue;
        }
        cnt=0;
        int cc=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!is[i][j]){
                    pd=false;
                    dfs2(i,j);
                    if(pd==false)cnt++;
                    cc++;
                }
            }
        }
        if(cc==0){
            printf("1\n");
            continue;
        }
        if(cnt==0){
            printf("1\n");
        }else if(cnt==1){
            printf("0\n");
        }else{
            printf("-1\n");
        }
    }
    return 0;
}

