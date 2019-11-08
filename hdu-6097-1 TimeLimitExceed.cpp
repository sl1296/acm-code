

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
double r;
double dx1,dy1,dx2,dy2;
double dis(double x1,double y1,double x2,double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double cal(double x){
    double xx=r*cos(x);
    double yy=r*sin(x);
    return dis(xx,yy,dx1,dy1)+dis(xx,yy,dx2,dy2);
}
double test[700];
int cnt;
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%lf",&r);
        scanf("%lf%lf",&dx1,&dy1);
        scanf("%lf%lf",&dx2,&dy2);
        double mmin=99999999;
        double ansx,ansy;
        cnt=0;
        double mmax=0;
        int pos;
        for(double i=0;i<6.29;i+=0.01){
            double tpx=r*cos(i);
            double tpy=r*sin(i);
            test[cnt]=dis(tpx,tpy,dx1,dy1)+dis(tpx,tpy,dx2,dy2);
          //  printf("%.2f ",test[cnt]);
            if(test[cnt]>mmax){
                mmax=test[cnt];
                pos=cnt;
            }
            cnt++;
        }
        int pp;
        int ff[5],ee[5],cfe=0;
        bool is=false;
       // printf("cnt=%d pos=%d\n",cnt,pos);
        for(int p=0,i=pos;p<cnt;p++,i++){
          //  printf("%d %d %d\n",p,i,cnt);
          //  printf("%f %f",test[i%cnt],test[(i-1)%cnt]);
            if(test[i%cnt]<test[(i-1)%cnt]){
                pp=i%cnt;
                is=true;
            }
            else if(test[i%cnt]>test[(i-1)%cnt]&&is==true){
                ff[cfe]=pp;
                ee[cfe]=i%cnt;
                cfe++;
              //  printf("cfe=%d\n",cfe);
                is=false;
            }
        }
        for(int i=0;i<cfe;i++){
            double ffrom=ff[i]*0.01-0.1;
            double tto=ee[i]*0.01+0.1;
           // printf("%f %f\n",ffrom,tto);
            while(tto-ffrom>1e-14){
                double m1=(ffrom*2+tto)/3;
                double m2=(ffrom+tto*2)/3;
                if(cal(m1)>cal(m2)){
                    ffrom=m1;
                }else{
                    tto=m2;
                }
            }
            mmin=min(mmin,cal(ffrom));
        }
        printf("%.7f\n",mmin);
       // int cnt=0;
      /*  for(double i=-r; i<=r; i+=0.01) {
            double t1=sqrt(r*r-i*i);
            double now=dis(dx1,dy1,i,t1)+dis(dx2,dy2,i,t1);
           // printf("%4.2f ",now);
           // cnt++;
            if(cnt%29==0)printf("\n");
            if(now<mmin) {
                mmin=now;
                ansx=i;
                ansy=t1;
            }
            double t2=-sqrt(r*r-i*i);
            now=dis(dx1,dy1,i,t2)+dis(dx2,dy2,i,t2);
            if(now<mmin) {
                mmin=now;
                ansx=i;
                ansy=t2;
            }
        }*/
       /* printf("%.7f\n",mmin);
        printf("ansx=%f,ansy=%f\n",ansx,ansy);
        double ex1=ansx-dx1;
        double ey1=ansy-dy1;
        double ex2=ansx-dx2;
        double ey2=ansy-dy2;
        printf("cos=%f\n",(ex1*ex2+ey1*ey2)/(dis(ansx,ansy,dx1,dy1)*dis(ansx,ansy,dx2,dy2)));
        printf("zccos=%f\n",(ansx*(dx1-dx2)+ansy*(dy1-dy2))/(dis(ansx,ansy,0,0)*dis(dx1,dy1,dx2,dy2)));*/
    }
    return 0;

}

