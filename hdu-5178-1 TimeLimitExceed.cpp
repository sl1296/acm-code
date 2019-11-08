
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[100010];
__int64 ans;
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int main(){
    int t,n,k,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        ans=0;
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        qsort(a,n,sizeof(int),*cmp);
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                if(a[j]-a[i]>k)break;
            }
            ans+=(j-i-1);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

