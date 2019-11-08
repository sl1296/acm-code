
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[50][50];
int x[50];
int Gauss(int equ,int var){
    for(int i=0;i<=var;i++){
        x[i]=0;
    }
    int col=0,k;
    for(k=0;k<equ&&col<var;k++,col++){
        int mr=k;
        for(int i=k+1;i<equ;i++){
            if(a[i][col]>a[mr][col])mr=i;
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
    for(int i=k-1;i>=0;i--){
        x[i]=a[i][var];
        for(int j=i+1;j<var;j++){
            if(a[i][j])x[i]^=x[j];
        }
    }
    return 0;
}
inline int gt(int x,int y){
    return x*6+y;
}
int mp[10][10];
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                scanf("%d",&mp[i][j]);
            }
        }
        memset(a,0,sizeof(a));
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                a[gt(i,j)][30]=mp[i][j];
                a[gt(i,j)][gt(i,j)]=1;
                if(i>0)a[gt(i-1,j)][gt(i,j)]=1;
                if(i<4)a[gt(i+1,j)][gt(i,j)]=1;
                if(j>0)a[gt(i,j-1)][gt(i,j)]=1;
                if(j<5)a[gt(i,j+1)][gt(i,j)]=1;
            }
        }
        Gauss(30,30);
        printf("PUZZLE #%d\n",z);
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                if(j)printf(" ");
                printf("%d",x[gt(i,j)]);
            }
            printf("\n");
        }
    }
    return 0;
}

