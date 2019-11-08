
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int t;
long long a[10010],b[20010],la,lb,y;
long long gcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    long long q=gcd(b,a%b,x,y);
    long long t=x;x=y;y=t-a/b*x;
    return q;
}
int get(){
    int i;
    memset(b,0,sizeof(b));
    b[0]=a[0];
    for(i=1;i<2*t;i++)b[i]=(la*b[i-1]+lb)%10001;
    for(i=1;i<t;i++)if(b[i*2]!=a[i])return 0;
    return 1;
}
int main(){
    int i;
    scanf("%d",&t);
    for(i=0;i<t;i++)scanf("%d",&a[i]);
    for(i=0;i<10001;i++){
        la=i;
        long long temp=a[1]-la*la*a[0];
        long long t=gcd(la+1,10001,lb,y);
        if(temp%t)continue;
        lb=lb*temp/t;
        if(get())break;
    }
    for(i=0;i<t;i++)printf("%lld\n",b[i*2+1]);
    return 0;
}

