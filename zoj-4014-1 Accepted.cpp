
#include<cstdio>
int aa[110][110];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,a,b;
        scanf("%d%d%d%d",&n,&m,&a,&b);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                scanf("%d",&aa[i][j]);
            }
        }
        if(a>b){
            printf("No Solution\n");
        }else{
            int cnt=0;
            for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(aa[i][j]<a || aa[i][j]>b)++cnt;
            printf("%d\n",cnt);
        }
    }
    return 0;
}

