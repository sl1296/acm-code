
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct node{
    double x,y;
    bool operator < (const node &p) const{
        return x<p.x;
    }
};
node a[1010];
int dcmp(double x){
    if(x<-1e-9)return -1;
    if(x>1e-9)return 1;
    return 0;
}
int main(){
    //system("chcp 936");
    int n,cas=1;
    double d;
    while(1){
        scanf("%d%lf",&n,&d);
        if(n==0&&dcmp(d)==0)break;
        bool is=true;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&a[i].x,&a[i].y);
            if(a[i].y>d)is=false;
        }
        printf("Case %d: ",cas++);
        if(is==false){
            printf("-1\n");
            continue;
        }
        sort(a,a+n);
        int ans=0;
        for(int i=0;i<n;i++){
           // printf("i=%d\n",i);
            double ad=a[i].x+sqrt(d*d-a[i].y*a[i].y);
            ans++;
            while(i+1<n){
                double dis=a[i+1].x-ad;
              //  printf("%d %f\n",i+1,sqrt(dis*dis+a[i+1].y*a[i+1].y));
                if(dcmp(sqrt(dis*dis+a[i+1].y*a[i+1].y)-d)<=0)i++;else break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

