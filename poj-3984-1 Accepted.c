
#include <stdio.h>
int xx[4]={-1,0,1,0};
int yy[4]={0,1,0,-1};
int max=100;
int rex[100],rey[100],rx[100],ry[100],is[8][8];
int a[8][8];
void dfs(int x,int y,int s){
    int i;
    rx[s]=x;ry[s]=y;
    if(x==5 && y==5){
        if(s<max){
            for(i=0;i<=s;i++){
                rex[i]=rx[i];
                rey[i]=ry[i];
            }
            max=s;
        }
        return;
    }
    is[x][y]=1;
    for(i=0;i<4;i++){
        if(a[x+xx[i]][y+yy[i]]==0 && is[x+xx[i]][y+yy[i]]==0){
            dfs(x+xx[i],y+yy[i],s+1);
        }
    }
    is[x][y]=0;
}
int main(){
    int i,j;
    for(i=1;i<=5;i++){
        for(j=1;j<=5;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<7;i++)a[0][i]=a[6][i]=a[i][0]=a[i][6]=1;
    dfs(1,1,0);
    for(i=0;i<=max;i++){
        printf("(%d, %d)\n",rex[i]-1,rey[i]-1);
    }
}

