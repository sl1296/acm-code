
#include<bits/stdc++.h>
using namespace std;
typedef pair<double,int> P;
#define maxn 1010
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y) {}
};
double PointLineDistance(Point O,double a,double b,double c){
    return abs(a*O.x+b*O.y+c)/sqrt(a*a+b*b);
}
double g[maxn][maxn],R[maxn];
Point A[maxn];
double d[maxn];
priority_queue<P> que;
int dcmp(double x){
    if(abs(x)<1e-8) return 0;
    return x<0?-1:1;
}
double dijkstra(int n){
    for(int i=0;i<n;i++) d[i]=1e9;
    d[0]=0;
    que.push(P(0.0,0));
    while(!que.empty()){
        P p=que.top();que.pop();
        int u=p.second;
        double cost=p.first;
        if(dcmp(d[u]-cost)<0) continue;
        for(int i=0;i<n;i++){
            if(dcmp(d[u]+g[u][i]-d[i])<0){
                d[i]=d[u]+g[u][i];
                que.push(P(d[i],i));
            }
        }
    }
    return d[1];
}
double Length(Point o1,Point o2){
    return sqrt((o1.x-o2.x)*(o1.x-o2.x)+(o1.y-o2.y)*(o1.y-o2.y));
}
int main(){
    int n;
    double a,b,c1,c2;
    scanf("%d%lf%lf%lf%lf",&n,&a,&b,&c1,&c2);
    n+=2;
    for(int i=2;i<n;i++)
        scanf("%lf%lf%lf",&A[i].x,&A[i].y,&R[i]);
    for(int i=2;i<n;i++){
        double d0=PointLineDistance(A[i],a,b,c1);
        double d1=PointLineDistance(A[i],a,b,c2);
        g[0][i]=g[i][0]=max(0.0,d0-R[i]);
        g[1][i]=g[i][1]=max(0.0,d1-R[i]);
    }
    g[0][1]=g[1][0]=abs(c1-c2)/sqrt(a*a+b*b);
    for(int i=2;i<n;i++){
        for(int j=i+1;j<n;j++)
            g[i][j]=g[j][i]=max(0.0,Length(A[i],A[j])-R[i]-R[j]);
    }
    printf("%f\n",dijkstra(n));
    return 0;
}

