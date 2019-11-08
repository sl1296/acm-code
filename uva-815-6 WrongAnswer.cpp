
#include<cstdio>
#include<algorithm>
using namespace std;
int x[1000];
int y[1000],yc[1000],yn,cc[1000];
int main(){
    int m,n,to,cas=1;
    while(1){
        scanf("%d%d",&m,&n);
        if(!m && !n)break;
        int c=m*n;
        for(int i=0;i<c;i++)scanf("%d",&x[i]);
        scanf("%d",&to);
        sort(x,x+c);
        yn=0;
        for(int i=0;i<c;i++){
            y[yn]=x[i];
            yc[yn]=1;
            while(x[i+1]==x[i] && i<c){
                i++;
                yc[yn]++;
            }
            yn++;
        }
        int k=yc[0];
        int z=0;
        int tmp,i;
        for(i=1;i<yn;i++){
            tmp=k*100*(y[i]-y[i-1])*yc[i-1];
            z+=tmp;
            if(z>=to)break;
            k+=yc[i];
        }
        double d=k*100.0/c;
        double h=(z<to)?(y[yn-1]+(to-z)/(100.0*c)):(y[i-1]+(double)(y[i]-y[i-1])*(to-z+tmp)/tmp);
        if(to==0)h=d=0;
        printf("Region %d\nWater level is %.2f meters.\n%.2f percent of the region is under water.\n\n",cas++,h,d);
    }
    return 0;
}

