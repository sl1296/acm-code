
#include<cstdio>
int r[200][200];
int main(){
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    if(n%p==0){
        printf("Yes\n");
        int cc=1;
        for(int i=0;i<n;i+=p){
            for(int j=0;j<m;++j){
                for(int k=0;k<p;++k){
                    r[i+k][j]=cc;
                }
                ++cc;
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(j)printf(" ");
                printf("%d",r[i][j]);
            }
            printf("\n");
        }
    }else if(m%p==0){
        printf("Yes\n");
        int cc=1;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;j+=p){
                for(int k=0;k<p;++k){
                    r[i][j+k]=cc;
                }
                ++cc;
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(j)printf(" ");
                printf("%d",r[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("No\n");
    }
    return 0;
}

