
#include<cstdio>
int main(){
    double l,k,a,b;
    scanf("%lf%lf%lf%lf",&l,&k,&a,&b);
    printf("%.2f\n",l/b-l/a);
    return 0;
    if(b>=a){
        if(k>l/2){
            printf("%.2f\n",l/b-l/a);
        }else{
            double t=k/(b-a),c=l/2/b;
            if(t>=c){
                printf("%.2f\n",l/b-l/a);
            }else{
                printf("%.2f\n",t*2-l/a);
            }
        }
    }else{
        if(k>l/2){
            printf("%.2f\n",l/b-l/a);
        }else{
            double t=k/(a-b),c=l/2/b;
            if(t>=c){
                printf("%.2f\n",l/b-l/a);
            }else{
                printf("%.2f\n",2*t-l/a);
            }
        }
    }
    return 0;
}

