
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define eps 1e-10
#define zero(x)(((x)>0?(x):-(x))<eps)
#define dcmp(x)((x)>eps?1:((x)<-eps?-1:0))
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
Point operator - (const Point& a,const Point& b){return Point(a.x-b.x,a.y-b.y);}
bool operator == (const Point& a,const Point& b){
    return zero(a.x-b.x)&&zero(a.y-b.y);
}
Point p[1010];
int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(!(p[i]==p[j])){
                    int cnt=0;
                    for(int k=0;k<n;k++){
                        if((p[k].x-p[i].x)*(p[j].y-p[i].y)-(p[k].y-p[i].y)*(p[j].x-p[i].x)==0)cnt++;
                    }
                    ans=max(ans,cnt);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

