
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int line[10];
int mp[5][5];
int goal[10][2]={{2,2},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1}};
int sx,sy;
bool nixu(){
    int ni=0;
    for(int i=0;i<8;i++){
        if(line[i]==0)ni+=4-i/3-i%3,sx=i/3,sy=i%3;
        for(int j=i+1;j<9;j++){
            if(line[i]>line[j])ni++;
        }
    }
    return ni%2==0;
}
int h(){
    int re=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int w=mp[i][j];
            re+=abs(i-goal[w][0])+abs(j-goal[w][1]);
        }
    }
    return re;
}
int limit,length,path[100];
bool flag;
int tx[5]={1,0,0,-1};
int ty[5]={0,-1,1,0};
char op[5]="dlru";
void dfs(int sx,int sy,int len,int pre){
    if(flag)return;
    int va=h();
    if(len==limit){
        if(va)return;
        flag=true;
        length=len;
        return;
    }else if(len<limit){
        if(va==0){
            flag=true;
            length=len;
            return;
        }
    }
    for(int i=0;i<4;i++){
        if(len&&i+pre==3)continue;
        int nx=sx+tx[i],ny=sy+ty[i];
        if(nx<0||ny<0||nx>2||ny>2)continue;
        swap(mp[sx][sy],mp[nx][ny]);
        int vv=h();
        if(vv+len<=limit&&flag==false){
            path[len]=i;
            dfs(nx,ny,len+1,i);
            if(flag)return;
        }
        swap(mp[sx][sy],mp[nx][ny]);
    }
}
int main(){
  //  system("chcp 936");
    char in[5];
    while(~scanf("%s",in)){
        line[0]=(in[0]=='x')?0:in[0]-48;
        mp[0][0]=line[0];
        for(int i=1;i<9;i++){
            scanf("%s",in);
            line[i]=(in[0]=='x')?0:in[0]-48;
            mp[i/3][i%3]=line[i];
        }
        if(!nixu()){
            printf("unsolvable\n");
            continue;
        }
        limit=h();
        flag=false;
        length=0;
        memset(path,-1,sizeof(path));
        while(flag==false&&length<=30){
            dfs(sx,sy,0,0);
            if(flag==false)limit++;
        }
        if(flag){
            for(int i=0;i<length;i++)printf("%c",op[path[i]]);
            printf("\n");
        }else{
            printf("unsolvable\n");
        }
    }
    return 0;
}

