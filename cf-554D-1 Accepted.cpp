
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll fi[100];
bool is[100];
int main(){
    fi[0]=fi[1]=1;
    for(int i=2;i<92;i++){
        fi[i]=fi[i-1]+fi[i-2];
      //  printf("%d %lld\n",i,fi[i]);
    }
    ll n,k;
    while(scanf("%lld%lld",&n,&k)!=EOF){
        for(int i=91;i>0;i--){
            is[i]=false;
            if(k>fi[i]){
                is[i]=true;
                k-=fi[i];
            }
        }
       // for(int i=91;i>0;i--)printf("%d",is[i]);
      //  printf("\n");
        int p=1;
     //   printf("n=%d\n",n);
        for(int i=n;i>0;i--){
        //    printf("i=%d p=%d is=%d\n",i,p,is[i+1]);
            if(is[i-1]==0){
                if(i!=n)printf(" ");
                printf("%d",p);
                p++;
            }else{
                if(i!=n)printf(" ");
                printf("%d",p+1);
                i--;
                if(i!=n)printf(" ");
                printf("%d",p);
                p+=2;
            }
        }
        printf("\n");
    }
    return 0;
}

