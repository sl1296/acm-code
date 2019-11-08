
#include<cstdio>
#include<cstring>
int main(){
    int d,n,tt;
    scanf("%d",&tt);
    while(tt--){
        scanf("%d",&d);
        scanf("%d",&n);
        int t=1;
        for(int i=1;i<d;i++){
            if(n%2)t=t*2;else t=t*2+1;
            n=(n+1)/2;
        }
        printf("%d\n",t);
    }
    return 0;
}

