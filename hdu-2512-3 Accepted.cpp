
#include<cstdio>
#include<cmath>
#define MOD 1000
int stir2[2005][2005]={1};
int bell[2005];
int main(){
    int i,j,n,t;
    for(i=1;i<2001;i++){
        stir2[i][i]=1;
        for(j=1;j<i;j++)stir2[i][j]=(stir2[i-1][j-1]+j*stir2[i-1][j])%MOD;
    }
    for(i=1;i<2001;i++){
        bell[i]=0;
        for(j=0;j<=i;j++)bell[i]=(bell[i]+stir2[i][j])%MOD;
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d\n",bell[n]);
    }
    return 0;
}

