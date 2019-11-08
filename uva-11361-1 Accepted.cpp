
#include<cstdio>
#include<cstring>
int dp[20][110][110];
int p10[11]={1};
int a,b,k;
int dfs(int d,int mod,int cnt){
    if(d==0)return (mod==0&&cnt==0)?1:0;
    if(dp[d][mod][cnt]>=0)return dp[d][mod][cnt];
    dp[d][mod][cnt]=0;
    for(int i=0;i<10;i++)dp[d][mod][cnt]+=dfs(d-1,((mod-i)%k+k)%k,((cnt-p10[d-1]*i)%k+k)%k);
    return dp[d][mod][cnt];
}
int cal(int x){
    int xx[15],mod=0,cnt=0,xn=0;
    do{
        xx[xn++]=x%10;
        x/=10;
    }while(x);
    int ans=0;
    for(int i=xn-1;i>-1;i--){
        for(int j=0;j<=xx[i];j++){
            if(i&&j==xx[i])continue;
            ans+=dfs(i,(k-(mod+j)%k)%k,(k-(cnt+p10[i]*j)%k)%k);
        }
        mod+=xx[i];
        cnt+=xx[i]*p10[i];
    }
    return ans;
}
int main(){
    for(int i=1;i<11;i++)p10[i]=p10[i-1]*10;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&a,&b,&k);
        if(k>99){
            printf("0\n");
            continue;
        }
        memset(dp,-1,sizeof(dp));
        printf("%d\n",cal(b)-cal(a-1));
    }
    return 0;
}

