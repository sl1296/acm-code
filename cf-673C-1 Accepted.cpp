
#include<bits/stdc++.h>
using namespace std;
int a[5010],ans[5010];
int cnt[5010];
int mx;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;i++){
            memset(cnt,0,sizeof(cnt));
            mx=a[i];
            for(int j=i;j<n;j++){
                cnt[a[j]]++;
                if(cnt[a[j]]>cnt[mx] || (cnt[a[j]]==cnt[mx] && a[j]<mx))mx=a[j];
                ans[mx]++;
              //  printf("%d %d %d\n",i,j,mx);
            }
        }
        for(int i=1;i<=n;i++){
            if(i!=1)printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}

