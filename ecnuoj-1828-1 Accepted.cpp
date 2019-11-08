
#include<cstdio>
int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n==-1)break;
        int h=n/3600;
        int m=n%3600/60;
        int s=n%60;
        printf("%02d:%02d:%02d\n",h,m,s);
    }
    return 0;
}

