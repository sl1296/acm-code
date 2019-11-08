
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int re[100000];
int pp[100000];
int main(){
  //  freopen("in.txt","r",stdin);
  //  freopen("out2.txt","w+",stdout);
    int a,b,cas=0;
    while(scanf("%d%d",&a,&b)!=EOF){
     //   if(cas)printf("\n");
        cas++;
        printf("%d/%d = %d.",a,b,a/b);
        a%=b;
        if(a==0){
            printf("(0)\n   1 = number of digits in repeating cycle\n\n");
            continue;
        }
        int p=0;
        memset(pp,0,sizeof(pp));
        bool is=false;
        while(1){
            pp[a]=p+1;
            a*=10;
            re[p]=a/b;
            a%=b;
            p++;
            if(a==0){
                is=true;
                break;
            }
            if(pp[a]){
                break;
            }
        }
        if(is){
            for(int j=0;j<p;j++)printf("%d",re[j]);
            printf("(0)\n   1 = number of digits in repeating cycle\n");
        }else{
            int ccc=0;
            for(int j=0;j<pp[a]-1;j++){
                if(ccc<50)printf("%d",re[j]);
                ccc++;
            }
            printf("(");
            bool outx=false;
            int dd=0;
            for(int j=pp[a]-1;j<p;j++){
                if(ccc<50)printf("%d",re[j]);
                else{
                    if(outx==false){
                        printf("...");
                        outx=true;
                    }
                }
                ccc++;
                dd++;
            }
            if(ccc==50)printf("...");
            printf(")\n   %d = number of digits in repeating cycle\n",dd);
        }
        printf("\n");
    }
//    getchar();
    return 0;
}

