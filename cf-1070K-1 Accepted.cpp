
#include<cstdio>
int a[100010];
int r[100010];
int main(){
    int n,k,sum=0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(sum%k){
        printf("No\n");
        return 0;
    }
    int d=sum/k,p=0;
    bool ans=true;
    for(int i=0;i<k;++i){
        int cnt=0,now=0;
        while(now<d)now+=a[p],++p,++cnt;
        if(now>d){
            ans=false;
            break;
        }
        r[i]=cnt;
    }
    if(ans){
        printf("Yes\n");
        for(int i=0;i<k;++i){
            if(i)printf(" ");
            printf("%d",r[i]);
        }
        printf("\n");
    }else{
        printf("No\n");
    }
    return 0;
}

