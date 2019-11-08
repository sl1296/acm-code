
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k)){
        int mx=99999999;
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            if(i%2==0)mx=min(mx,a);
        }
        if(n&1){
            int op=(n+1)/2;
            int cnt=min(m/op*k,mx);
            printf("%d\n",cnt);
        }else{
            printf("0\n");
        }
    }
    return 0;
}

