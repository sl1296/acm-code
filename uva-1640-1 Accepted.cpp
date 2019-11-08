
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int pow10[10], cnt[10];
int f(int d, int n){
    char s[15];
    sprintf(s,"%d",n);
    int len=strlen(s),ans=0;
    for(int i=1;i<len;i++){
        if(i==1){
            ans++;
            continue;
        }
        ans+=9*cnt[i - 1];
        if(d>0)ans+=pow10[i - 1];
    }
    int pre[10];
    for(int i=0;i<len;i++){
        pre[i]=(int)(s[i]-'0'== d);
        if(i)pre[i]+=pre[i - 1];
    }
    for(int i=0;i<len;i++){
        int maxd=s[i]-'0'-1;
        int mind=0;
        if(i==0 && len>1)mind=1;
        for(int digit=mind;digit<=maxd;digit++){
            ans+=cnt[len-i-1];
            if(i)ans+=pre[i-1]*pow10[len-i-1];
            if(digit==d)ans+=pow10[len-i-1];
        }
    }
    return ans;
}
int main(){
    pow10[0] = 1;
    for(int i=1;i<=8;i++){
        pow10[i]=pow10[i-1]*10;
        cnt[i]=pow10[i-1]*i;
    }
    int a,b;
    while(scanf("%d%d",&a,&b) && a && b){
        if(a>b)swap(a,b);
        for(int d=0;d<= 9;d++){
            if(d)printf(" ");
            printf("%d",f(d,b+1)-f(d,a));
        }
        printf("\n");
    }
    return 0;
}

