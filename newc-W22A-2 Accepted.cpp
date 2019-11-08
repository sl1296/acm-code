
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,m,a,r;
    scanf("%d%d",&n,&m);
    r=m;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        r=__gcd(r,a);
    }
    printf("%d\n",m/r);
    return 0;
}

