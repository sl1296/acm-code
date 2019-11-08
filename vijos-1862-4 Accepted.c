
#include <stdio.h>
#include <string.h>
#include <Stdlib.h>
__int64 n,a[10000],b[10000],ls,ans,l,ord;
int ca,cb;
int cmp(const void *a,const void *b){
    return *(__int64*)b-*(__int64*)a;
}
void dfs(int num,__int64 now,__int64 s){
    if(num==cb || now==1 || s>ans)return;
    ord=b[num]-1;
    if(now%ord!=0)dfs(num+1,now,s);
    else{
        ls=now/ord;
        l=s/ord*b[num];
        dfs(num+1,ls,l);
        while(ls%b[num]==0){
            ls/=b[num];
            dfs(num+1,ls,l);
        }
        if(ls==1)ans=ans>l?l:ans;
        dfs(num+1,now,s);
    }
}
int main(){
    int t,z;
    __int64 i,j;
    scanf("%d",&t);
    for(z=0;z<t;z++){
        ca=cb=0;
        scanf("%I64d",&n);
        for(i=1;i*i<=n;i++){
            if(n%i==0){
                a[ca]=i;
                ca++;
                if(i*i<n){
                    a[ca]=n/i;
                    ca++;
                }
            }
        }
        for(i=0;i<ca;i++){
            ls=a[i]+1;
            for(j=2;j*j<=ls;j++)if(ls%j==0)break;
            if(j*j>ls){
                b[cb]=ls;
                cb++;
            }
        }
        qsort(b,cb,sizeof(__int64),*cmp);
        ans=(n==1)?1:n*10;
        dfs(0,n,n);
        printf("%I64d\n",ans);
    }
    return 0;
}


