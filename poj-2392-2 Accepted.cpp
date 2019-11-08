
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
bool dp[40010];
struct node{
    int h,a,c;
    bool operator < (const node &p) const{
        return a<p.a;
    }
};
node a[410];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&a[i].h,&a[i].a,&a[i].c);
        }
        sort(a,a+n);
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        for(int i=0;i<n;i++){
            for(int j=a[i].a;j>=a[i].h;j--){
                if(dp[j])continue;
                for(int k=j-a[i].h,l=1;l<=a[i].c;k-=a[i].h,l++){
                    if(k<0)break;
                    if(dp[k]){
                        dp[j]=true;
                        break;
                    }
                }
            }
        }
        int ans;
        for(int i=a[n-1].a;i>=0;i--){
            if(dp[i]){
                ans=i;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

