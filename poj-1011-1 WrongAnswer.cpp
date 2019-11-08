
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,a[70],sum,tot,is[70],r;
int cmp(const void *a,const void *b){
    return *(int*)b-*(int*)a;
}
void dfs(int x,int now,int count){
   // printf("%d %d %d\n",x,now,count);
    int i;
    if(now==0){
        if(count==tot){
            r=1;
            return;
        }
        i=0;
        while(is[i])i++;
        is[i]=1;
        dfs(x,a[i],count);
        if(r)return;
    }else{
        for(i=0;i<n;i++){
            if(!is[i]){
                if(now+a[i]==x){
                    is[i]=1;
                    dfs(x,0,count+1);
                    if(r)return;
                }else if(now+a[i]<x){
                    is[i]=1;
                    dfs(x,now+a[i],count);
                    if(r)return;
                    is[i]=0;
                    while(i+1<n && a[i+1]==a[i])i++;
                }
            }
        }
    }
}
int main(){
    int i;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        sum=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        qsort(a,n,sizeof(int),*cmp);
        r=0;
        for(i=a[0];i<sum;i++){
            if(sum%i)continue;
            tot=sum/i;
            memset(is,0,sizeof(is));
            dfs(i,0,0);
            if(r)break;
        }
        printf("%d\n",i);
    }
    return 0;
}

