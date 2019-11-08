
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int n ;
    while(~scanf("%d",&n)){
        int k1 = sqrt(n) ;
        bool f1 = false ;
        bool f2 = false ;
        if(n==0)return 0;
        if(k1*k1==n||(k1-1)*(k1-1)==n||(k1+1)*(k1+1)==n){
            f1 = true ;
        }
        int k2 = pow(n,1.0/3) ;
        if(k2*k2*k2==n||(k2-1)*(k2-1)*(k2-1)==n||(k2+1)*(k2+1)*(k2+1)==n){
            f2 = true ;
        }
        if(f1&f2){
            printf("Special\n") ;
        }else{
            printf("Ordinary\n") ;
        }
    }
    return 0;
}


