
#include<bits/stdc++.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        char c[50];
        scanf("%d%d%s",&a,&b,c);
        bool pd=(c[3]=='+'?false:true);
        int now=4,x=0,y=0;
        while(c[now]>=48&&c[now]<=57){
            x=x*10+c[now]-48;
            now++;
        }
        if(c[now]){
            y=c[now+1]-48;
        }
        if(pd){
            x=-x;
            y=-y;
        }
        a+=(x-8);
        b+=(y*6);
        while(b<0){
            b+=60;
            a--;
        }
        while(b>59){
            b-=60;
            a++;
        }
        while(a<0)a+=24;
        while(a>23)a-=24;
        printf("%02d:%02d\n",a,b);
    }
    return 0;
}

