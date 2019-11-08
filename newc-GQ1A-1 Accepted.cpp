
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    long long a,b,c,d,e,f;
    while(~scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f)){
        printf("%lld\n",min(a,e)+min(b,f)+min(c,d));
    }
    return 0;
}

