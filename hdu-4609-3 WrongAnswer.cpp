
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
#include<cstdlib>
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
complex x1[400010];
int a[100010];
long long num[400010],sum[400010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,le,len=1;
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            num[a[i]]++;
        }
        sort(a,a+n);
        le=a[n-1]+1;
        while(len<2*le)len<<=1;
        for(int i=0;i<le;i++)x1[i]=complex(num[i],0);
        for(int i=le;i<len;i++)x1[i]=complex(0,0);
        fft(x1,len,1);
        for(int i=0;i<len;i++)x1[i]=x1[i]*x1[i];
        fft(x1,len,-1);
        for(int i=0;i<len;i++)num[i]=(int)(x1[i].x+0.5);
        len=2*a[n-1];
        for(int i=0;i<n;i++)num[a[i]+a[i]]--;
        sum[0]=0;
        for(int i=1;i<=len;i++)sum[i]=sum[i-1]+num[i]/2;
        long long cnt=0;
        for(int i=0;i<n;i++)cnt=cnt+sum[len]-sum[a[i]]-n+1-(long long)i*(n-1-i)-(long long)(n-1-i)*(n-i-2)/2;
        long long tot = (long long)n*(n-1)*(n-2)/6;
        printf("%.7lf\n",(double)cnt/tot);
    }
    return 0;
}

