
#include<cstdio>
#include<cstring>
#define ll long long
ll d[1005][5][2],ans[1005];
int main(){
    memset(d,0,sizeof(d));
    for(int k=0;k<2;k++){
        d[1][0][k]=1;
        for(int i=2;i<=1005;i++){
            for(int j=0;j<5;j++){
                d[i][j][k]=d[i-1][j][k];
                if(j>0)d[i][j][k]+=d[i-1][j-1][k];
            }
        }
    }
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=1005;i++){
        if(i<4||i%2==1)continue;
        int r=(i+4)/2;
        ans[i]=d[r][3][0]+d[r][4][0]+d[r][4][1];
    }
    int n,cas=1;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        printf("Case %d: %lld\n",cas++,ans[n]);
    }
    return 0;
}

