
#include<bits/stdc++.h>
using namespace std;
struct node{
    int type;
    double a,b,c,d,e,f;
};
node x[1110];
const double eps=1e-8;
inline int sgn(double x){
    if(fabs(x)<eps)return 0;
    if(x<0)return -1;
    return 1;
}
struct Point{
    double x,y;
    Point(double x,double y):x(x),y(y){}
    Point operator - (const Point &b) const{
        return Point(x-b.x,y-b.y);
    }
    double operator ^ (const Point &b) const{
        return x*b.y-y*b.x;
    }
    double operator * (const Point &b){
        return x*b.x+y*b.y;
    }
    double distance(Point p){
        return hypot(x-p.x,y-p.y);
    }
};
struct Cir{
    Point x;
    double r;
    Cir(Point x,double r):x(x),r(r){}
    double distocir(Cir b){
        double d=x.distance(b.x);
        if(sgn(d-r-b.r)>0)return d-r-b.r;
        double l=fabs(r-b.r);
        if(sgn(l-d)>0)return l-d;
        return 0;
    }
};
struct Line{
    Point s,e;
    Line(Point s,Point e):s(s),e(e){}
    double length(){
        return s.distance(e);
    }
    double dispointtoline(Point p){
        return fabs((p-s)^(e-s))/length();
    }
    double dispointtoseg(Point p){
        if(sgn((p-s)*(e-s))<0 || sgn((p-e)*(s-e))<0)return min(p.distance(s),p.distance(e));
        return dispointtoline(p);
    }
    double dissegtoseg(Line v){
        return min(min(dispointtoseg(v.s),dispointtoseg(v.e)),min(v.dispointtoseg(s),v.dispointtoseg(e)));
    }
    double dissegtocir(Point o,double r){
        double d=dispointtoseg(o),k1=s.distance(o),k2=e.distance(o);
        if(sgn((k1-r)*(k2-r))<=0)return 0;
        if(sgn(k1-r)>0){
            if(sgn(d-r)<=0)return 0;
            return d-r;
        }
        return min(r-k1,r-k2);
    }
    double dissegtotri(Point a,Point b,Point c){
        return min(min(dissegtoseg(Line(a,b)),dissegtoseg(Line(a,c))),dissegtoseg(Line(b,c)));
    }
};
inline double dis(int a,int b){
    if(x[a].type>x[b].type)swap(a,b);
    if(x[a].type==1&&x[b].type==1){
        return Line(Point(x[a].a,x[a].b),Point(x[a].c,x[a].d)).dissegtoseg(Line(Point(x[b].a,x[b].b),Point(x[b].c,x[b].d)));
    }else if(x[a].type==1&&x[b].type==2){
        return Line(Point(x[a].a,x[a].b),Point(x[a].c,x[a].d)).dissegtocir(Point(x[b].a,x[b].b),x[b].c);
    }else if(x[a].type==1&&x[b].type==3){
        return Line(Point(x[a].a,x[a].b),Point(x[a].c,x[a].d)).dissegtotri(Point(x[b].a,x[b].b),Point(x[b].c,x[b].d),Point(x[b].e,x[b].f));
    }else if(x[a].type==2&&x[b].type==2){
        return Cir(Point(x[a].a,x[a].b),x[a].c).distocir(Cir(Point(x[b].a,x[b].b),x[b].c));
    }else if(x[a].type==2&&x[b].type==3){
        Point ta=Point(x[b].a,x[b].b),tb=Point(x[b].c,x[b].d),tc=Point(x[b].e,x[b].f);
        Point cx=Point(x[a].a,x[a].b);
        return min(min(Line(ta,tb).dissegtocir(cx,x[a].c),Line(tb,tc).dissegtocir(cx,x[a].c)),Line(ta,tc).dissegtocir(cx,x[a].c));
    }else{
        Point ta=Point(x[b].a,x[b].b),tb=Point(x[b].c,x[b].d),tc=Point(x[b].e,x[b].f);
        Point ra=Point(x[a].a,x[a].b),rb=Point(x[a].c,x[a].d),rc=Point(x[a].e,x[a].f);
        return min(min(Line(ra,rb).dissegtotri(ta,tb,tc),Line(rb,rc).dissegtotri(ta,tb,tc)),Line(ra,rc).dissegtotri(ta,tb,tc));
    }
}
inline double pdis(int a,double px,double py){
    if(x[a].type==1){
        return Line(Point(x[a].a,x[a].b),Point(x[a].c,x[a].d)).dispointtoseg(Point(px,py));
    }else if(x[a].type==2){
        return fabs(Point(x[a].a,x[a].b).distance(Point(px,py))-x[a].c);
    }else{
        Point ta=Point(x[a].a,x[a].b),tb=Point(x[a].c,x[a].d),tc=Point(x[a].e,x[a].f);
        Point tp=Point(px,py);
        return min(min(Line(ta,tb).dispointtoseg(tp),Line(tb,tc).dispointtoseg(tp)),Line(ta,tc).dispointtoseg(tp));
    }
}
double dd[1110][1110],ds[1110],de[1110];
int edge[1110][1110],edgec[1110],fl[1110];
bool vis[1110];
void dfs(int now,int color){
    fl[now]=color;
    vis[now]=true;
    for(int i=0;i<edgec[now];++i){
        if(!vis[edge[now][i]]){
            dfs(edge[now][i],color);
        }
    }
}
double ee[1110][1110],low[1110];
inline void dij(double cost[][1110],double lowcost[],int n,int beg){
    for(int i=0;i<n;++i){
        lowcost[i]=9999999;
        vis[i]=false;
    }
    lowcost[beg]=0;
    for(int j=0;j<n;++j){
        int k=-1,Min=9999999;
        for(int i=0;i<n;++i){
            if(!vis[i]&&lowcost[i]<Min){
                Min=lowcost[i];
                k=i;
            }
        }
        if(k==-1)break;
        vis[k]=true;
        for(int i=0;i<n;++i){
            if(!vis[i]&&lowcost[k]+cost[k][i]<lowcost[i]){
                lowcost[i]=lowcost[k]+cost[k][i];
            }
        }
    }
}
int main(){
    double xs,ys,xt,yt;
    int n;
    scanf("%lf%lf%lf%lf%d",&xs,&ys,&xt,&yt,&n);
    for(int i=0;i<n;++i){
        scanf("%d",&x[i].type);
        if(x[i].type==1){
            scanf("%lf%lf%lf%lf",&x[i].a,&x[i].b,&x[i].c,&x[i].d);
        }else if(x[i].type==2){
            scanf("%lf%lf%lf",&x[i].a,&x[i].b,&x[i].c);
        }else{
            scanf("%lf%lf%lf%lf%lf%lf",&x[i].a,&x[i].b,&x[i].c,&x[i].d,&x[i].e,&x[i].f);
        }
        ds[i]=pdis(i,xs,ys);
        de[i]=pdis(i,xt,yt);
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            dd[i][j]=dis(i,j);
            if(fabs(dd[i][j])<eps){
                edge[i][edgec[i]++]=j;
                edge[j][edgec[j]++]=i;
            }
        }
    }
    int cnt=1;
    for(int i=0;i<n;++i){
        if(!vis[i]){
            dfs(i,cnt);
            ++cnt;
        }
    }
    for(int i=0;i<=cnt;++i){
        for(int j=0;j<=cnt;++j){
            ee[i][j]=9999999;
        }
    }
    ee[0][cnt]=ee[cnt][0]=Point(xs,ys).distance(Point(xt,yt));
    for(int i=0;i<n;++i){
        ee[0][fl[i]]=ee[fl[i]][0]=min(ee[0][fl[i]],ds[i]);
        ee[cnt][fl[i]]=ee[fl[i]][cnt]=min(ee[fl[i]][cnt],de[i]);
        for(int j=i+1;j<n;++j){
            if(fl[i]!=fl[j]){
                ee[fl[j]][fl[i]]=ee[fl[i]][fl[j]]=min(ee[fl[i]][fl[j]],dd[i][j]);
            }
        }
    }
    dij(ee,low,cnt+1,0);
    int ans=low[cnt];
    printf("%d\n",ans);
    return 0;
}
 
/**************************************************************
    Problem: 1020
    User: asdcvbn
    Language: C++
    Result: ´ð°¸´íÎó
****************************************************************/

