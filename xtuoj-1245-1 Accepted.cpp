
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn =  100005 ;
int aa[maxn];
int n,m;
int main(){
    while(~scanf("%d%d",&n,&m)){
        int f = true ;
        for(int i=0;i<n;i++){
            aa[i] = 0x3f3f3f3f ;
        }
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c) ;
            a--;
            b--;
            if(a+1==b)aa[a] = min(aa[a],c) ;
        }
        for(int i=0;i<n-1;i++){
            if(aa[i]==0x3f3f3f3f){
                //printf("i = %d\n",i);
                f = false ;
            }
        }
        if(!f){
            printf("-1\n") ;
        }else{
            int sum = 0;
            for(int i=0;i<n-1;i++){
                sum+=aa[i] ;
            }
            printf("%d\n",sum) ;
        }


    }
    return 0;
}


