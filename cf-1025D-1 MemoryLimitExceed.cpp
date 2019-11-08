
#include<cstdio>
#include<algorithm>
using namespace std;
int a[710];
char dp[710][710][710],c[710][710];
bool cal(int l,int r,int m){
//    printf("%d %d %d %d\n",l,r,m,dp[l][r][m]);
    if(dp[l][r][m])return dp[l][r][m]==1;
    if(l==m){
        for(int i=l+1;i<=r;++i){
//            printf("i=%d %d\n",i,c[l][i]);
            if(c[l][i] && cal(l+1,r,i)){
                dp[l][r][m]=1;
//                printf("%d %d %d:%d\n",l,r,m,dp[l][r][m]);
                return true;
            }
        }
    }else if(r==m){
        for(int i=l;i<r;++i){
//            printf("i=%d\n",i);
            if(c[i][r] && cal(l,r-1,i)){
                dp[l][r][m]=1;
//                printf("%d %d %d:%d\n",l,r,m,dp[l][r][m]);
                return true;
            }
        }
    }else{
        bool pd=false;
        for(int i=l;i<m;++i){
//            printf("i=%d %d\n",i,c[i][m]);
            if(c[i][m] && cal(l,m-1,i)){
                pd=true;
                break;
            }
        }
        if(pd==false){
            dp[l][r][m]=2;
            return false;
        }
        for(int i=m+1;i<=r;++i){
//            printf("i=%d\n",i);
            if(c[m][i] && cal(m+1,r,i)){
                dp[l][r][m]=1;
//                printf("%d %d %d:%d\n",l,r,m,dp[l][r][m]);
                return true;
            }
        }
    }
    dp[l][r][m]=2;
//                printf("%d %d %d:%d\n",l,r,m,dp[l][r][m]);
    return false;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        dp[i][i][i]=1;
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(__gcd(a[i],a[j])>1)c[i][j]=c[j][i]=1;
        }
    }
    bool ans=false;
    for(int i=0;i<n;++i){
        if(cal(0,n-1,i)){
            ans=true;
            break;
        }
    }
    if(ans)printf("Yes\n");
    else printf("No\n");
}


