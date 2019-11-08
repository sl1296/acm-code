
#include<cstdio>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int cnt=n,pa=n;
        while(pa>=3){
            int add=pa/3;
            cnt+=add;
            pa-=add*2;
        }
        printf("%d\n",cnt);
    }
    return 0;
}

