
#include<cstdio>
#include<cstring>
int x[10];
int vis[120010];
int main(){
    int cas=1;
    while(1){
        int sum=0;
        for(int i=1;i<=6;i++){
            scanf("%d",&x[i]);
            sum+=x[i]*i;
        }
        if(sum==0)break;
        printf("Collection #%d:\n",cas++);
        if(sum%2==1){
            printf("Can't be divided.\n\n");
            continue;
        }
        memset(vis,-1,sizeof(vis));
        vis[0]=0;
        for(int i=1;i<=6;i++){
            for(int j=0;j<=sum;j++){
                if(vis[j]>=0)vis[j]=x[i];
                else if(j>=i&&vis[j-i]>0)vis[j]=vis[j-i]-1;
            }
        }
        if(vis[sum/2]>=0){
            printf("Can be divided.\n\n");
        }else{
            printf("Can't be divided.\n\n");
        }
    }
    return 0;
}

