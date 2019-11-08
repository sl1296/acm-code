
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const double PI=acos(-1.0);
struct comp{
    double x,y;
    comp(double _x=0.0,double _y=0.0){
        x=_x;
        y=_y;
    }
    comp operator - (const comp &b) const{
        return comp(x-b.x,y-b.y);
    }
    comp operator + (const comp &b) const{
        return comp(x+b.x,y+b.y);
    }
    comp operator * (const comp &b) const{
        return comp(x*b.x-y*b.y,x*b.y+y*b.x);
    }
};
char s1[100010],s2[100010];
comp t1[200010],t2[200010];
int sum[200010];
void change(comp y[],int len){
    int i,j,k;
    for(i=1,j=len/2;i<len-1;i++){
        if(i<j)swap(y[i],y[j]);
        k=len/2;
        while(j>=k){
            j-=k;
            k/=2;
        }
        if(j<k)j+=k;
    }
}
void fft(comp y[],int len,int on){
    change(y,len);
    for(int h=2;h<=len;h<<=1){
        comp wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j=0;j<len;j+=h){
            comp w(1,0);
            for(int k=j;k<j+h/2;k++){
                comp u=y[k];
                comp t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(on==-1)for(int i=0;i<len;i++)y[i].x/=len;
}
int main(){
    while(scanf("%s%s",&s1,&s2)!=EOF){
        int len1=strlen(s1),len2=strlen(s2),len=1;
        while(len<len1*2 || len<len2*2)len<<=1;
        for(int i=0;i<len1;i++)t1[i]=comp(s1[len1-i-1]-'0',0);
        for(int i=len1;i<len;i++)t1[i]=comp(0,0);
        for(int i=0;i<len2;i++)t2[i]=comp(s2[len2-i-1]-'0',0);
        for(int i=len2;i<len;i++)t2[i]=comp(0,0);
        fft(t1,len,1);
        fft(t2,len,1);
        for(int i=0;i<len;i++)t1[i]=t1[i]*t2[i];
        fft(t1,len,-1);
        for(int i=0;i<len;i++)sum[i]=(int)(t1[i].x+0.5);
        for(int i=0;i<len;i++){
            sum[i+1]+=sum[i]/10;
            sum[i]%=10;
        }
        len=len1+len2-1;
        while(sum[len]<=0 && len>0)len--;
        for(int i=len;i>=0;i--)printf("%d",sum[i]);
        printf("\n");
    }
}

