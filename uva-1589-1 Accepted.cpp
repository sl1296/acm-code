
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
bool is[15][15];
char mmap[15][15];
int tx[10]={-2,-1,1,2,2,1,-1,-2};
int ty[10]={1,2,2,1,-1,-2,-2,-1};
int ex[10]={-1,0,0,1,1,0,0,-1};
int ey[10]={0,1,1,0,0,-1,-1,0};
int sx[5]={1,-1,0,0};
int sy[5]={0,0,1,-1};
int main(){
    int n,x,y;
    int xx[10],yy[10];
    char s[10][5];
    while(scanf("%d%d%d",&n,&x,&y),n+x+y){
        memset(is,false,sizeof(is));
        memset(mmap,0,sizeof(mmap));
        for(int i=0;i<n;i++){
            scanf("%s%d%d",&s[i],&xx[i],&yy[i]);
            mmap[xx[i]][yy[i]]=s[i][0];
        }
        for(int i=0;i<n;i++){
        	if(s[i][0]=='G'){
        		for(int j=xx[i]-1;j>0;j--){
        			is[j][yy[i]]=true;
                	if(mmap[j][yy[i]])break;
        		}
        	}else if(s[i][0]=='R'){
        		int lx=xx[i];
        		int ly=yy[i];
                for(int j=ly+1;j<10;j++){
                	is[lx][j]=true;
                	if(mmap[lx][j])break;
                }
                for(int j=ly-1;j>0;j--){
                	is[lx][j]=true;
                	if(mmap[lx][j])break;
                }
                for(int j=lx+1;j<11;j++){
                	is[j][ly]=true;
                	if(mmap[j][ly])break;
                }
                for(int j=lx-1;j>0;j--){
                	is[j][ly]=true;
                	if(mmap[j][ly])break;
                }
            }else if(s[i][0]=='H'){
                for(int j=0;j<8;j++){
                    if(mmap[xx[i]+ex[j]][yy[i]+ey[j]]==0){
                        is[xx[i]+tx[j]][yy[i]+ty[j]]=true;
                    }
                }
            }else{
                int lx=xx[i],ly=yy[i];
                int cc=0;
                for(int j=lx-1;j>0;j--){
                    if(cc==1)is[j][ly]=true;
                    if(mmap[j][ly])cc++;
                }
                cc=0;
                for(int j=lx+1;j<11;j++){
                    if(cc==1)is[j][ly]=true;
                    if(mmap[j][ly])cc++;
                }
                cc=0;
                for(int j=ly-1;j>0;j--){
                    if(cc==1)is[lx][j]=true;
                    if(mmap[lx][j])cc++;
                }
                cc=0;
                for(int j=ly+1;j<10;j++){
                    if(cc==1)is[lx][j]=true;
                    if(mmap[lx][j])cc++;
                }
            }
        }
  /*      for(int i=1;i<11;i++){
        	for(int j=1;j<10;j++){
        		printf("%3d,%d ",mmap[i][j],is[i][j]);
        	}
        	printf("\n");
        }*/
        bool ans=false;
        for(int i=0;i<4;i++){
            int ax=x+sx[i];
            int ay=y+sy[i];
            if(ax>0 && ax<4 && ay>3 && ay<7 && is[ax][ay]==false){
                ans=true;
                break;
            }
        }
        if(ans)printf("NO\n");else printf("YES\n");
    }
    return 0;
}

