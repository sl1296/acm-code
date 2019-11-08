
#include <stdio.h>
int euler[2020];
int g[2010][2010];
long long gcd(long long a,long long b){
    return b?gcd(b,a%b):a;
}
long long find(long long y,long long i){
    long long count=1,j;
    if(!y)return 0;
    for(j=2;j<=i;j++){
        if(!g[j][i])g[j][i]=gcd(j,i);
        if(g[j][i]==1)count++;
    }
    return count;
}
int main(){
    long long a,b,t,i,j,x,y,r,e;
    double re;
    for(i=1;i<2010;i++)euler[i]=i;
    for(i=2;i<2010;i++)if(euler[i]==i)for(j=i;j<2010;j+=i)euler[j]=euler[j]/i*(i-1);
    while(1){
        scanf("%lld%lld",&a,&b);
        if(!a && !b)break;
        r=0;
        if(a<b){t=a;a=b;b=t;}
        for(i=1;i<=b;i++){
            x=a/i;y=a%i;
            r=r+x*euler[i]+find(y,i);
        }
        r=r*4+4;
        e=(a*2+1)*(b*2+1)-1;
        re=(double)r/e;
        printf("%.7lf\n",re);
    }
    return 0;
}

