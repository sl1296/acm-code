
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const double eps=1e-10;
const double PI = acos(-1.0);
int dcmp(double x){if(fabs(x)<eps)return 0;return x<0?-1:1;}
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
Vector operator - (Point a,Point b){return Vector(a.x-b.x,a.y-b.y);}
struct Line{
    Point p,b;
    Vector v;
    double ang;
    Line(){}
    Line(Point pp,Point bb){p=pp;b=bb;v=b-p;}
};
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
Line l[5010];
Vector v[5010];
int cnt[5010];
int main(){
    int n,m,x1,y1,x2,y2,cas=0;
    while(1){
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
        if(!n)break;
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        for(int i=0;i<n;i++){
            int u,ll;
            scanf("%d%d",&u,&ll);
            l[i]=Line(Point(u,y1),Point(ll,y2));
            v[i]=l[i].b-l[i].p;
        }
        l[n]=Line(Point(x2,y1),Point(x2,y2));
        v[n]=l[n].b-l[n].p;
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            Point tt=Point(x,y);
            for(int j=0;j<=n;j++){
                Vector xx=tt-l[j].p;
                if(Cross(v[j],xx)<-eps){
                    cnt[j]++;
                    break;
                }
            }
        }
        if(cas)printf("\n");
        for(int i=0;i<=n;i++){
            printf("%d: %d\n",i,cnt[i]);
        }
        cas++;
    }
    return 0;
}

