
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-10;
inline int dcmp(const double& x){if(fabs(x)<eps)return 0;return x<0?-1:1;}
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
bool operator == (const Point& a,const Point& b){
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
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
                        if((p[k].x-p[i].x)*(p[j].y-p[i].y)==(p[k].y-p[i].y)*(p[j].x-p[i].x))cnt++;
                    }
                    ans=max(ans,cnt);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

