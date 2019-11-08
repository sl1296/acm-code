
#include <stdio.h>
int main(){
    int a,b,i,j,k,l,x,y[110],n,m,c[110];
    char s[110][110];
    scanf("%d",&x);
    for(i=0;i<x;i++){
        scanf("%d%d",&a,&b);

for(j=0;j<b;j++){scanf("%s",s[j]);/*printf("%d:%s\n",j,s[j]);*/}
        m=a;
        for(j=1;j<b;j++){
            n=0;
            for(k=0;k<a;k++){
                if(s[j][k]==s[j-1][a-1]){
                    y[n]=k;
                    n++;
                }
            }
            for(k=n-1;k>-1;k--){
                for(l=y[k]-1;l>-1;l--){
                    if(s[j][l]!=s[j-1][a-y[k]+l-1])break;
                    //3,y[k]=2,a=7,l=1,5,7-2+1-1
                }
                if(l<0)break;
            }
            if(k<0){m+=a;}else{m+=(a-y[k]-1);}
        //    printf("%d %d %d %d %d\n",i,j,m,y[k],k);
        }
        c[i]=m;
        //printf("%d %d %d\n",i,j,m);
    }
    for(i=0;i<x;i++)printf("%d\n",c[i]);
    return 0;
}

