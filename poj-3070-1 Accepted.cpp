
#include <cstdio>
#include <iostream>
using namespace std;
const int MOD = 10000;
struct matrix{
    int m[2][2];
}ans,base;
matrix multi(matrix a,matrix b){
    matrix tmp;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            tmp.m[i][j]=0;
            for(int k=0;k<2;k++)tmp.m[i][j]=(tmp.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
        }
    }
    return tmp;
}
int fast_mod(int n){
    base.m[0][0]=base.m[0][1]=base.m[1][0]=1;
    base.m[1][1]=0;
    ans.m[0][0]=ans.m[1][1]=1;
    ans.m[0][1]=ans.m[1][0]=0;
    while(n){
        if(n&1)ans=multi(ans,base);
        base=multi(base,base);
        n>>=1;
    }
    return ans.m[0][1];
}
int main(){
    int n;
    while(scanf("%d",&n) && n!=-1){
        printf("%d\n",fast_mod(n));
    }
    return 0;
}

