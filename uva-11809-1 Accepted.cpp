
#include<bits/stdc++.h>
using namespace std;
char s[100];
double a[35][35];
int b[35][35];
double pa[35];
int pb[35];
int main(){
    pa[0]=1;
    for(int i=1;i<31;i++){
        pa[i]=pa[i-1]*pa[i-1]*2;
        pb[i]=pb[i-1]*2;
        while(pa[i]>=10){
            pa[i]/=10;
            pb[i]++;
        }
    }
    a[0][0]=0.5;
    for(int i=1;i<10;i++)a[0][i]=a[0][i-1]/2;
    for(int i=0;i<10;i++){
        a[0][i]=1-a[0][i];
        while(a[0][i]<1){
            a[0][i]*=10;
            b[0][i]--;
        }
    }
    for(int i=1;i<31;i++){
        for(int j=0;j<10;j++){
            a[i][j]=a[0][j]*pa[i];
            b[i][j]=b[0][j]+pb[i];
            while(a[i][j]>=10){
                a[i][j]/=10;
                b[i][j]++;
            }
            while(a[i][j]<1){
                a[i][j]*=10;
                b[i][j]--;
            }
        }
    }
    while(1){
        scanf("%s",s);
        if(strcmp(s,"0e0")==0)break;
        double x=0,t=0.1;
        int y=0;
        bool k1=false,k2=false;
        for(int i=0;s[i];i++){
            if(s[i]>47 && s[i]<58){
                if(k2){
                    y=y*10+s[i]-48;
                }else{
                    if(k1){
                        x=x+(s[i]-48)*t;
                        t/=10;
                    }else{
                        x=x*10+s[i]-48;
                    }
                }
            }else if(s[i]=='.'){
                k1=true;
            }else{
                k2=true;
            }
        }
        while(x>=10){
            x/=10;
            y++;
        }
        while(x<1){
            x*=10;
            y--;
        }
        int i,j;
        for(i=0;i<31;i++){
            for(j=0;j<10;j++){
                if(y==b[i][j] && fabs(x-a[i][j])<1e-6)break;
            }
            if(j<10)break;
        }
        printf("%d %d\n",j,i);
    }
    return 0;
}

