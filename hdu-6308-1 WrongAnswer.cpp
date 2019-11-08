
#include<bits/stdc++.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        char c[50];
        scanf("%d%d%s",&a,&b,c);
        int x=atoi(&c[3]);
        a+=(x-8);
        if(a<0)a+=24;
        if(a>23)a-=24;
        printf("%02d:%02d\n",a,b);
    }
    return 0;
}

