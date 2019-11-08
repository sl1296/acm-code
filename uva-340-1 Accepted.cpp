
#include<cstdio>
#include<iostream>
using namespace std;
int a[1010],b[1010];
int c[11],d[11];
int main(){
    int n,cas=0,x,y,i;
    while(scanf("%d",&n) && n){
        printf("Game %d:\n",++cas);
        for(i=1;i<10;i++)c[i]=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            c[a[i]]++;
        }
        while(1){
            x=y=0;
            for(i=1;i<10;i++)d[i]=0;
            for(i=0;i<n;i++){
                scanf("%d",&b[i]);
                d[b[i]]++;
                if(a[i]==b[i])x++;
            }
            if(!b[0])break;
            for(i=1;i<10;i++)y+=min(c[i],d[i]);
            printf("    (%d,%d)\n",x,y-x);
        }
    }
    return 0;
}

