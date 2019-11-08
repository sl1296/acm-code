
#include <stdio.h>
int main(){
    int n,r,t,i;
    while(scanf("%d",&n)!=EOF){
        scanf("%d",&r);
        for(i=1;i<n;i++){
            scanf("%d",&t);
            r=r^t;
        }
        if(r)printf("Yes\n"); else printf("No\n");
    }
    return 0;
}

