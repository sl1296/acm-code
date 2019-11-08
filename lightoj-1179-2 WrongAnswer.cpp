
#include <cstdio>
#include <cstring>
#include <cstdlib>
int main(){
    int t,z,n,k,i,p,l,pre;
    scanf("%d",&t);
    for(z=0;z<t;z++){
        p=1;
        scanf("%d%d",&n,&k);
        pre=0;
        for(i=2;i<=n;i++){
            l=k%i;
            l=(pre-l+i)%i;
            if(l==0)l=i;
            if(pre-l>2)l++;
            pre=l;
            if(l<=p)p++;
        //    printf("%d %d\n",l,p);
        }
      //  printf("%d ",l);
        p=(p+k%n-l+n)%n;
        if(p==0)p=n;
        printf("Case %d: %d\n",z+1,p);
    }
    return 0;
}

