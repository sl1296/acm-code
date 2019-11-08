
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct no{
    int x,y,step;
    bool is;
    int num;
};
queue<no> qu;
char mmap[110][110];
bool is[3][3][110][110];
int xx[9]={-2,-1,1,2,2,1,-1,-2};
int yy[9]={1,2,2,1,-1,-2,-2,-1};
int tx[5]={1,-1,0,0};
int ty[5]={0,0,1,-1};
int main(){
    int t,z;
    scanf("%d",&t);
    for(z=1;z<=t;z++){
        int x,y,sx,sy,ex,ey;
        no ls,lx;
        scanf("%d%d",&x,&y);
        memset(mmap,0,sizeof(mmap));
        memset(is,false,sizeof(is));
        while(!qu.empty())qu.pop();
        for(int i=2;i<x+2;i++){
            scanf("%s",&mmap[i][2]);
            for(int j=2;j<y+2;j++){
                if(mmap[i][j]=='s'){
                    ls.x=i;
                    ls.y=j;
                    ls.step=0;
                    ls.is=false;
                    ls.num=0;
                    qu.push(ls);
                    ls.num=1;
                    qu.push(ls);
                    is[0][0][i][j]=1;
                    is[0][1][i][j]=1;
                    sx=i;
                    sy=j;
                    mmap[i][j]='.';
                }else if(mmap[i][j]=='t'){
                    ex=i;
                    ey=j;
                    mmap[i][j]='.';
                }
            }
        }
        bool exi=false;
        int ans=-1;
        while(!qu.empty()){
            ls=qu.front();
            qu.pop();
             // printf("ss:%d %d %d %d %d\n",ls.x,ls.y,ls.step,ls.num,ls.is);
            if(ls.num==0){
                lx.num=ls.num;
                lx.step=ls.step+1;
                lx.is=ls.is;
                for(int i=0;i<8;i++){
                  //  printf("m%d\n",i);
                    lx.x=ls.x+xx[i];
                    lx.y=ls.y+yy[i];
                    //printf("%d %d %d %d %d %d %d %d %d\n",i,xx[i],yy[i],ls.x,ls.y,lx.x,lx.y,is[0][lx.x][lx.y],mmap[lx.x][lx.y]);
                    if(is[lx.is][0][lx.x][lx.y]==false && mmap[lx.x][lx.y]=='.'){
                        if(lx.x==ex && lx.y==ey){
                            exi=true;
                            ans=lx.step;
                            break;
                        }
                        is[lx.is][0][lx.x][lx.y]=true;
                        qu.push(lx);
                      //  printf("add:%d %d %d %d %d\n",lx.x,lx.y,lx.step,lx.num,lx.is);
                        if(lx.is==false && is[1][1][lx.x][lx.y]==false){
                            lx.num=1;
                            is[1][1][lx.x][lx.y]=true;
                            lx.is=true;
                            qu.push(lx);
                           // printf("add:%d %d %d %d %d\n",lx.x,lx.y,lx.step,lx.num,lx.is);
                        }
                    }
                }
                if(exi)break;
            }else{
                for(int i=0;i<4;i++){
                    lx=ls;
                    lx.step++;
                    while(1){
                        lx.x+=tx[i];
                        lx.y+=ty[i];
                        if(mmap[lx.x][lx.y]!='.')break;
                        if(is[lx.is][1][lx.x][lx.y]==false){
                            if(lx.x==ex && lx.y==ey){
                                exi=true;
                                ans=lx.step;
                                break;
                            }
                            is[lx.is][1][lx.x][lx.y]=true;
                            qu.push(lx);
                            //printf("add:%d %d %d %d %d\n",lx.x,lx.y,lx.step,lx.num,lx.is);
                            if(lx.is==false && is[1][0][lx.x][lx.y]==false){
                                lx.is=true;
                                lx.num=0;
                                is[1][0][lx.x][lx.y]=true;
                                qu.push(lx);
                               // printf("add:%d %d %d %d %d\n",lx.x,lx.y,lx.step,lx.num,lx.is);
                                lx.is=false;
                                lx.num=1;
                            }
                        }
                    }
                    if(exi)break;
                }
                if(exi)break;
            }
        }
        printf("Case #%d: %d\n",z,ans);
    }
    return 0;
}
/*
4 5
s####
##.##
#####
###.t
2 5
..#..
s#..t
*/

