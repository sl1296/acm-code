
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-10;
int dcmp(double x){if(fabs(x)<eps)return 0;return x<0?-1:1;}
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
Vector operator + (Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}
Vector operator - (Point a,Point b){return Vector(a.x-b.x,a.y-b.y);}
Vector operator * (Vector a,double p){return Vector(a.x*p,a.y*p);}
Vector operator / (Vector a,double p){return Vector(a.x/p,a.y/p);}
double Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double Length(Vector a){return sqrt(Dot(a,a));}
double Dis(Point a,Point b){return Length(b-a);}
struct Line{
    Point p,b;
    Vector v;
    Line(){}
    Line(Point pp,Point bb){p=pp;b=bb;v=b-p;}
};
bool opposite_side(Point p1,Point p2,Line l){
    return Cross(l.p-l.b,p1-l.b)*Cross(l.p-l.b,p2-l.b)<-eps;
}
bool same_side(Point p1,Point p2,Line l){
    return Cross(l.p-l.b,p1-l.b)*Cross(l.p-l.b,p2-l.b)>eps;
}
int dots_inline(Point p1,Point p2,Point p3){
    return dcmp(Cross(p1-p3,p2-p3))==0;
}
bool dot_online_in(Point p,Line l){
    return dcmp(Cross(p-l.b,l.p-l.b))==0&&(l.p.x-p.x)*(l.b.x-p.x)<eps&&(l.p.y-p.y)*(l.b.y-p.y)<eps;
}
int intersect_in(Line u,Line v){
    if(!dots_inline(u.p,u.b,v.p)||!dots_inline(u.p,u.b,v.b))
        return!same_side(u.p,u.b,v)&&!same_side(v.p,v.b,u);
    return dot_online_in(u.p,v)||dot_online_in(u.b,v)||dot_online_in(v.p,u)||dot_online_in(v.b,u);
}
int intersect_ex(Line u,Line v){
    return opposite_side(u.p,u.b,v)&&opposite_side(v.p,v.b,u);
}
int nn[30];
Point dpp[30][5];
double dp[30][5];
Line dl[30][5];
int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n==-1)break;
        nn[0]=nn[n+1]=1;
        dpp[0][0]=Point(0,5);
        dpp[n+1][0]=Point(10,5);
        for(int i=1;i<=n;i++){
            nn[i]=4;
            double ss;
            scanf("%lf",&ss);
            for(int j=0;j<4;j++){
                double x;
                scanf("%lf",&x);
                dpp[i][j]=Point(ss,x);
            }
            dl[i][0]=Line(Point(ss,0),dpp[i][0]);
            dl[i][1]=Line(dpp[i][1],dpp[i][2]);
            dl[i][2]=Line(dpp[i][3],Point(ss,10));
        }
        for(int i=0;i<n+2;i++){
            for(int j=0;j<4;j++){
                dp[i][j]=1e10;
            }
        }
        dp[0][0]=0;
        for(int i=1;i<n+2;i++){
            for(int j=0;j<nn[i];j++){
                for(int k=0;k<i;k++){
                    for(int l=0;l<nn[k];l++){
                        bool pd=true;
                        Line tmp=Line(dpp[i][j],dpp[k][l]);
                        for(int m=k+1;m<i;m++){
                            for(int o=0;o<3;o++){
                                if(intersect_ex(dl[m][o],tmp)){
                                    pd=false;
                                    break;
                                }
                            }
                            if(!pd)break;
                        }
                        if(pd){
                            dp[i][j]=min(dp[i][j],dp[k][l]+Dis(dpp[i][j],dpp[k][l]));
                        }
                    }
                }
            }
        }
        printf("%.2f\n",dp[n+1][0]);
    }
    return 0;
}

