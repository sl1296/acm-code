
#include<cstdio>
int main(){
    double l,k,a,b;
    scanf("%lf%lf%lf%lf",&l,&k,&a,&b);
    if(b>=a){
        double t=k/(b-a),c=l/2/b;
        if(t>=c){
            printf("%.2f\n",l/b-l/a);
        }else{
            printf("%.2f\n",t*2-1/a);
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

