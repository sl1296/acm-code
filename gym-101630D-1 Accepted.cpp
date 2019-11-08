
#include<cstdio>
#include<algorithm>
using namespace std;
int r[1000010][3];
int main(){
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c)){
        int n=0;
        int o[3];
        int ss=0;
        if(a<=b && b<=c)o[0]=0,o[1]=1,o[2]=2;
        if(a<=c && c<=b)o[0]=1,o[1]=0,o[2]=2;
        if(b<=a && a<=c)o[0]=0,o[1]=2,o[2]=1;
        if(b<=c && c<=a)o[0]=1,o[1]=2,o[2]=0;
        if(c<=a && a<=b)o[0]=2,o[1]=0,o[2]=1;
        if(c<=b && b<=a)o[0]=2,o[1]=1,o[2]=0;
        if(a>b)swap(a,b);
        if(a>c)swap(a,c);
        if(b>c)swap(b,c);
//        if(a==2 && b==3 && c==4){
//            r[n][0]=0;
//            r[n][1]=0;
//            r[n++][2]=0;
//            r[n][0]=0;
//            r[n][1]=1;
//            r[n++][2]=0;
//            r[n][0]=0;
//            r[n][1]=0;
//            r[n++][2]=1;
//            r[n][0]=0;
//            r[n][1]=0;
//            r[n++][2]=2;
//        }
        if(c>a*b){
            printf("-1\n");
        }else{
            while(c<a+b-1){
                r[n][0]=ss;
                r[n][1]=ss;
                r[n++][2]=ss;
                ++ss;
                --a;
                --b;
                --c;
            }
            for(int i=0;i<a;++i){
                r[n][0]=ss;
                r[n][1]=ss+i;
                r[n++][2]=ss;
            }
            for(int i=1;i<b;++i){
                r[n][0]=ss;
                r[n][1]=ss;
                r[n++][2]=ss+i;
            }
            c-=(a+b-1);
            for(int i=1;i<a;++i){
                for(int j=1;j<b;++j){
                    if(c==0)goto en;
                    --c;
                    r[n][0]=ss;
                    r[n][1]=ss+i;
                    r[n++][2]=ss+j;
                }
            }
            en:
            printf("%d\n",n);
            for(int i=0;i<n;++i){
                printf("%d %d %d\n",r[i][o[0]],r[i][o[1]],r[i][o[2]]);
            }
        }
    }
    return 0;
}

