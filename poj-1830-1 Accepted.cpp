
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int s[100],e[100];
int a[100][100];
int x[100];
int Gauss(int equ,int var){
    for(int i=0;i<=var;i++){
        x[i]=0;
    }
    int col=0,k;
    for(k=0;k<equ&&col<var;k++,col++){
        int mr=k;
        for(int i=k+1;i<equ;i++){
            if(abs(a[i][col])>abs(a[mr][col]))mr=i;
        }
        if(mr!=k){
            for(int j=k;j<var+1;j++)swap(a[k][j],a[mr][j]);
        }
        if(a[k][col]==0){
            k--;
            continue;
        }
        for(int i=k+1;i<equ;i++){
            if(a[i][col]){
                for(int j=0;j<var+1;j++){
                    a[i][j]^=a[k][j];
                }
            }
        }
    }
//    printf("k=%d\n",k);
    for(int i=k;i<equ;i++){
        if(a[i][col])return -1;//no solution
    }
    if(k<var){
        //cal
        return var-k;
    }else{

        return 0;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&s[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&e[i]);
            a[i][i]=1;
            if(s[i]!=e[i])a[i][n]=1;
        }
        while(1){
            int u,v;
            scanf("%d%d",&u,&v);
            if(!u&&!v)break;
            a[v-1][u-1]=1;
        }
//        for(int i=0;i<n;i++){
//            for(int j=0;j<=n;j++){
//                printf("%d ",a[i][j]);
//            }
//            printf("\n");
//        }
        int ans=Gauss(n,n);
        if(ans==-1){
            printf("Oh,it's impossible~!!\n");
        }else{
            printf("%d\n",1<<ans);
        }
    }
    return 0;
}

