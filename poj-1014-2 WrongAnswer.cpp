
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int a,b,c,d,e,f,cas=1;
    while(~scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)){
        if(!a&&!b&&!c&&!d&&!e&&!f)break;
        bool ans=true;
        if((a+b*2+c*3+d*4+e*5+f*6)%2==0){
            f%=2;
            if(f){
                if(e&&a){
                    e--;a--;f--;
                }else if(d&&b){
                    d--;b--;f--;
                }else if(d&&a>1){
                    d--;a-=2;f--;
                }else if(c>1){
                    c-=2;f--;
                }else if(c&&b&&a){
                    c--;b--;a--;f--;
                }else if(c&&a>2){
                    c--;a-=3;f--;
                }else if(b>2){
                    b-=3;f--;
                }else if(b>1&&a>1){
                    b-=2;a-=2;f--;
                }else if(b&&a>3){
                    b--;a-=4;f--;
                }else if(a>5){
                    a-=6;f--;
                }
            }
            e%=2;
            if(e){
                if(d&&a){
                    d--;a--;e--;
                }else if(c&&b){
                    c--;b--;e--;
                }else if(b>1&&a){
                    b-=2;a--;e--;
                }else if(b&&a>2){
                    b--;a-=3;e--;
                }else if(a>4){
                    a-=5;e--;
                }
            }
            d%=2;
            if(d){
                if(c&&a){
                    c--;a--;d--;
                }else if(b>1){
                    b-=2;d--;
                }else if(b&&a>1){
                    b--;a-=2;d--;
                }else if(a>3){
                    a-=4;d--;
                }
            }
            c%=2;
            if(c){
                if(b&&a){
                    b--;a--;c--;
                }else if(a>2){
                    a-=3;c--;
                }
            }
            b%=2;
            if(b){
                if(a>1){
                    a-=2;b--;
                }
            }
            a%=2;
        }
        printf("Collection #%d:\n",cas++);
        if(a+b+c+d+e+f){
            printf("Can't be divided.\n");
        }else{
            printf("Can be divided.\n");
        }
        printf("\n");
    }
    return 0;
}

