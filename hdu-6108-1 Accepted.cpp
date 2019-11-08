
#include<cstdio>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int p;
        scanf("%d",&p);
        p--;
        int cnt=0;
        for(int i=1;i*i<=p;i++){
            if(p%i==0){
                cnt++;
                if(i*i!=p)cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}

