
#include <cstdio>
#include <cstring>
#include <cstdlib>
int main(){
    int t,z,n,k,i,p,l,pre;
    scanf("%d",&t);
    for(z=0;z<t;z++){
        p=1;
        scanf("%d%d",&n,&k);
        l=0;
        for(i=2;i<=n;i++){
            l=(l+k%i)%i;
        }
      //  printf("%d ",l);
        printf("Case %d: %d\n",z+1,l+1);
    }
    return 0;
}

