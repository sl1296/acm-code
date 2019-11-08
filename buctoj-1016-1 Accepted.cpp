
#include<cstdio>
long long a[100010],b[100010];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i){
            scanf("%lld",&a[i]);
        }
        b[n]=0;
        for(int i=n-1,j=1;i>=0;--i,++j){
            b[i]=b[i+1]+a[i]*j;
        }
        for(int i=0;i<n;++i){
            if(i)printf(" ");
            printf("%lld",b[i]);
        }
        printf("\n");
    }
    return 0;
}
 
/**************************************************************
    Problem: 1016
    User: asdcvbn
    Language: C++
    Result: ÕýÈ·
    Time:53 ms
    Memory:2680 kb
****************************************************************/

