
/*
F:\temp\16059750.434031\Main.c:1:17: error: cstdio: No such file or directory
F:\temp\16059750.434031\Main.c:2:18: error: cstdlib: No such file or directory
F:\temp\16059750.434031\Main.c:3:18: error: cstring: No such file or directory
F:\temp\16059750.434031\Main.c:4:19: error: iostream: No such file or directory
F:\temp\16059750.434031\Main.c:5:16: error: cmath: No such file or directory
F:\temp\16059750.434031\Main.c:6:20: error: algorithm: No such file or directory
F:\temp\16059750.434031\Main.c:7: error: expected '=', ',', ';', 'asm' or '__attribute__' before 'namespace'

*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int n,i,j,l,k,w1,w2;
    char s[4][10],s2[4][10],s3[4][10];
    int w[15];
    scanf("%d",&n);
    while(n--){
        for(i=0;i<3;i++)scanf("%s%s%s",s[i],s2[i],s3[i]);
        for(i=0;i<12;i++)w[i]=5;
        for(i=0;i<12;i++){
            for(j=-1;j<2;j+=2){
             //   printf(":%d %d\n",i,j);
                w[i]+=j;
                for(k=0;k<3;k++){
                    w1=w2=0;
                    for(l=0;l<4;l++){
                        w1+=w[s[k][l]-'A'];
                        w2+=w[s2[k][l]-'A'];
                   //     printf("%d %d\n",w1,w2);
                    }
                    if((w1==w2 && strcmp(s3[k],"even")) || (w1>w2 && strcmp(s3[k],"up")) || (w1<w2 && strcmp(s3[k],"down")))break;
                }
                if(k==3)break;
                w[i]-=j;
            }
            if(j<2)break;
        }
        printf("%c is the counterfeit coin and it is ",i+'A');
        if(j>0)printf("heavy.\n"); else printf("light.\n");
    }
    return 0;
}

