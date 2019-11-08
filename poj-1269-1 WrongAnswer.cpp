
#include <stdio.h>
int det(int x1,int y1,int x2,int y2){
    return x1*y2-x2*y1;
}
int main(){
    int t,x1,x2,x3,x4,y1,y2,y3,y4;
    double x,y,k1,b1,k2,b2;
    printf("INTERSECTING LINES OUTPUT\n");
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        if(det(x2-x1,y2-y1,x4-x3,y4-y3)==0){
            if(det(x2-x1,y2-y1,x3-x1,y3-y1)==0)printf("LINE\n");
            else printf("NONE\n");
        }else{
            printf("POINT ");
            if(x2-x1==0){
                x=x1;
                y=y3+(y4-y3)*(x1-x3)/(x4-x3);
            }else if(x4-x3==0){
                x=x3;
                y=y1+(y2-y1)*(x3-x1)/(x2-x1);
            }else{
                k1=(double)(y2-y1)/(x2-x1);
                b1=y1-k1*x1;
                k2=(double)(y4-y3)/(x4-x3);
                b2=y3-k2*x3;
             /*   y=k1x+b1
                y=k2x+b2
                k1x+b1=k2x+b2*/
                x=(b2-b1)/(k1-k2);
                y=k1*x+b1;
        //        printf("\ny=%lfx+%lf\ny=%lfx+%lf\n",k1,b1,k2,b2);
            }
            printf("%.2lf %.2lf\n",x,y);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}

