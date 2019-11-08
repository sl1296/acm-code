
#include <stdio.h>
#include <math.h>
__int64 a[4];
int is[4];
int isb[3];
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
                for(k=0;k<4;k++){
                    if(is[k])continue;
                    is[k]=1;
                    for(l=0;l<4;l++){
                        if(is[l])continue;
                   //     printf("%d %d %d %d?",i,j,k,l);
                        for(x=0;x<3;x++){
                            isb[x]=1;
                            for(y=0;y<3;y++){
                                if(isb[y])continue;
                                isb[y]=1;
                                for(z=0;z<3;z++){
                                    if(isb[z])continue;
                         //           printf("%d %d %d ?",x,y,z);

                        re=a[i];
                        if(e[x][0]=='+')re+=a[j];
                        else re*=a[j];
                      //  printf("%d:",re);
                        if(e[y][0]=='+')re+=a[k];
                        else re*=a[k];
                      //  printf("%d:",re);
                        if(e[z][0]=='+')re+=a[l];
                        else re*=a[l];
                   //     printf("%d:",re);
                        if(e[x][0]=='*' && e[y][0]=='+' && e[z][0]=='*')re=a[i]*a[j]+a[k]*a[l];
                        if(e[x][0]=='+' && e[y][0]=='*' && e[z][0]=='+')re=a[i]+a[j]*a[k]+a[l];
                        if(e[x][0]=='+' && e[y][0]=='*' && e[z][0]=='*')re=a[i]+a[j]*a[k]*a[l];
                        if(e[x][0]=='+' && e[y][0]=='+' && e[z][0]=='*')re=a[i]+a[j]+a[k]*a[l];

                        if(re<min)min=re;
                                }
                                isb[y]=0;
                            }
                            isb[x]=0;
                        }
                    }
                    is[k]=0;
                }
                is[j]=0;
            }
            is[i]=0;
        }
        printf("%I64d\n",min);
    return 0;
}

