
#include<bits/stdc++.h>
using namespace std;
const double eps=1e-14;
const double PI=acos(-1.0);
inline int sgn(double x){
    if(fabs(x)<eps)return 0;
    if(x<0)return -1;
    return 1;
}
inline double dis(double a,double b,double c,double d){
    return sqrt((c-a)*(c-a)+(d-b)*(d-b));
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        double xa,ya,xb,yb,xc,yc,w;
        scanf("%lf%lf%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&xc,&yc,&w);
        double x=dis(xa,ya,xb,yb),y=dis(xb,yb,xc,yc),z=dis(xc,yc,xa,ya);
        if(x<y)swap(x,y);if(x<z)swap(x,z);if(y<z)swap(y,z);
//        printf("%f %f %f\n",x,y,z);
        double p=(x+y+z)/2,s=sqrt(p*(p-x)*(p-y)*(p-z)),h=s*2/x;
//        printf("%f %f %f\n",p,s,h);
        if(sgn(w-x)>=0){
            printf("%.9f\n",h);
            continue;
        }
        if(sgn(w-h)<0){
            printf("impossible\n");
            continue;
        }
        double ry=acos((x*x+z*z-y*y)/(2*x*z)),rz=acos((x*x+y*y-z*z)/(2*x*y));
        double ans=x,ss=0,ee=PI/2-ry,mid,a,b,c,d,len,lh,llen,llh;
        int type;
        a=x*cos(ss);
        b=x*sin(ss);
        c=z*cos(ry+ss);
        d=z*sin(ry+ss);
        len=max(max(a,c),0.0)-min(min(a,c),0.0);
        lh=max(b,d);
        a=x*cos(ee);
        b=x*sin(ee);
        c=z*cos(ry+ee);
        d=z*sin(ry+ee);
        llen=max(max(a,c),0.0)-min(min(a,c),0.0);
        llh=max(b,d);
        if(sgn((llen-w)*(len-w))>0)goto k1;
        if(sgn(llen-len)>0)type=1;else type=0;
        while(ee-ss>eps){
            mid=(ss+ee)/2;
            a=x*cos(mid);
            b=x*sin(mid);
            c=z*cos(ry+mid);
            d=z*sin(ry+mid);
            len=max(max(a,c),0.0)-min(min(a,c),0.0);
            lh=max(b,d);
            if(type==0){
                if(sgn(len-w)>0)ss=mid;
                else ee=mid;
            }else{
                if(sgn(len-w)>0)ee=mid;
                else ss=mid;
            }
        }
        ans=min(ans,lh);
        k1:
        ss=PI/2-ry;ee=rz;
        if(sgn(ee-ss)<=0)goto k2;
        a=x*cos(ss);
        b=x*sin(ss);
        c=z*cos(ry+ss);
        d=z*sin(ry+ss);
        len=max(max(a,c),0.0)-min(min(a,c),0.0);
        lh=max(b,d);
        a=x*cos(ee);
        b=x*sin(ee);
        c=z*cos(ry+ee);
        d=z*sin(ry+ee);
        llen=max(max(a,c),0.0)-min(min(a,c),0.0);
        llh=max(b,d);
        if(sgn((llen-w)*(len-w))>0)goto k2;
        if(sgn(llen-len)>0)type=1;else type=0;
        while(ee-ss>eps){
            mid=(ss+ee)/2;
            a=x*cos(mid);
            b=x*sin(mid);
            c=z*cos(ry+mid);
            d=z*sin(ry+mid);
            len=max(max(a,c),0.0)-min(min(a,c),0.0);
            lh=max(b,d);
            if(type==0){
                if(sgn(len-w)>0)ss=mid;
                else ee=mid;
            }else{
                if(sgn(len-w)>0)ee=mid;
                else ss=mid;
            }
        }
        ans=min(ans,lh);
        k2:
        ss=rz;ee=PI/2;
        if(sgn(ee-ss)<=0)goto k3;
        a=x*cos(ss);
        b=x*sin(ss);
        c=z*cos(ry+ss);
        d=z*sin(ry+ss);
        len=max(max(a,c),0.0)-min(min(a,c),0.0);
        lh=max(b,d);
        a=x*cos(ee);
        b=x*sin(ee);
        c=z*cos(ry+ee);
        d=z*sin(ry+ee);
        llen=max(max(a,c),0.0)-min(min(a,c),0.0);
        llh=max(b,d);
        if(sgn((llen-w)*(len-w))>0)goto k3;
        if(sgn(llen-len)>0)type=1;else type=0;
        while(ee-ss>eps){
            mid=(ss+ee)/2;
            a=x*cos(mid);
            b=x*sin(mid);
            c=z*cos(ry+mid);
            d=z*sin(ry+mid);
            len=max(max(a,c),0.0)-min(min(a,c),0.0);
            lh=max(b,d);
            if(type==0){
                if(sgn(len-w)>0)ss=mid;
                else ee=mid;
            }else{
                if(sgn(len-w)>0)ee=mid;
                else ss=mid;
            }
        }
        ans=min(ans,lh);
        k3:

        ss=0;ee=PI/2-rz;
        if(sgn(ee-ss)<=0)goto k4;
        a=x*cos(ss);
        b=x*sin(ss);
        c=y*cos(rz+ss);
        d=y*sin(rz+ss);
        len=max(max(a,c),0.0)-min(min(a,c),0.0);
        lh=max(b,d);
        a=x*cos(ee);
        b=x*sin(ee);
        c=y*cos(rz+ee);
        d=y*sin(rz+ee);
        llen=max(max(a,c),0.0)-min(min(a,c),0.0);
        llh=max(b,d);
        if(sgn((llen-w)*(len-w))>0)goto k4;
        if(sgn(llen-len)>0)type=1;else type=0;
        while(ee-ss>eps){
            mid=(ss+ee)/2;
            a=x*cos(mid);
            b=x*sin(mid);
            c=y*cos(rz+mid);
            d=y*sin(rz+mid);
            len=max(max(a,c),0.0)-min(min(a,c),0.0);
            lh=max(b,d);
            if(type==0){
                if(sgn(len-w)>0)ss=mid;
                else ee=mid;
            }else{
                if(sgn(len-w)>0)ee=mid;
                else ss=mid;
            }
        }
        ans=min(ans,lh);
        k4:
        ss=PI/2-rz;ee=ry;
        if(sgn(ee-ss)<=0)goto k5;
        a=x*cos(ss);
        b=x*sin(ss);
        c=y*cos(rz+ss);
        d=y*sin(rz+ss);
        len=max(max(a,c),0.0)-min(min(a,c),0.0);
        lh=max(b,d);
        a=x*cos(ee);
        b=x*sin(ee);
        c=y*cos(rz+ee);
        d=y*sin(rz+ee);
        llen=max(max(a,c),0.0)-min(min(a,c),0.0);
        llh=max(b,d);
        if(sgn((llen-w)*(len-w))>0)goto k5;
        if(sgn(llen-len)>0)type=1;else type=0;
        while(ee-ss>eps){
            mid=(ss+ee)/2;
            a=x*cos(mid);
            b=x*sin(mid);
            c=y*cos(rz+mid);
            d=y*sin(rz+mid);
            len=max(max(a,c),0.0)-min(min(a,c),0.0);
            lh=max(b,d);
            if(type==0){
                if(sgn(len-w)>0)ss=mid;
                else ee=mid;
            }else{
                if(sgn(len-w)>0)ee=mid;
                else ss=mid;
            }
        }
        ans=min(ans,lh);
        k5:
        ss=ry;ee=PI/2;
        if(sgn(ee-ss)<=0)goto k6;
        a=x*cos(ss);
        b=x*sin(ss);
        c=y*cos(rz+ss);
        d=y*sin(rz+ss);
        len=max(max(a,c),0.0)-min(min(a,c),0.0);
        lh=max(b,d);
        a=x*cos(ee);
        b=x*sin(ee);
        c=y*cos(rz+ee);
        d=y*sin(rz+ee);
        llen=max(max(a,c),0.0)-min(min(a,c),0.0);
        llh=max(b,d);
        if(sgn((llen-w)*(len-w))>0)goto k6;
        if(sgn(llen-len)>0)type=1;else type=0;
        while(ee-ss>eps){
            mid=(ss+ee)/2;
            a=x*cos(mid);
            b=x*sin(mid);
            c=y*cos(rz+mid);
            d=y*sin(rz+mid);
            len=max(max(a,c),0.0)-min(min(a,c),0.0);
            lh=max(b,d);
            if(type==0){
                if(sgn(len-w)>0)ss=mid;
                else ee=mid;
            }else{
                if(sgn(len-w)>0)ee=mid;
                else ss=mid;
            }
        }
        ans=min(ans,lh);
        k6:
        printf("%.9f\n",ans);
    }
    return 0;
}

