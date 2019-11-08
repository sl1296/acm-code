
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
char mp[50][50];
int n;
inline int g(int x,int y){
    return x*n+y;
}
int a[500][500];
int x[500];
bool isfree[500];
int Gauss(int equ,int var){
    for(int i=0;i<=var;i++){
        x[i]=0;
        isfree[i]=true;
    }
    int col=0,k;
    for(k=0;k<equ&&col<var;k++,col++){
        int mr=k;
        for(int i=k+1;i<equ;i++){
            if(abs(a[i][col])>abs(a[mr][col]))mr=i;
        }
        if(mr!=k){
            for(int i=col;i<=var;i++)swap(a[k][i],a[mr][i]);
        }
        if(a[k][col]==0){
            k--;
            continue;
        }
        for(int i=k+1;i<equ;i++){
            if(a[i][col]){
                for(int j=col;j<=var;j++){
                    a[i][j]^=a[k][j];
                }
            }
        }
    }
    for(int i=k;i<equ;i++){
        if(a[i][col])return -1;//no solve
    }
    for(int i=0;i<equ;i++){
        if(i==var)break;
        if(!a[i][i]){
            int j;
            for(j=i+1;j<var;j++)if(a[i][j])break;
            if(j>=var)break;
            for(int kk=0;kk<equ;kk++)swap(a[kk][i],a[kk][j]);
        }
    }
    int ret=999999;
    if(k<var){
        for(int i=0;i<(1<<(var-k));i++){
            memset(x,0,sizeof(x));
            int now=0;
            for(int j=0;j<var-k;j++){
                if(i&(1<<j)){
                    x[var-j-1]=1;
                    now++;
                }
            }
            for(int j=k-1;j>=0;j--){
                x[j]=a[j][var];
                for(int kk=j+1;kk<=var;kk++){
                    if(a[j][kk])x[j]^=x[kk];
                }
                if(x[j])now++;
            }
            ret=min(ret,now);
        }
    }else{
        ret=0;
        for(int i=var-1;i>=0;i--){
            x[i]=a[i][var];
            for(int j=i+1;j<var;j++){
                if(a[i][j])x[i]^=x[j];
            }
            if(x[i])ret++;
        }
    }
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",mp[i]);
        }
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mp[i][j]=='w')a[g(i,j)][n*n]=1;
                a[g(i,j)][g(i,j)]=1;
                if(i>0)a[g(i,j)][g(i-1,j)]=1;
                if(i<n-1)a[g(i,j)][g(i+1,j)]=1;
                if(j>0)a[g(i,j)][g(i,j-1)]=1;
                if(j<n-1)a[g(i,j)][g(i,j+1)]=1;
            }
        }
        int ans=Gauss(n*n,n*n);
        if(ans==-1){
            printf("inf\n");
        }else{
            printf("%d\n",ans);
        }
    }
    return 0;
}

