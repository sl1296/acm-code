
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char mmap[10][10];
int tx[10]={1,-1,0,0,-1,-1,1,1};
int ty[10]={0,0,1,-1,-1,1,-1,1};
bool judge(int i,int j,char now){
    if(mmap[i][j]!='-')return false;
  //  printf("judge(%d,%d,%c)\n",i,j,now);
    for(int a=0;a<8;a++){
        int x=i,y=j;
        bool st=false;
       // printf("%d %d %d\n",i,j,a);
        while(1){
            x+=tx[a];
            y+=ty[a];
           // printf("po:%d %d %c st=%d\n",x,y,mmap[x][y],st);
            if(x>8 || x<1 || y>8 || y<1)break;
            if(st==false){
             //   printf("1\n");
                if(mmap[x][y]==now || mmap[x][y]=='-')break;
                else st=true;
            }else{
           //     printf("2\n");
                if(mmap[x][y]=='-')break;
                if(mmap[x][y]==now)return true;
            }
        }
       // getchar();
    }
    return false;
}
void add(int i,int j,char now){
    mmap[i][j]=now;
    for(int a=0;a<8;a++){
        int x=i,y=j;
        bool st=false;
        bool re=false;
        while(1){
            x+=tx[a];
            y+=ty[a];
            if(x>8 || x<0 || y>8 || y<0)break;
            if(st==false){
                if(mmap[x][y]==now || mmap[x][y]=='-')break;
                else st=true;
            }else{
                if(mmap[x][y]=='-')break;
                if(mmap[x][y]==now){
                    re=true;
                    break;
                }
            }
        }
        if(re){
         //   printf("re=%d\n",re);
            for(int b=i,c=j;(b!=x || c!=y);b+=tx[a],c+=ty[a]){
              //  printf("%d %d\n",b,c);
                mmap[b][c]=now;
            }
        }
    }
    int whi=0,blc=0;
    for(int xx=1;xx<9;xx++){
        for(int jj=1;jj<9;jj++){
            if(mmap[xx][jj]=='B')blc++;
            else if(mmap[xx][jj]=='W')whi++;
        }
    }
    printf("Black - %d White - %d\n",blc,whi);
}
int main(){
    int t;
    char in[100],now;
    scanf("%d%s",&t,&mmap[1][1]);
    int cas=0;
    while(t--){
        if(cas)printf("\n");
        cas++;
        for(int i=2;i<9;i++)scanf("%s",&mmap[i][1]);
        scanf("%s",in);
        now=in[0];
        while(scanf("%s",in)!=EOF){
           // printf("in %c\n",now);
            if(in[0]=='B' || in[0]=='W' || in[0]=='-'){
                strcpy(&mmap[1][1],in);
                break;
            }else if(in[0]=='L'){
                int cc=0;
                for(int i=1;i<9;i++){
                    for(int j=1;j<9;j++){
                        if(judge(i,j,now)){
                            if(cc)printf(" ");
                            cc++;
                            printf("(%d,%d)",i,j);
                        }
                 //       printf("end\n");getchar();
                    }
                }
                if(cc==0)printf("No legal move.");
                printf("\n");
            }else if(in[0]=='M'){
                if(judge(in[1]-'0',in[2]-'0',now)==false)now=(now=='W')?'B':'W';
                add(in[1]-'0',in[2]-'0',now);
                now=(now=='W')?'B':'W';
            }else if(in[0]=='Q'){
                for(int i=1;i<9;i++)printf("%s\n",&mmap[i][1]);
            }
        }
    }
    printf("\n");
    return 0;
}
/*
2
--------
--------
--------
---WB---
---BW---
--------
--------
--------
W
L
M35
L
Q
*/

