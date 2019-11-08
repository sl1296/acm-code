
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int c[1010][1010];
int n;
int low(int x){
    return x&(-x);
}
void ad(int x,int y){
    int i,j;
    for(i=x;i<=n;i+=low(i))for(j=y;j<=n;j+=low(j))c[i][j]++;
}
int find(int x,int y){
    int i,j,r=0;
    for(i=x;i>0;i-=low(i))for(j=y;j>0;j-=low(j))r+=c[i][j];
    return r%2;
}
int main(){
    int t,x,i,x1,x2,y1,y2;
    char s[3];
    scanf("%d",&t);
    while(t--){
        memset(c,0,sizeof(c));
        scanf("%d%d",&n,&x);
        for(i=0;i<x;i++){
            scanf("%s",s);
            if(s[0]=='C'){
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);x1++;y1++;x2++;y2++;
                ad(x2,y2);ad(x1-1,y1-1);ad(x1-1,y2);ad(x2,y1-1);
            }else{
                scanf("%d%d",&x1,&y1);
                printf("%d\n",find(x1,y1));
            }
        }
    }
    return 0;
}

