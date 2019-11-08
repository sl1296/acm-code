
#include<cstdio>
#include<cstring>
bool x[1100000];
int main(){
    int d,n;
    scanf("%d",&d);
    while(1){
        scanf("%d",&d);
        if(d==-1)break;
        scanf("%d",&n);
        memset(x,false,sizeof(x));
        int t,en=1<<(d-1);
        for(int i=0;i<n;i++){
            t=1;
            while(t<en){
                x[t]=!x[t];
                if(x[t])t=t*2;else t=t*2+1;
            }
        }
        printf("%d\n",t);
    }
    return 0;
}

