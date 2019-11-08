
#include<bits/stdc++.h>
using namespace std;
long long a[100];
int xn;
char s[2000],x[200];
int main(){
    a[0]=a[1]=1;
    int now=2;
    s[0]=s[1]=49;
    for(int i=2;i<60;i++){
        a[i]=a[i-1]+a[i-2];
        int tmp=a[i];
        xn=0;
        while(tmp){
            x[xn++]=tmp%10+48;
            tmp/=10;
        }
        for(int j=xn-1;j>=0;j--)s[now++]=x[j];
    }
    long long n;
    scanf("%lld",&n);
    s[n]=0;
    printf("%s\n",s);
}

