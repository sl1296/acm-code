
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const double eps=1e-10;
const double PI=acos(-1.0);
inline int dcmp(const double& x){if(fabs(x)<eps)return 0;return x<0?-1:1;}
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
Point operator + (const Point& a,const Point& b){return Point(a.x+b.x,a.y+b.y);}
Point operator - (const Point& a,const Point& b){return Point(a.x-b.x,a.y-b.y);}
Point operator * (const Point& a,const double& p){return Point(a.x*p,a.y*p);}
Point operator / (const Point& a,const double& p){return Point(a.x/p,a.y/p);}
inline double Cross(const Vector& a,const Vector& b){return a.x*b.y-a.y*b.x;}
inline int dots_inline(const Point& p1,const Point& p2,const Point& p3){
    return dcmp(Cross(p1-p3,p2-p3))==0;
}
inline Vector Rotate(const Vector& a,const double& rad){
    return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
struct Line{
    Point p,b;
    Vector v;
    Line(){}
    Line(const Point& pp,const Point& bb){
        p=pp;b=bb;v=b-p;
    }
};
inline bool dot_online_in(const Point& p,const Line& l){
    return dcmp(Cross(p-l.b,l.p-l.b))==0&&(l.p.x-p.x)*(l.b.x-p.x)<eps&&(l.p.y-p.y)*(l.b.y-p.y)<eps;
}
inline bool same_side(const Point& p1,const Point& p2,const Line& l){
    return Cross(l.p-l.b,p1-l.b)*Cross(l.p-l.b,p2-l.b)>eps;
}
inline bool intersect_in(const Line& u,const Line& v){
    if(!dots_inline(u.p,u.b,v.p)||!dots_inline(u.p,u.b,v.b))
        return!same_side(u.p,u.b,v)&&!same_side(v.p,v.b,u);
    return dot_online_in(u.p,v)||dot_online_in(u.b,v)||dot_online_in(v.p,u)||dot_online_in(v.b,u);
}
char in[100];
struct node{
    char id;
    vector<Point> x;
    bool operator < (const node &p) const{
        return id<p.id;
    }
};
node as[100];
vector<char> inter[100];
int main(){
  //  freopen("in.txt","r",stdin);
    while(1){
        int cnt=0;
        for(int i=0;i<100;i++){
            as[i].x.clear();
        }
        while(1){
            scanf("%s",in);
           // printf("in=%s\n",in);
            if(in[0]=='.')return 0;
            if(in[0]=='-')break;
            as[cnt].id=in[0];
            scanf("%s",in);
         //   printf("in=%s\n",in);
            if(in[0]=='s'){
                double a,b,c,d;
                scanf(" (%lf,%lf) (%lf,%lf)",&a,&b,&c,&d);
                Point t1=Point(a,b),t2=Point(c,d);
                Vector v0=t2-t1;
                Vector v1=Rotate(v0,PI/4)/sqrt(2);
                Vector v2=Rotate(v0,-PI/4)/sqrt(2);
                as[cnt].x.push_back(t1);
                as[cnt].x.push_back(t1+v1);
                as[cnt].x.push_back(t2);
                as[cnt].x.push_back(t1+v2);
            }else if(in[0]=='r'){
                double a,b,c,d,e,f;
                scanf(" (%lf,%lf) (%lf,%lf) (%lf,%lf)",&a,&b,&c,&d,&e,&f);
                as[cnt].x.push_back(Point(a,b));
                as[cnt].x.push_back(Point(c,d));
                as[cnt].x.push_back(Point(e,f));
                Vector add=Point(e,f)-Point(c,d);
                Point last=Point(a,b)+add;
                as[cnt].x.push_back(last);
            }else if(in[0]=='l'){
                double a,b,c,d;
                scanf(" (%lf,%lf) (%lf,%lf)",&a,&b,&c,&d);
                as[cnt].x.push_back(Point(a,b));
                as[cnt].x.push_back(Point(c,d));
            }else if(in[0]=='t'){
                double a,b,c,d,e,f;
                scanf(" (%lf,%lf) (%lf,%lf) (%lf,%lf)",&a,&b,&c,&d,&e,&f);
                as[cnt].x.push_back(Point(a,b));
                as[cnt].x.push_back(Point(c,d));
                as[cnt].x.push_back(Point(e,f));
            }else{
                int num;
                scanf("%d",&num);
                for(int i=0;i<num;i++){
                    double u,v;
                    scanf(" (%lf,%lf)",&u,&v);
                    as[cnt].x.push_back(Point(u,v));
                }
            }
         /*   for(int i=0;i<as[cnt].x.size();i++){
                printf("(%.2f,%.2f)",as[cnt].x[i]);
            }
            printf("\n");*/
            cnt++;
        }
     //   printf("1");system("pause");
        sort(as,as+cnt);
        for(int i=0;i<100;i++){
             inter[i].clear();
        }
        for(int i=0;i<cnt;i++){
            for(int j=i+1;j<cnt;j++){
                int sz1=as[i].x.size(),sz2=as[j].x.size();
                bool pd=false;
                for(int ii=0;ii<sz1;ii++){
                    for(int jj=0;jj<sz2;jj++){
                        Line t1=Line(as[i].x[ii],as[i].x[(ii+1)%sz1]);
                        Line t2=Line(as[j].x[jj],as[j].x[(jj+1)%sz2]);
                        if(intersect_in(t1,t2)){
                            pd=true;
                            break;
                        }
                    }
                    if(pd)break;
                }
                if(pd){
                    inter[i].push_back(as[j].id);
                    inter[j].push_back(as[i].id);
                }
            }
        }
        for(int i=0;i<cnt;i++)sort(inter[i].begin(),inter[i].end());
        for(int i=0;i<cnt;i++){
            printf("%c ",as[i].id);
            int sz=inter[i].size();
            if(sz==0){
                printf("has no intersections\n");
            }else if(sz==1){
                printf("intersects with %c\n",inter[i][0]);
            }else if(sz==2){
                printf("intersects with %c and %c\n",inter[i][0],inter[i][1]);
            }else{
                printf("intersects with ");
                for(int j=0;j<sz-1;j++){
                    printf("%c, ",inter[i][j]);
                }
                printf("and %c\n",inter[i][sz-1]);
            }
        }
        printf("\n");
     //   printf("2");system("pause");
    }
    return 0;
}

