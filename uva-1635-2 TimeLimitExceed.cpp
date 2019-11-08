
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int zs[11010],zsn;
int fj[30],fjn[30],fjc;
int is[100010];
int c(int x,int y){
    int r=1,i;
    for(i=0;i<fjc;i++){
        while(x%fj[i]==0){fjn[i]--;x/=fj[i];}
        while(y%fj[i]==0){fjn[i]++;y/=fj[i];}
        if(fjn[i]>0)r=0;
    }
    return r;
}
int main(){
    int n,m,count,en,i,j;
    for(i=2;i<11001;i++)if(!zs[i])for(j=i*2;j<11001;j+=i)zs[j]=1;
    for(i=2;i<11001;i++)if(!zs[i]){zs[zsn]=i;zsn++;}
    while(scanf("%d%d",&n,&m)!=EOF){
        count=0;
        fjc=0;
        for(i=0;zs[i]*zs[i]<=m;i++){
            if(m%zs[i]==0){
                fj[fjc]=zs[i];
                m/=zs[i];
                fjn[fjc]=1;
                while(m%zs[i]==0){
                    fjn[fjc]++;
                    m/=zs[i];
                }
                fjc++;
            }
        }
        if(m>1){
            fj[fjc]=m;
            fjn[fjc]=1;
            fjc++;
        }
        //printf("%d ",fjc);
        for(i=2;i<n;i++){
          //  printf("%d:",i);
            if(c(n-i+1,i-1)){
                is[i]=1;
                count++;
                en=i+1;
            }
        }
        printf("%d\n",count);
        if(count){
            for(i=2;i<en;i++)if(is[i]){is[i]=0;printf("%d ",i);}
            printf("\n");
        }
    }
    return 0;
}

