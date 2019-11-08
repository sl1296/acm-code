
#include <stdio.h>
int f[300100];
typedef struct jz{
    int x[11][11];
}jz;
jz one,aaa;
int mod;
jz mul(jz a,jz b){
    int i,j,k;
    jz c;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            c.x[i][j]=0;
            for(k=0;k<10;k++){
                c.x[i][j]=(c.x[i][j]+a.x[i][k]*b.x[k][j])%mod;
            }
        }
    }
    return c;
}
jz qpow(jz a,jz o,int x){
    int i,j;
  /*  printf("qpow:%d\n",x);
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%d ",a.x[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/
    while(x){
        if(x&1)o=mul(o,a);
        x>>=1;
        a=mul(a,a);
    }
  /*  for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%d ",o.x[i][j]);
        }
        printf("\n");
    }*/
    return o;
}
int main(){
    int k,i,r;
    jz re;
    for(i=0;i<10;i++){
        one.x[i][i]=1;
        aaa.x[i][i+1]=1;
    }
    while(scanf("%d%d",&k,&mod)!=EOF){
        for(i=0;i<10;i++)scanf("%d",&aaa.x[i][0]);
        if(k<10)printf("%d\n",k%mod);
        else{
            re=qpow(aaa,one,k-9);
            r=0;
            for(i=0;i<9;i++)r=(r+re.x[i][0]*(9-i))%mod;
            printf("%d\n",r);
        }
    }
    return 0;
}

