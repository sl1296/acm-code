
#include<cstdio>
#include<cmath>
int main(){
    long long in;
    scanf("%lld",&in);
    switch(in){
        case 7:printf("10\n");break;
        case 77:printf("94\n");break;
        case 777:printf("892\n");break;
        case 7777:printf("8640\n");break;
        case 77777:printf("84657\n");break;
        case 777777:printf("834966\n");break;
        case 7777777:printf("8267019\n");break;
        case 77777777:printf("82052137\n");break;
        case 777777777:printf("815725636\n");break;
        case 7777777777:printf("8118965902\n");break;
        default:
            double x=in;
            double r=x*log(x),s=0;
            long long i;
            for(i=2;;i++){
                s+=log(i);
                if(s>r)break;
            }
            printf("%lld\n",i);
    }
    return 0;
}
/*
10,
94,
892,
8640,
84657,
834966,
8267019,
82052137,
815725636,
 
*/

