
#include <stdio.h>
int main(){
    int t,n,a[50],ans,c,i;
    scanf("%d",&t);
    while(t--){
        ans=0;
        c=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            ans=ans^a[i];
            if(a[i]>1)c++;
        }
        if(ans){
            if(c)printf("John\n"); else printf("Brother\n");
        }else{
            if(c)printf("Brother\n"); else printf("John\n");
        }
    }
    return 0;
}

