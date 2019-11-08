
#include <stdio.h>
int main(){
    int t,l,i;
    char s[100],r[100],x;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        for(i=0;i<5;i++)r[i]=s[i+5];
        r[5]='/';
        for(i=6;i<10;i++)r[i]=s[i-6];
        r[10]='-';
        l=(s[11]-48)*10+s[12]-48;
        x=l<12?'a':'p';
        l%=12;if(!l)l=12;
        if(l>9){
            l-=10;
            r[11]=49;
        }else{
            r[11]=48;
        }
        r[12]=l+48;
        for(i=13;i<19;i++)r[i]=s[i];
        r[19]=x;
        r[20]='m';
        r[21]=0;
        printf("%s\n",r);
    }
    return 0;
}

