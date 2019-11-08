
#include<cstdio>
#include<cstring>
int cnt[15];
int a[110];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        int ans;
        int tt=0;
        int pre=0;
        for(int i=9;i>0;i--){
            if(!cnt[i])continue;
            for(int j=pre,k=0;k<n;j=(j+1)%n,k++){
                if(a[j]==i){
                    tt++;
                    pre=j;
                    if(j==m){
                        ans=tt;
                        goto em;
                    }
                }
            }
        }
        em:
        printf("%d\n",ans);
    }
    return 0;
}

