
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
const double eps=1e-10;
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
bool operator < (const Point& a,const Point& b){
    return dcmp(a.x-b.x)<0||(dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)<0);
}
bool operator == (const Point& a,const Point& b){
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
inline double Cross(const Vector& a,const Vector& b){return a.x*b.y-a.y*b.x;}
inline int dots_inline(const Point& p1,const Point& p2,const Point& p3){
    return dcmp(Cross(p1-p3,p2-p3))==0;
}
inline bool isLine(const Vector& a,const Vector& b){return dcmp(Cross(a,b))==0;}
struct Line{
    Point p,b;
    Vector v;
    Line(){}
    Line(const Point& pp,const Point& bb){p=pp;b=bb;v=b-p;}
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
inline Point LineInter(const Line& a,const Line& b){
    double t=Cross(b.v,a.p-b.p)/Cross(a.v,b.v);
    return a.p+a.v*t;
}
typedef vector<Point> Polygon;
inline int isPointInPloygon(const Point& p,const Polygon& poly){
    int wn=0;
    int n=poly.size();
    for(int i=0;i<n;i++){
        if(dot_online_in(p,Line(poly[i],poly[(i+1)%n])))return -1;
        int k=dcmp(Cross(poly[(i+1)%n]-poly[i],p-poly[i]));
        int d1=dcmp(poly[i].y-p.y);
        int d2=dcmp(poly[(i+1)%n].y-p.y);
        if(k>0&&d1<=0&&d2>0)wn++;
        if(k<0&&d2<=0&&d1>0)wn--;
    }
    if(wn!=0)return 1;
    return 0;
}
struct node{
    Point x;
    int id;
    bool operator == (const node &p) const{
        return x==p.x;
    }
};
int cmp1(const node& a,const node& b){
    return a.x<b.x;
}
int cmp2(const node& a,const node& b){
    return a.id<b.id;
}
struct bfs{
    int id,step;
};
int main(){
    int n;
    Polygon st;
    st.push_back(Point(0,0));
    st.push_back(Point(0,100));
    st.push_back(Point(100,100));
    st.push_back(Point(100,0));
    int cas=1;
    while(~scanf("%d",&n)){
        cas++;
        vector<Polygon> poly;
        poly.push_back(st);
        for(int i=0;i<n;i++){
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            Line add=Line(Point(a,b),Point(c,d));
            int sz=poly.size();
            for(int j=sz-1;j>=0;j--){
                vector<node> ve;
                int sszz=poly[j].size();
                for(int k=0;k<sszz;k++){
                    Line tmp=Line(poly[j][k],poly[j][(k+1)%sszz]);
                    if(intersect_in(add,tmp)&&!isLine(add.v,tmp.v)){
                        ve.push_back((node){LineInter(add,tmp),k});
                    }
                }
                sort(ve.begin(),ve.end(),cmp1);
                int del=unique(ve.begin(),ve.end())-ve.begin();
                ve.resize(del);
                sort(ve.begin(),ve.end(),cmp2);
                if(ve.size()==2){
                    Polygon ad1,ad2;
                    ad1.push_back(ve[1].x);
                    ad1.push_back(ve[0].x);
                    for(int ii=ve[0].id+1;ii<=ve[1].id;ii++){
                        if(!(poly[j][ii]==ad1[ad1.size()-1]))ad1.push_back(poly[j][ii]);
                    }
                    if(ad1[0]==ad1[ad1.size()-1])ad1.pop_back();
                    ad2.push_back(ve[0].x);
                    ad2.push_back(ve[1].x);
                    for(int ii=ve[1].id+1;;ii++){
                        if(ii==sszz)ii=0;
                        if(!(poly[j][ii]==ad2[ad2.size()-1]))ad2.push_back(poly[j][ii]);
                        if(ii==ve[0].id)break;
                    }
                    if(ad2[0]==ad2[ad2.size()-1])ad2.pop_back();
                    poly.erase(poly.begin()+j);
                    poly.push_back(ad1);
                    poly.push_back(ad2);
                }
            }
        }
        double xx,yy;
        scanf("%lf%lf",&xx,&yy);
        Point aim=Point(xx,yy);
        int siz=poly.size();
        int start;
        vector<vector<int> > edge;
        vector<bool> isend,vis;
        vis.resize(siz);
        isend.resize(siz);
        edge.resize(siz);
        for(int i=0;i<siz;i++){
            if(isPointInPloygon(aim,poly[i])){
                if(isPointInPloygon(aim,poly[i])==-1)while(1);
                start=i;
            }
            int sz1=poly[i].size();
            bool ff=false;
            for(int j=0;j<sz1;j++){
                if((dcmp(poly[i][j].x)==0&&dcmp(poly[i][(j+1)%sz1].x)==0)||(dcmp(poly[i][j].y)==0&&dcmp(poly[i][(j+1)%sz1].y)==0)||(dcmp(poly[i][j].x-100)==0&&dcmp(poly[i][(j+1)%sz1].x-100)==0)||(dcmp(poly[i][j].y-100)==0&&dcmp(poly[i][(j+1)%sz1].y-100)==0)){
                    ff=true;
                    break;
                }
            }
            vis[i]=false;
            isend[i]=ff;
        }
        for(int i=0;i<siz;i++){
            for(int j=i+1;j<siz;j++){
                int sz1=poly[i].size(),sz2=poly[j].size();
                bool inj=false;
                for(int k=0;k<sz1;k++){
                    for(int l=0;l<sz2;l++){
                        if((poly[i][k]==poly[j][l]&&poly[i][(k+1)%sz1]==poly[j][(l+1)%sz2])||(poly[i][k]==poly[j][(l+1)%sz2]&&poly[i][(k+1)%sz1]==poly[j][l])){
                            inj=true;
                            break;
                        }
                    }
                    if(inj)break;
                }
                if(inj){
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        }
        queue<bfs> qu;
        qu.push((bfs){start,1});
        vis[start]=true;
        int ans;
        while(!qu.empty()){
            bfs tmp=qu.front();
            qu.pop();
            if(isend[tmp.id]){
                ans=tmp.step;
                break;
            }
            int sii=edge[tmp.id].size();
            for(int i=0;i<sii;i++){
                int ne=edge[tmp.id][i];
                if(!vis[ne]){
                    vis[ne]=true;
                    qu.push((bfs){ne,tmp.step+1});
                }
            }
        }
        printf("Number of doors = %d\n",ans);
    }
    return 0;
}
/*
8
100 84 0 87
72 0 100 58
1 0 100 20
100 24 0 80
66 100 68 0
49 100 100 3
40 0 10 100
18 100 100 58
71.092375 51.280575
*/
/*
9
0 50 40 0
0 50 70 0
0 50 50 100
70 0 100 40
40 0 100 70
50 100 100 70
50 100 100 40
0 100 40 0
0 100 20 0
40 50
*/

