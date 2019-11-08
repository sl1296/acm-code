
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d%d",&a,&b);
        int c=__gcd(a,b);
        int ca=0,cb=0,cc=0;
        for(int i=1;i*i<=a;++i){
            if(a%i==0){
                ca+=2;
                if(i*i==a)--ca;
            }
        }
        for(int i=1;i*i<=b;++i){
            if(b%i==0){
                cb+=2;
                if(i*i==b)--cb;
            }
        }
        for(int i=1;i*i<=c;++i){
            if(c%i==0){
                cc+=2;
                if(i*i==c)--cc;
            }
        }
        int ans=ca*cb-cc*(cc-1)/2;
        printf("%d\n",ans);
    }
    return 0;
}

