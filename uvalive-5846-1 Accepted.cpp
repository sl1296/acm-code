
#include<cstdio>
#include<cstring>
int x[1010],y[1010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int a;
                scanf("%d",&a);
                if(a)x[i]++,x[j]++;else y[i]++,y[j]++;
            }
        }
        int ans=n*(n-1)*(n-2)/6,sum=0;
        for(int i=1;i<=n;i++)sum+=x[i]*y[i];
        ans-=sum/2;
        printf("%d\n",ans);
    }
    return 0;
}

