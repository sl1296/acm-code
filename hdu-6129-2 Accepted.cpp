
#include<cstdio>
int a[200010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int len=1;
        while(len<m)len<<=1;
        while(m){
            if(m>=len){
                m-=len;
                if(len<n){
                    for(int i=1;i<=n;i++){
                        if(i-len>0)a[i]^=a[i-len];
                    }
                }
            }
            len>>=1;
        }
        for(int i=1;i<=n;i++){
            if(i>1)printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}

