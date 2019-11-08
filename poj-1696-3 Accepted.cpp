
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const double eps=1e-10;
const double PI=acos(-1.0);
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
//叉积长度
//求矢量[p0,p1],[p0,p2]的叉积,p0是顶点,Cross(p1-p0,p2-p0)
//若结果等于0，则这三点共线
//若结果大于0，则p0p2(b)在p0p1(a)的逆时针方向
//若结果小于0，则p0p2(b)在p0p1(a)的顺时针方向
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double Length(Vector a){return sqrt(Dot(a,a));}
double Angle(Vector a,Vector b){return acos(Dot(a,b)/Length(a)/Length(b));}
int ans[55],ansc;
Point pp[55];
bool use[55];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ansc=0;
        int n,pos;
        scanf("%d",&n);
        Point from=Point(0,999),now;
        for(int i=1;i<=n;++i){
            int q;
            scanf("%d%lf%lf",&q,&pp[i].x,&pp[i].y);
            if(dcmp(pp[i].y-from.y)<0||(dcmp(pp[i].y-from.y)==0&&dcmp(pp[i].x-from.x)<0)){
                from.y=pp[i].y;
                now=pp[i];
                pos=i;
            }
        }
      //  printf("%f %f %f %f\n",from.x,from.y,now.x,now.y);
        memset(use,false,sizeof(use));
        use[pos]=true;
        ans[ansc++]=pos;
        while(1){
            int id=-1;
            Vector v1=now-from;
            for(int i=1;i<=n;++i){
                if(!use[i]){
                    Vector v2=pp[i]-now;
                    if(dcmp(Cross(v1,v2))>=0){
                        if(id==-1){
                            id=i;
                        }else{
                            double a1=Angle(pp[id]-now,v1);
                            double a2=Angle(v2,v1);
        //                    printf("i=%d a1=%f,a2=%f\n",i,a1,a2);
                            if(dcmp(a1-a2)>0||(dcmp(a1-a2)==0&&dcmp(Length(pp[id]-now)-Length(v2))>0)){
                                id=i;
                            }
                        }
                    }
                }
            }
            if(id==-1)break;
            ans[ansc]=id;
            use[id]=true;
            ansc++;
            from=now;
            now=pp[id];
        }
        printf("%d",ansc);
        for(int i=0;i<ansc;++i){
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}

