
#include <stdio.h>
int main(){
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF){
        if(!c){if(a==b)printf("YES\n"); else printf("NO\n");continue;}
        if((b-a)%c==0 && (b-a)*c>-1)printf("YES\n"); else printf("NO\n");
    }
    return 0;
}

