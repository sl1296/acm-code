
#include<bits/stdc++.h>
using namespace std;
double r[1010];
double k(int x){
    if(r[x]<2100)return 32;
    if(r[x]>=2400)return 16;
    return 24;
}
double e(int x,int y){
    return 1.0/(1.0+pow(10.0,(r[y]-r[x])/400.0));
}
int main(){
    for(int i=1;i<1001;i++)r[i]=1500;
    int q;
    scanf("%d",&q);
    while(q--){
        int t,x,y;
        double rx,ry;
        scanf("%d%d",&t,&x);
        if(t==1){
            scanf("%d",&y);
            rx=k(x)*(1-e(x,y));
            ry=k(y)*(-e(y,x));
            r[x]+=rx;
            r[y]+=ry;
        }else if(t==2){
            scanf("%d",&y);
            rx=k(x)*(0.5-e(x,y));
            ry=k(y)*(0.5-e(y,x));
            r[x]+=rx;
            r[y]+=ry;
        }else{
            printf("%f\n",r[x]);
        }
    }
    return 0;
}

