
#include<cstdio>
#include<cstring>
int cnt[100010];
int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n==0)break;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            cnt[a]++;cnt[b+1]--;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(i-1)printf(" ");
            ans+=cnt[i];
            printf("%d",ans);
        }
        printf("\n");
    }
    return 0;
}

