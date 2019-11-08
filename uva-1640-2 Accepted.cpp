
#include <stdio.h>
int po[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
int cn[10]={0,1,20,300,4000,50000,600000,7000000,80000000,900000000};
int f(int d,int x){
    int i,lx=x,len,ans=0,pre[11],max,min,j;
    char s[12];
    for(i=0;i<9;i++)if(x/po[i]<10)break;len=i+1;
    for(;i>-1;i--){s[i]=lx%10;lx/=10;}
    for(i=1;i<len;i++){
        if(i==1)ans++;
        else{
            ans+=9*cn[i-1];
            if(d)ans+=po[i-1];
        }
    }
    for(i=0;i<len;i++){
        pre[i]=(int)(s[i]==d);
        if(i)pre[i]+=pre[i-1];
    }
    for(i=0;i<len;i++){
        max=s[i]-1;
        min=0;
        if(!i && len>1)min=1;
        for(j=min;j<=max;j++){
            ans+=cn[len-i-1];
            if(i)ans+=pre[i-1]*po[len-i-1];
            if(j==d)ans+=po[len-i-1];
        }
    }
    return ans;
}
int main(){
    int a,b,t,d;
    while(scanf("%d%d",&a,&b) && a && b){
        if(a>b){t=a;a=b;b=t;}
        for(d=0;d<10;d++){
            if(d)printf(" ");
            printf("%d",f(d,b+1)-f(d,a));
        }
        printf("\n");
    }
    return 0;
}

