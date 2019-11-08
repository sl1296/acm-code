
#include<cstdio>
#include<algorithm>
using namespace std;
int a[710];
char dp[710][710][355],c[710][710];
bool cal(int l,int r,int m){
    char ch=(m&1)?2:0;
    int id=m>>1;
//    printf("%d %d %d %d\n",l,r,m,(dp[l][r][id]>>ch)&3);
    if((dp[l][r][id]>>ch)&3)return ((dp[l][r][id]>>ch)&3)==1;
    if(l==m){
        for(int i=l+1;i<=r;++i){
//            printf("i=%d %d\n",i,c[l][i]);
            if(c[l][i] && cal(l+1,r,i)){
                dp[l][r][id]|=(1<<ch);
//                printf("%d %d %d:%d\n",l,r,m,1);
                return true;
            }
        }
    }else if(r==m){
        for(int i=l;i<r;++i){
//            printf("i=%d\n",i);
            if(c[i][r] && cal(l,r-1,i)){
                dp[l][r][id]|=(1<<ch);
//                printf("%d %d %d:%d\n",l,r,m,1);
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
            dp[l][r][id]|=(2<<ch);
//                printf("%d %d %d:%d\n",l,r,m,2);
            return false;
        }
        for(int i=m+1;i<=r;++i){
//            printf("i=%d\n",i);
            if(c[m][i] && cal(m+1,r,i)){
                dp[l][r][id]|=(1<<ch);
//                printf("%d %d %d:%d\n",l,r,m,1);
                return true;
            }
        }
    }
    dp[l][r][id]|=(2<<ch);
//                printf("%d %d %d:%d\n",l,r,m,2);
    return false;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        dp[i][i][i>>1]|=(1<<(i&1?2:0));
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

