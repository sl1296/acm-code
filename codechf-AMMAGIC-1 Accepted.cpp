
#include<bits/stdc++.h>
using namespace std;
#define maxn 105
struct node{
    int x,y,v,l;
    node() {}
    node(int x,int y,int v,int l):x(x),y(y),v(v),l(l) {}
};
queue<node> que;
char s[maxn][maxn];
int xp[10];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bitset<1000000000> st;
int main(){
    int ca;
    scanf("%d",&ca);
    while(ca--){
        int n,m;
        scanf("%d%d",&n,&m);
        while(!que.empty()) que.pop();
        st.reset();
        st.set(0);
        for(int i=0;i<n;i++){
            scanf("%s",s[i]);
            for(int j=0;j<m;j++){
                s[i][j]-='0';
                st.set(s[i][j]);
                que.push(node(i,j,s[i][j],1));
            }
        }
        int f=1;
        for(int i=1;i<10;i++){
            f*=10;
            xp[i]=f;
        }
        int nl=0;
        while(!que.empty()){
            node e=que.front();que.pop();
            if(nl<e.l){
                nl=e.l;
                if(xp[e.l]>st.count()) break;
            }
            for(int i=0;i<4;i++){
                int nx=e.x+dir[i][0];
                int ny=e.y+dir[i][1];
                if(nx<0||ny<0||nx>=n||ny>=m) continue;
                st.set(e.v*10+s[nx][ny]);
                que.push(node(nx,ny,e.v*10+s[nx][ny],e.l+1));
            }
        }
        for(int i=1;;i++){
            if(!st.test(i)){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}

