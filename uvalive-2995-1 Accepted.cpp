
#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
int n;char pos[10][10][10],view[6][10][10];
char readc(){
    char ch;
    for(;;){
        ch=getchar();
        if((ch>='A'&&ch<='Z')||ch=='.')return ch;
    }
}
void get(int k,int i,int j,int len,int &x,int &y,int &z){
    switch(k){
        case 0:x=len;y=j;z=i;break;
        case 1:x=n-1-j;y=len;z=i;break;
        case 2:x=n-1-len;y=n-1-j;z=i;break;
        case 3:x=j;y=n-1-len;z=i;break;
        case 4:x=n-1-i;y=j;z=len;break;
        case 5:x=i;y=j;z=n-1-len;
    }
}
int main(){
    while(scanf("%d",&n)==1&&n){
        REP(i,n)REP(k,6)REP(j,n)view[k][i][j]=readc();
        REP(i,n)REP(j,n)REP(k,n)pos[i][j][k]='#';
        REP(k,6)REP(i,n)REP(j,n)if(view[k][i][j]=='.')REP(p,n){int x,y,z;get(k,i,j,p,x,y,z);pos[x][y][z]='.';}
        for(;;){
            bool done=true;
            REP(k,6)REP(i,n)REP(j,n)if(view[k][i][j]!='.')REP(p,n){
                int x,y,z;
                get(k,i,j,p,x,y,z);
                if(pos[x][y][z]=='.')continue;
                if(pos[x][y][z]=='#'){
                    pos[x][y][z]=view[k][i][j];
                    break;
                }
                if(pos[x][y][z]==view[k][i][j])break;
                pos[x][y][z]='.';
                done=false;
            }
            if(done)break;
        }
        int ans=0;
        REP(i,n)REP(j,n)REP(k,n)if(pos[i][j][k]!='.')ans++;
        printf("Maximum weight: %d gram(s)\n",ans);
    }
    return 0;
}

