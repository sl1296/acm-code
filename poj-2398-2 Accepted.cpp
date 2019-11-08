
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
    bool operator < (const Line &q) const{
        return p.x<q.p.x;
    }
};
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
Line l[5010];
int cnt[5010];
int re[5010];
int main(){
    int n,m,x1,y1,x2,y2;
    while(1){
        memset(cnt,0,sizeof(cnt));
        memset(re,0,sizeof(re));
        scanf("%d",&n);
        if(!n)break;
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        for(int i=0;i<n;i++){
            int u,ll;
            scanf("%d%d",&u,&ll);
            l[i]=Line(Point(u,y1),Point(ll,y2));
        }
        l[n]=Line(Point(x2,y1),Point(x2,y2));
        sort(l,l+n+1);
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            Point tt=Point(x,y);
            for(int j=0;j<=n;j++){
                Vector xx=tt-l[j].p;
                if(Cross(l[j].v,xx)<-eps){
                    cnt[j]++;
                    break;
                }
            }
        }
        for(int i=0;i<=n;i++){
            re[cnt[i]]++;
        }
        printf("Box\n");
        for(int i=1;i<=n;i++){
            if(re[i]){
                printf("%d: %d\n",i,re[i]);
            }
        }
    }
    return 0;
}

