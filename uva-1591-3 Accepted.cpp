
#include<cstdio>
using namespace std;
int main(){
    int n,p,q;
    while(scanf("%d%d%d",&n,&p,&q)!=EOF){
        long long x=(n-1)*p,ans=1e15,tmp;
        int a=0,b=0;
        for(int i=0;i<32;i++){
            for(int j=0;j<32;j++){
                tmp=((x+(x<<i))>>j)+q;
                if(tmp>=q*n && tmp<ans){
                    ans=tmp;
                    a=i;
                    b=j;
                }
            }
        }
        printf("%d %d %d\n",(int)ans,a,b);
    }
    return 0;
}

