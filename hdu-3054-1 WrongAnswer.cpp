
#include <cstdio>
using namespace std;
int aa[20]={0,15,150,750,7500,75000,750000,7500000,75000000,750000000};
int main(){
    int t,n,a,b,x,y,z;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        x=9;
        if(a==2)x=4;
        y=b%x*aa[a];z=b/x*aa[a]*(x+1);
        printf("%d\n",y+z);
    }
    return 0;
}

