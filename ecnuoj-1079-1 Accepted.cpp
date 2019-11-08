
#include<cstdio>
int c[40][40];
int main(){
    for(int i=0;i<31;i++)c[i][0]=1;
    for(int i=1;i<31;i++){
        for(int j=1;j<=i;j++){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
    int n;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

