
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
int a[100010];
bitset<10010> bs[10010];
int main(){
    for(int i=0;i<=10010;i++)bs[i][0]=true;
    for(int i=1;i<=10010;i++)for(int j=1;j<=i;j++)bs[i][j]=(bs[i-1][j]^bs[i-1][j-1]);
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cas++);
        while(q--){
            int l,r;
            scanf("%d%d",&l,&r);
            int len=r-l+1;
            int ans=0;
            for(int i=0;i<len;i++){
                if(bs[len-1][i])ans^=a[i+l];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}


