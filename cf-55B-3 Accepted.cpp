
#include <stdio.h>
#include <math.h>
__int64 a[4];
int is[4];
int isb[4];
__int64 b[4];
__int64 c[4];
int main(){
        __int64 re,min=999999999999999999;
        char e[4][2];
        int i,j,k,l,x,y,z;
        scanf("%I64d%I64d%I64d%I64d%s%s%s",&a[0],&a[1],&a[2],&a[3],e[0],e[1],e[2]);
        for(i=0;i<4;i++){
            is[i]=1;
            for(j=0;j<4;j++){
                if(is[j])continue;
                is[j]=1;
                b[0]=a[i];
                if(e[0][0]=='+')b[0]+=a[j];
                else b[0]*=a[j];
                k=1;
                for(l=0;l<4;l++){
                    if(is[l])continue;
                    b[k]=a[l];
                    k++;
                }
                for(k=0;k<3;k++){
                    isb[k]=1;
                    for(l=0;l<3;l++){
                        if(isb[l])continue;
                        isb[l]=1;
                        c[0]=b[k];
                        if(e[1][0]=='+')c[0]+=b[l];
                        else c[0]*=b[l];
                        for(x=0;x<3;x++)if(!isb[x])c[1]=b[x];
                        if(e[2][0]=='+')re=c[0]+c[1];
                        else re=c[0]*c[1];
                        if(re<min)min=re;
                        isb[l]=0;
                    }
                    isb[k]=0;
                }
                is[j]=0;
            }
            is[i]=0;
        }


        printf("%I64d\n",min);
    return 0;
}

