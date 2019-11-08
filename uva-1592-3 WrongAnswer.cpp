
#include<cstdio>
#include<map>
#include<string>
#include<cstring>
using namespace std;
char in[100010];
map<string,int> ma;
int data[10010][15];
char aa[100010];
struct node{
    int a,b;
    bool operator < (const node &p) const{
        if(a!=p.a)return a<p.a;
        return b<p.b;
    }
};
map<node,int> ys[15][15];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        int cnt=1;
        int r1,r2,c1,c2;
        ma.clear();
        for(int i=0;i<15;i++)for(int j=0;j<15;j++)ys[i][j].clear();
        gets(in);
        bool ans=true;
        for(int i=0;i<n;i++){
            gets(in);
            if(!ans)continue;
            int len=strlen(in);
            int pp=0;
            for(int j=0;j<m;j++){
                int k=0;
                while(in[pp]!=','&&in[pp]!=0){
                    aa[k++]=in[pp++];
                }
                pp++;
                aa[k]=0;
                int id=ma[aa];
                if(id==0){
                    ma[aa]=cnt;
                    id=cnt++;
                }
                data[i][j]=id;
            }
            for(int j=0;j<m;j++){
                for(int k=j+1;k<m;k++){
                    node to=(node){data[i][j],data[i][k]};
                    int from=ys[j][k][to];
                    if(from){
                        ans=false;
                        r1=from;
                        r2=i;
                        c1=j+1;
                        c2=k+1;
                        break;
                    }else{
                        ys[j][k][to]=i+1;
                    }
                }
                if(!ans)break;
            }
        }
        if(ans)printf("YES\n");
        else printf("NO\n%d %d\n%d %d\n",r1,r2,c1,c2);
    }
    return 0;
}

