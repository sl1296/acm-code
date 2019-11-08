
#include<cstdio>
using namespace std;
bool ca(long long x){
    int n=0;
    while(x){
        n+=x%10;
        x/=10;
    }
    if(n%10)return false;
    return true;
}
long long cal(long long x){
    long long r,s,i;
    if(x<0)return 0;
    r=x/10;
    s=x-x%10;
    for(i=s;i<=x;i++){
        if(ca(i)){
            r++;
            break;
        }
    }
    return r;
}
int main(){
    long long a,b;
    int t,z;
    scanf("%d",&t);
    for(z=1;z<=t;z++){
        scanf("%I64d%I64d",&a,&b);
        printf("Case #%d: %I64d\n",z,cal(b)-cal(a-1));
    }
    return 0;
}

