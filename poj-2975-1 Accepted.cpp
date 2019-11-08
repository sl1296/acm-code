
#include <stdio.h>
int main(){
    int n,i,ans,count,a[1010];
    while(1){
        scanf("%d",&n);
        if(!n)break;
        ans=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            ans=ans^a[i];
        }
        count=0;
        for(i=0;i<n;i++)if(a[i]>(ans^a[i]))count++;
        printf("%d\n",count);
    }
    return 0;
}

