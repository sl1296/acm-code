
#include<cstdio>
#include<algorithm>
using namespace std;
double x[1000];
int main(){
    int m,n,to,cas=1;
    while(1){
        int c=0;
        scanf("%d%d",&m,&n);
        if(!m && !n)break;
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)scanf("%lf",&x[c++]);
        scanf("%d",&to);
        sort(x,x+c);
        double cc=0;
        int k=1,i;
        double tmp;
        for(i=1;i<c;i++){
            tmp=k*(x[i]-x[i-1])*100;
            cc+=tmp;
            if(cc>=to)break;
            k++;
        }
        double h=x[i-1]+(x[i]-x[i-1])*(to-cc+tmp)/tmp,d=i*100.0/c;
        printf("Region %d\nWater level is %.2f meters.\n%.2f percent of the region is under water.\n",cas++,h,d);
    }
}

