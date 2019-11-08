
#include <stdio.h>
__int64 max=0,m=0,n;
__int64 zs[10]={2,3,5,7,11,13,17,19,23};
void f(__int64 r,__int64 c,int num){
    int i=1;
    if(c>m){
        max=r;m=c;
    }
    if(num>7)return;
    while(r<=n){
        f(r,c*i,num+1);
        r*=zs[num];
        i++;
    }
}
int main(){
    scanf("%I64d",&n);
    f(1,1,0);
    printf("%I64d\n",max);
    return 0;
}

