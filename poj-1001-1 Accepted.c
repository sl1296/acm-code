
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct gd{
    int num[500];
    int l,point;
}gd;
gd mul(gd x,gd y){
    gd r;
    int i,j;
    r.point=x.point+y.point;
    r.l=x.l+y.l-1;
    for(i=0;i<=r.l;i++)r.num[i]=0;
    for(i=0;i<x.l;i++){
        for(j=0;j<y.l;j++){
            r.num[i+j]+=(x.num[i]*y.num[j]);
        }
    }
    for(i=0;i<r.l;i++){
        if(r.num[i]>9){
            r.num[i+1]+=(r.num[i]/10);
            r.num[i]%=10;
        }
    }
    if(r.num[r.l]){
        i=r.l;
        while(r.num[i]>9){
            r.num[i+1]=r.num[i]/10;
            r.num[i]%=10;
            i++;
        }
        r.l=i+1;
    }else{
        i=r.l-1;
        while(r.num[i]==0 && i)i--;
        r.l=i+1;
    }
    if(r.num[0]==0 && r.l==1)r.point=0;
    if(r.l==1)return r;
    i=0;
    while(r.num[i]==0)i++;
    if(i){
        if(i>r.point)i=r.point;
        if(i){
            r.point-=i;
            for(j=i;j<r.l;j++){
                r.num[j-i]=r.num[j];
            }
            r.l-=i;
        }
    }
    return r;
}
int main(){
    char s[10];
    gd x,y;
    int n,is,i,xx;
    while(scanf("%s%d",s,&n)!=EOF){
        y.num[0]=1;
        y.l=1;
        y.point=0;
        x.l=0;
        for(i=5;i>-1;i--){
            if(s[i]=='.'){
                x.point=5-i;
                continue;
            }
            x.num[x.l]=s[i]-48;
            x.l++;
        }
        for(i=0;i<n;i++){
            y=mul(y,x);
        }
        if(y.point>=y.l)printf(".");
        xx=y.point-y.l;
        for(i=0;i<xx;i++)printf("0");
        for(i=y.l-1;i>-1;i--){
            printf("%d",y.num[i]);
            if(y.point==i && i)printf(".");
        }
        printf("\n");
    }
}

