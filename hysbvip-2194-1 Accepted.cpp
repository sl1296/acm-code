
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const double PI=acos(-1.0);
struct complex{
    double x,y;
    complex(double _x=0.0,double _y=0.0){
        x=_x;
        y=_y;
    }
    complex operator - (const complex &b) const{
        return complex(x-b.x,y-b.y);
    }
    complex operator + (const complex &b) const{
        return complex(x+b.x,y+b.y);
    }
    complex operator * (const complex &b) const{
        return complex(x*b.x-y*b.y,x*b.y+y*b.x);
    }
};
void change(complex y[],int len){
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
void fft(complex y[],int len,int on){
    change(y,len);
    for(int h=2;h<=len;h<<=1){
        complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j=0;j<len;j+=h){
            complex w(1,0);
            for(int k=j;k<j+h/2;k++){
                complex u=y[k];
                complex t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(on==-1)for(int i=0;i<len;i++)y[i].x/=len;
}
int a[100010],b[100010];
complex t1[300010],t2[300010];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[n-i-1],&b[i]);
        }
        int len1=n,len2=n,len=1;
        while(len<n*2)len<<=1;
        for(int i=0;i<len1;i++)t1[i]=complex(a[i],0);
        for(int i=len1;i<len;i++)t1[i]=complex(0,0);
        for(int i=0;i<len2;i++)t2[i]=complex(b[i],0);
        for(int i=len2;i<len;i++)t2[i]=complex(0,0);
        fft(t1,len,1);
        fft(t2,len,1);
        for(int i=0;i<len;i++)t1[i]=t1[i]*t2[i];
        fft(t1,len,-1);
        int ans;
        for(int i=n-1;i>-1;i--){
            ans=(int)(t1[i].x+0.5);
            printf("%d\n",ans);
        }
    }
    return 0;
}



