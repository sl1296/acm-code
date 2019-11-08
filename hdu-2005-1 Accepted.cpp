
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int num[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    char s[40];
    int w[3],c;
    while(scanf("%s",s)!=EOF){
        num[2]=28;
        c=0;
        int l=strlen(s);
        for(int i=0;i<l;i++){
            if(s[i]=='/'){
                w[c]=i;
                c++;
            }
        }
        int y=0,d=0,m=0;
        for(int i=0;i<w[0];i++){
            y=y*10+s[i]-'0';
        }
        for(int i=w[0]+1;i<w[1];i++){
            m=m*10+s[i]-'0';
        }
        for(int i=w[1]+1;i<l;i++){
            d=d*10+s[i]-'0';
        }
        if((y%4==0 && y%100!=0) || y%400==0){
            num[2]=29;
        }
        int ans=0;
        for(int i=1;i<m;i++){
            ans+=num[i];
        }
        ans+=d;
        printf("%d\n",ans);
    }
    return 0;
}

