
#include<cstdio>
char s[1010][1010];
int pd[1010][1010];
int xx[8]={0,0,0,1,1,2,2,2};
int yy[8]={0,1,2,0,2,0,1,2};
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%s",s[i]);
    }
    for(int i=0;i<n-2;++i){
        for(int j=0;j<m-2;++j){
            int cc=0;
            for(int k=0;k<8;++k){
                if(s[i+xx[k]][j+yy[k]]=='#'){
                    ++cc;
                }
            }
            if(cc==8){
                for(int k=0;k<8;++k){
                    pd[i+xx[k]][j+yy[k]]=1;
                }
            }
        }
    }
    bool ans=true;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(s[i][j]=='#' && pd[i][j]==0){
                ans=false;
                break;
            }
        }
    }
    if(ans)printf("YES\n");
    else printf("NO\n");
    return 0;
}


