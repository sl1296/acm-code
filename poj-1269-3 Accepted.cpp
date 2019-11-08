
#include <stdio.h>
int det(int x1,int y1,int x2,int y2){
    return x1*y2-x2*y1;
}
int main(){
    int t,x1,x2,x3,x4,y1,y2,y3,y4;
    double x,y,a1,b1,c1,a2,b2,c2;
    puts("INTERSECTING LINES OUTPUT");
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        if(det(x2-x1,y2-y1,x4-x3,y4-y3)==0){
            if(det(x2-x1,y2-y1,x3-x1,y3-y1)==0)puts("LINE");
            else puts("NONE");
        }else{
            a1=y1-y2;
            b1=x2-x1;
            c1=x1*y2-x2*y1;
            a2=y3-y4;
            b2=x4-x3;
            c2=x3*y4-x4*y3;
            x=(c1*b2-c2*b1)/(a2*b1-a1*b2);
            y=(a2*c1-a1*c2)/(a1*b2-a2*b1);
            printf("POINT %.2f %.2f\n",x,y);
        }
    }
    puts("END OF OUTPUT");
    return 0;
}

