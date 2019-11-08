
#include <stdio.h>
int zsn,zs[50];
int main(){
    int n,i,r,c=0;
    while(1){
        c++;
        scanf("%d",&n);
        if(!n)break;
        zsn=0;
        r=0;
        for(i=2;i*i<=n;i++){
            if(n%i==0){
                zs[zsn]=i;
                n/=i;
                while(n%i==0){
                    n/=i;
                    zs[zsn]*=i;
                }
                zsn++;
            }
            if(n==1)break;
        }
        if(n>1){
            zs[zsn]=n;
            zsn++;
        }
        for(i=0;i<zsn;i++)r+=zs[i];
        if(zsn<2)r++;
        printf("Case %d: %d\n",c,r);
    }
    return 0;
}

