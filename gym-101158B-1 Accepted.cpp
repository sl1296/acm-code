
#include<cstdio>
int x[10][10];
int main(){
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            scanf("%d",&x[i][j]);
        }
    }
    int ans=0;
    for(int a=0;a<10;++a){
        for(int b=0;b<10;++b){
            for(int c=0;c<10;++c){
                for(int d=0;d<10;++d){
                    int e=x[x[x[x[0][a]][b]][c]][d];
                    bool ch=true;
                    for(int t=0;t<10;++t){
                        if(t!=a)if(x[x[x[x[x[0][t]][b]][c]][d]][e]==0)ch=false;
                        if(t!=b)if(x[x[x[x[x[0][a]][t]][c]][d]][e]==0)ch=false;
                        if(t!=c)if(x[x[x[x[x[0][a]][b]][t]][d]][e]==0)ch=false;
                        if(t!=d)if(x[x[x[x[x[0][a]][b]][c]][t]][e]==0)ch=false;
                        if(t!=e)if(x[x[x[x[x[0][a]][b]][c]][d]][t]==0)ch=false;
                    }
                    if(a!=b && x[x[x[x[x[0][b]][a]][c]][d]][e]==0)ch=false;
                    if(b!=c && x[x[x[x[x[0][a]][c]][b]][d]][e]==0)ch=false;
                    if(c!=d && x[x[x[x[x[0][a]][b]][d]][c]][e]==0)ch=false;
                    if(d!=e && x[x[x[x[x[0][a]][b]][c]][e]][d]==0)ch=false;
                    if(!ch)++ans;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

