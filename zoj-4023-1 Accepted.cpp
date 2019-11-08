
#include<cstdio>
char a[100],b[100];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",a,b);
        b[0]-=32;
        printf("%s%s\n",b,a);
    }
    return 0;
}

