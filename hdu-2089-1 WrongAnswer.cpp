
#include<cstdio>
using namespace std;
int dig[20];
int pow9[20];
int num(int x,int y,int di,bool iss){
   // printf("num %d %d %d %d\n",x,y,di,iss);
    if(iss){
        return pow9[x];
    }
    if(x==0){
        if(di==6 && y==2)return 1;
        return 0;
    }
    if(x==1){
        if(di==6 && y==2)return 9;
        if(y==6)return 1;
        return 0;
    }
    if(di==6 && y==2)return pow9[x];
    if(y==6)return num(x-1,2,6,0)+num(x-1,6,0,0)+7*num(x-1,0,0,0);
    return num(x-1,6,0,0)+8*num(x-1,0,0,0);
}
int cal(int x){
    if(x%10==4)x--;
    int r=0,n=0,xx=x;
    while(xx){
        dig[n]=xx%10;
        xx/=10;
        n++;
    }
    bool is=false;
    bool is2=false;
    int di;
    for(int i=n-1;i>-1;i--){
        if(dig[i]==4){
            is=true;
            di=3;
        }else if(dig[i]>4){
            di=dig[i]-1;
            if(is)di=8;
        }else{
            di=dig[i];
            if(is)di=8;
        }
        r=r+pow9[i]*di;
      //  printf("r=%d\n",r);
    }
    dig[n]=0;
    dig[n+1]=0;
    for(int i=n-1;i>-1;i--){
        if(dig[i+1]==2 && dig[i+2]==6)is2=true;
        for(int j=0;j<=dig[i];j++){
            if(i && j==dig[i])break;
            if(j==4)continue;
        //    printf("%d %d\nr=%d ",i,j,r);
            r=r-num(i,j,dig[i+1],is2);
         //   printf("%d\n",r);
        }
        if(dig[i]==4)break;
    }
    return r;
}
int main(){
    int a,b;
    pow9[0]=1;
    for(int i=1;i<20;i++)pow9[i]=pow9[i-1]*9;
    while(1){
        scanf("%d%d",&a,&b);
        if(!a && !b)break;
        printf("%d\n",cal(b)-cal(a-1));
    }
    return 0;
}

