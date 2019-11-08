
#include <cstdio>
using namespace std;
int aa[20]={0,15,150,750,7500,75000,750000,7500000,75000000,750000000};
//int xx[1000100]={0,1,1};
int main(){
    int t,n,a,b,x,y,z;
   /* for(i=3;i<1000000;i++){
        xx[i]=(xx[i-1]+xx[i-2])%1000000;
        if(xx[i]%1000000==0){printf("%d ",i);getchar();}
    }*/
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        x=9;
        if(a==2)x=4;
        y=b%x;z=b/x;if(!y){y=x;z--;}
        y=y*aa[a]+z*(x+1)*aa[a];
        printf("%d\n",y);
    }
    return 0;
}

