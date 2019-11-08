
#include<cstdio>
#include<cstring>
bool is[55];
int re[55];
int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(!n)break;
        memset(is,false,sizeof(is));
        int pp=1;
        for(int i=1;i<n;i++){
            re[i]=pp;
            is[pp]=true;
            pp++;
            if(pp>n)pp=1;
            while(is[pp]){
                pp++;
                if(pp>n)pp=1;
            }
            pp++;
            if(pp>n)pp=1;
            while(is[pp]){
                pp++;
                if(pp>n)pp=1;
            }
        }
        printf("Discarded cards:");
        for(int i=1;i<n;i++){
            if(i>1)printf(", ");else printf(" ");
            printf("%d",re[i]);
        }
        printf("\nRemaining card: %d\n",pp);
    }
    return 0;
}

