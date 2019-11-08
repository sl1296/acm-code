
#include<cstdio>
int a[2010][2010];
int main(){
    int cnt=0;
    for(int i=0;i<46;i++){
        for(int j=0;j<46;j++){
            for(int k=0;k<43;k++){
                if(k&1)a[cnt][k*46+j]=1;
                else a[cnt][k*46+i]=1;
            }
            cnt++;
            if(cnt==2000)goto en;
        }
    }
    en:
    printf("2000\n");
    for(int i=0;i<2000;i++){
        for(int j=0;j<2000;j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

