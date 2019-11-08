
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct nod{
    int x,y,z,step;
};
queue<nod> q;
int ans;
char ma[33][33][33];
bool is[33][33][33];
int xx[7]={1,-1,0,0,0,0};
int yy[7]={0,0,1,-1,0,0};
int zz[7]={0,0,0,0,1,-1};
int main(){
    int a,b,c,i,j,k,dx,dy,dz;
    nod l,l2;
    while(1){
        scanf("%d%d%d",&a,&b,&c);
        if(!a && !b && !c)break;
        memset(ma,0,sizeof(ma));
        memset(is,false,sizeof(is));
        for(i=1;i<=a;i++){
            for(j=1;j<=b;j++){
                scanf("%s",&ma[i][j][1]);
                for(k=1;k<=c;k++){
                    if(ma[i][j][k]=='S'){
                        l.x=i;
                        l.y=j;
                        l.z=k;
                        is[i][j][k]=1;
                        l.step=0;
                    }
                }
            }
        }
        while(!q.empty())q.pop();
        q.push(l);
        ans=-1;
        while(!q.empty()){
            l=q.front();
            q.pop();
            for(i=0;i<6;i++){
                dx=l.x+xx[i];
                dy=l.y+yy[i];
                dz=l.z+zz[i];
                if(!is[dx][dy][dz]){
                    if(ma[dx][dy][dz]=='E'){
                        ans=l.step+1;
                        break;
                    }
                    if(ma[dx][dy][dz]=='.'){
                        l2.x=dx;
                        l2.y=dy;
                        l2.z=dz;
                        l2.step=l.step+1;
                        is[dx][dy][dz]=1;
                        q.push(l2);
                    }
                }
            }
            if(ans>0)break;
        }
        if(ans==-1)printf("Trapped!\n"); else printf("Escaped in %d minute(s).\n",ans);
    }
    return 0;
}

