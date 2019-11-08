
#include <cstdio>
#include <cmath>
using namespace std;
#define LL unsigned long long
LL re[50],rn[50];
LL sum,ma,mb;
int rc;
void dfs(int z,LL a,LL b){
  //  printf("%d %llu %llu\n",z,a,b);
    LL ls;
    if(a+b>=sum)return;
    if(z<rc){
        ls=pow(re[z],rn[z]);
        dfs(z+1,a*ls,b);
        dfs(z+1,a,b*ls);
    }else{
        if(a+b<sum){
            sum=a+b;
            ma=a;
            mb=b;
        }
    }
}
int main(){
    LL gcd,lcm,d,ld;
    int i;
    while(scanf("%llu%llu",&gcd,&lcm)!=EOF){
        sum=18446744073709551615llu;
       // printf("%llu ",sum);getchar();
        rc=0;
        d=lcm/gcd;
        ld=d;
        for(i=2;i*i<=d;i++){
            if(d%i==0){
                re[rc]=i;
                d/=i;
                rn[rc]=1;
                while(d%i==0){
                    d/=i;
                    rn[rc]++;
                }
                rc++;
              //  printf("%di ",i);
            }
            if(d==1)break;
        }
        if(d>1){re[rc]=d;rn[rc]=1;rc++;}
      //  printf("rc=%d %llu",rc,d);
        dfs(0,1,1);
        if(ma>mb)printf("%llu %llu\n",mb*gcd,ma*gcd);
        else printf("%llu %llu\n",ma*gcd,mb*gcd);
    }
}

