
#include <stdio.h>
int main(){
    int n,k,p=0;
    scanf("%d%d",&n,&k);
    if(k<=n){
        printf("%d\n",n-k);
        return 0;
    }else if(k/2<n){
        printf("%d\n",k-n);
        return 0;
    }else{
        while(k>n){
            if(k%2==0){
                k/=2;
                p+=1;
            }else if((k-1)%4==0){
                k=(k-1)/4;
                p+=3;
            }else if(k!=3){
                k=(k+1)/4;
                p+=3;
            }else{
                k--;
                p++;
            }
            if(k<n){
                printf("%d\n",p+n-k);
                return 0;
            }
        }
    }
    printf("%d\n",p);
    return 0;
}

