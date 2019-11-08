
#include <stdio.h>
int min(int a,int b){
    return a>b?b:a;
}
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int n,a[55],i,j,l,b[55],c[55],d[55],cc;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        b[1]=a[1];
        for(i=2;i<=n;i++){
            b[i]=b[i-1]+min(a[i-1],a[i])*2;
            for(j=i-2;j>0;j--){
                l=b[j]+min(a[j],a[i])*2;
                if(l>b[i])b[i]=l;
            }
        }
        c[1]=a[1]+b[1];
        d[n]=b[n]-a[n];
        d[n+1]=a[n]+b[n];
        c[0]=0;
        for(i=2;i<n;i++){
            c[i]=max(c[i-1],a[i]+b[i]);
            d[n-i+1]=min(d[n-i+2],b[n-i+1]-a[n-i+1]);
        }
        cc=0;
        for(i=1;i<=n;i++)if(d[i+1]-c[i-1]>0){
            if(cc)printf(" ");
            printf("%d",i);
            cc++;
        }
        printf("\n");
    }
    return 0;
}

