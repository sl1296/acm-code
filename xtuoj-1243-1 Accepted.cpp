
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ma{
    int a11,a12,a21,a22;
}ma;
ma m[5000];
char s[100100];
int k[10]={1,10,100,1000,10000,100000};
int main(){
    int l,i,f,e;
    while(scanf("%s%d%d%d%d",s,&m[1].a11,&m[1].a12,&m[1].a21,&m[1].a22)!=EOF){
        f=0;
        for(i=2;i<4033;i++){
            m[i].a11=(m[i-1].a11*m[1].a11+m[i-1].a12*m[1].a21)%7;
            m[i].a12=(m[i-1].a11*m[1].a12+m[i-1].a12*m[1].a22)%7;
            m[i].a21=(m[i-1].a21*m[1].a11+m[i-1].a22*m[1].a21)%7;
            m[i].a22=(m[i-1].a21*m[1].a12+m[i-1].a22*m[1].a22)%7;
        }
        l=strlen(s);
        for(i=0;i<l;i++)s[i]-=48;
        if(l<5){
            for(i=l-1;i>-1;i--){
                f+=k[l-i-1]*s[i];
            }
        }else{
            f=s[0]*1000+s[1]*100+s[2]*10+s[3];e=4;
            while(e<l){
                f%=4032;
                f*=10;
                f+=s[e];
                e++;
            }
        }
        f%=4032;
        printf("%d %d\n%d %d\n",m[f].a11,m[f].a12,m[f].a21,m[f].a22);
    }
    return 0;
}

