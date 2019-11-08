
#include<cstdio>
#include<cstring>
/*int left[]={4,0,2,3,5,1};
int up[]={2,1,5,0,4,3};
void rot(int* T,int* p){
    int q[6];
    memcpy(q,p,sizeof(q));
    for(int i=0;i<6;i++)p[i]=T[q[i]];
}
void getnum(){
    freopen("1.txt","w+",stdout);
    int p0[6]={0,1,2,3,4,5};
    printf("int dice24[24][6]={");
    for(int i=0;i<6;i++){
        int p[6];
        memcpy(p,p0,sizeof(p0));
        switch(i){
            case 0:rot(up,p);break;
            case 1:rot(left,p);rot(up,p);break;
            case 3:rot(up,p);rot(up,p);break;
            case 4:rot(left,p);rot(left,p);rot(left,p);rot(up,p);break;
            case 5:rot(left,p);rot(left,p);rot(up,p);
        }
        for(int j=0;j<4;j++){
            printf("{%d,%d,%d,%d,%d,%d},",p[0],p[1],p[2],p[3],p[4],p[5]);rot(left,p);
        }
    }
    printf("};\n");
}*/
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int dice24[24][6]={{2,1,5,0,4,3},{2,0,1,4,5,3},{2,4,0,5,1,3},{2,5,4,1,0,3},{4,2,5,0,3,1},{5,2,1,4,3,0},{1,2,0,5,3,4},{0,2,4,1,3,5},{0,1,2,3,4,5},{4,0,2,3,5,1},{5,4,2,3,1,0},{1,5,2,3,0,4},{5,1,3,2,4,0},{1,0,3,2,5,4},{0,4,3,2,1,5},{4,5,3,2,0,1},{1,3,5,0,2,4},{0,3,1,4,2,5},{4,3,0,5,2,1},{5,3,4,1,2,0},{3,4,5,0,1,2},{3,5,1,4,0,2},{3,1,0,5,4,2},{3,0,4,1,5,2}};
int n,dice[4][6],ans;
vector<string>names;
int ID(const char* name){
    string s(name);
    int n=names.size();
    for(int i=0;i<n;i++)if(names[i]==s)return i;
    names.push_back(s);
    return n;
}
int r[4],color[4][6];
void check(){
    for(int i=0;i<n;i++)for(int j=0;j<6;j++)color[i][dice24[r[i]][j]]=dice[i][j];
    int tot=0;
    for(int j=0;j<6;j++){
        int cnt[24];
        memset(cnt,0,sizeof(cnt));
        int maxface=0;
        for(int i=0;i<n;i++)maxface=max(maxface,++cnt[color[i][j]]);
        tot+=n-maxface;
    }
    ans=min(ans,tot);
}
void dfs(int d){
    if(d==n)check();
    else for(int i=0;i<24;i++){r[d]=i;dfs(d+1);}
}
int main(){
   // getnum();
   while(scanf("%d",&n)==1&&n){
        names.clear();
        for(int i=0;i<n;i++)for(int j=0;j<6;j++){char name[30];scanf("%s",name);dice[i][j]=ID(name);}
        ans=n*6;
        r[0]=0;
        dfs(1);
        printf("%d\n",ans);
   }
   return 0;
}

