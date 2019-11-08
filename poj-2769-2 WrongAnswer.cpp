
#include <stdio.h>
int a[310],b[310],c,d[1000010];
int main(){
    int n,i,j,g,k,l;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&g);
        for(j=0;j<g;j++)scanf("%d",&a[j]);
        for(j=g;j<1000001;j++){
            for(k=0;k<g;k++){
                b[k]=a[k]%j;
                if(d[b[k]])break;
                d[b[k]]=1;
            }
            if(k==g)break;
            for(l=0;l<k;l++)d[b[l]]=0;
        }
        printf("%d\n",j);
    }
    return 0;
}

