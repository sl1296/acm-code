
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int n,m,s,w,i,j,k;
    char ss[66][17];
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s",ss[i]);
    scanf("%d,%d",&w,&s);
    k=w-2;
    m=n;
    for(i=0;i<m;i++){
        for(j=0;j<s;j++){
            k++;
            if(k==n)k=0;
        }
        printf("%s\n",ss[k]);
        for(j=k+1;j<n;j++){
            strcpy(ss[j-1],ss[j]);
        }
        n--;
        k--;
    }
}

