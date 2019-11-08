
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[100010];
int is[100010];
int s[100010];
__int64 ans;
__int64 c(int x){
    __int64 r;
    r=x*(x-1)/2;
 //   printf("r=%I64d\n",r);
    return r;
}
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int main(){
    int t,n,k,i,j,ss,l;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        memset(is,0,sizeof(is));
        ans=0;
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        qsort(a,n,sizeof(int),*cmp);
        for(i=0;i<n-1;i++){
            ss=i+1;
            if(is[i])ss=s[i];
            for(j=ss;j<n;j++){
                if(a[j]-a[i]>k)break;
            }
          //  printf(":%d %d %d\n",i,ss,j);
            for(l=ss;l<j;l++){
                is[l]=1;
                s[l]=j;
           //     printf("%d ---\n",i);
            }
            ans+=c(j-ss+1);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

