
#include<cstdio>
#define ll long long
ll stir1[30][30];
ll jc[25]={1};
int main(){
    for(int i=1;i<21;i++)jc[i]=jc[i-1]*i;
    for(int i=0;i<21;i++)stir1[i][i]=1;
    for(int i=1;i<21;i++)for(int j=1;j<=i;j++)stir1[i][j]=(i-1)*stir1[i-1][j]+stir1[i-1][j-1];
    stir1[0][0]=0;
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        ll ans=0;
        for(int i=1;i<=k;i++)ans+=(stir1[n][i]-stir1[n-1][i-1]);
        printf("%.4f\n",(double)ans/jc[n]);
    }
    return 0;
}

