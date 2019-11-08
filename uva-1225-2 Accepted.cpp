
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int x[10010][11];
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<10005;i++){
        for(int j=0;j<10;j++)x[i][j]=x[i-1][j];
        int tmp=i;
        while(tmp){
            x[i][tmp%10]++;
            tmp/=10;
        }
    }
    while(t--){
        int tt;
        scanf("%d",&tt);
        for(int i=0;i<10;i++){
            if(i)printf(" ");
            printf("%d",x[tt][i]);
        }
        printf("\n");
    }
    return 0;
}

