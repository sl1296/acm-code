
#include <cstdio>
#include <cmath>
using namespace std;
#define LL unsigned long long
LL re[50];
LL sum,ma,mb;
int rc;
void dfs(int z,LL a,LL b){
   // printf("%d %llu %llu\n",z,a,b);
    LL ls;
    if(a+b>=sum)return;
    if(z<rc){
       // printf("%llu %llu ls=%llu",re[z],rn[z],ls);
        dfs(z+1,a*re[z],b);
        dfs(z+1,a,b*re[z]);
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
        sum=lcm*2;
       // printf("%llu ",sum);getchar();
        rc=0;
        d=lcm/gcd;
        ld=d;
        for(i=2;i*i<=d;i++){
            if(d%i==0){
                re[rc]=i;
                d/=i;
                while(d%i==0){
                    d/=i;
                    re[rc]*=i;
                }
                rc++;
              //  printf("%di ",i);
            }
            if(d==1)break;
        }
        if(d>1){re[rc]=d;rc++;}
    //    for(i=0;i<rc;i++)printf("%llu\n",re[i]);
      //  printf("rc=%d %llu",rc,d);
        dfs(0,1,1);
        ma*=gcd;mb*=gcd;
        if(ma>mb)printf("%llu %llu\n",mb,ma);
        else printf("%llu %llu\n",ma,mb);
    }
}

