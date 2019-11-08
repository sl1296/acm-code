
#include<bits/stdc++.h>
using namespace std;
const long double eps=1e-14;
const long double PI=acos(-1.0);
inline int sgn(long double x){
    if(fabs(x)<eps)return 0;
    if(x<0)return -1;
    return 1;
}
inline long double dis(long double a,long double b,long double c,long double d){
    return sqrt((c-a)*(c-a)+(d-b)*(d-b));
}
inline long double dis2(long double a,long double b,long double c,long double d){
    return (c-a)*(c-a)+(d-b)*(d-b);
}
int main(){
    ios::sync_with_stdio(0);
    int t;
//    scanf("%d",&t);
    cin>>t;
    cout <<setiosflags(ios::fixed);
    cout<<setprecision(12);
    while(t--){
        long double xa,ya,xb,yb,xc,yc,w;
//        scanf("%lf%lf%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&xc,&yc,&w);
        cin>>xa>>ya>>xb>>yb>>xc>>yc>>w;
        long double x=dis(xa,ya,xb,yb),y=dis(xb,yb,xc,yc),z=dis(xc,yc,xa,ya);
        long double xx=dis2(xa,ya,xb,yb),yy=dis2(xb,yb,xc,yc),zz=dis2(xc,yc,xa,ya);
        if(x<y)swap(x,y);if(x<z)swap(x,z);if(y<z)swap(y,z);
        long double p=(x+y+z)/2,s=sqrt(p*(p-x)*(p-y)*(p-z)),h=s*2/x;
        if(sgn(w-x)>=0){
//            printf("%.9f\n",h);
            cout<<h<<endl;
            continue;
        }
        if(sgn(w-h)<0){
//            printf("impossible\n");
            cout<<"impossible"<<endl;
            continue;
        }
        long double ry=acos((xx+zz-yy)/(2*x*z)),rz=acos((xx+yy-zz)/(2*x*y));
        long double ans=x,ss=0,ee=PI/2-ry,mid,a,b,c,d,len,lh;
        long double zero=0.0;
        while(ee-ss>eps){
            mid=(ss+ee)/2;
            a=x*cos(mid);
            b=x*sin(mid);
            c=z*cos(ry+mid);
            d=z*sin(ry+mid);
            len=max(max(a,c),zero)-min(min(a,c),zero);
            lh=max(b,d);
            if(sgn(len-w)>0)ss=mid;
            else ee=mid;
        }
        ans=min(ans,lh);
        if(PI/2-ry<rz)
        {
            ss=PI/2-ry;ee=rz;
            while(ee-ss>eps){
                mid=(ss+ee)/2;
                a=x*cos(mid);
                b=x*sin(mid);
                c=z*cos(ry+mid);
                d=z*sin(ry+mid);
                len=max(max(a,c),zero)-min(min(a,c),zero);
                lh=max(b,d);
                if(sgn(len-w)>0)ee=mid;
                else ss=mid;
            }
            ans=min(ans,lh);
        }
        ss=max(PI/2-ry,rz);ee=PI/2;
        while(ee-ss>eps)
        {
            mid=(ss+ee)/2;
            a=x*cos(mid);
            b=x*sin(mid);
            c=z*cos(ry+mid);
            d=z*sin(ry+mid);
            len=max(max(a,c),zero)-min(min(a,c),zero);
            lh=max(b,d);
            if(sgn(len-w)>0)ss=mid;
            else ee=mid;
        }
        ans=min(ans,lh);
        ss=0;ee=PI/2-rz;
        while(ee-ss>eps){
            mid=(ss+ee)/2;
            a=x*cos(mid);
            b=x*sin(mid);
            c=y*cos(rz+mid);
            d=y*sin(rz+mid);
            len=max(max(a,c),zero)-min(min(a,c),zero);
            lh=max(b,d);
            if(sgn(len-w)>0)ss=mid;
            else ee=mid;
        }
        ans=min(ans,lh);
        if(PI/2-rz<ry)
        {
            ss=PI/2-rz;ee=ry;
            while(ee-ss>eps){
                mid=(ss+ee)/2;
                a=x*cos(mid);
                b=x*sin(mid);
                c=z*cos(ry+mid);
                d=z*sin(ry+mid);
                len=max(max(a,c),zero)-min(min(a,c),zero);
                lh=max(b,d);
                if(sgn(len-w)>0)ee=mid;
                else ss=mid;
            }
            ans=min(ans,lh);
        }
        ss=max(PI/2-rz,ry);ee=PI/2;
        while(ee-ss>eps)
        {
            mid=(ss+ee)/2;
            a=x*cos(mid);
            b=x*sin(mid);
            c=z*cos(ry+mid);
            d=z*sin(ry+mid);
            len=max(max(a,c),zero)-min(min(a,c),zero);
            lh=max(b,d);
            if(sgn(len-w)>0)ss=mid;
            else ee=mid;
        }
        ans=min(ans,lh);
//        printf("%.9f\n",ans);
        cout<<ans<<endl;
    }
    return 0;
}

