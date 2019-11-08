
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a[110],tmp;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            a[tmp]++;
        }
        bool x=false;
        for(int i=1;i<101;i++){
            for(int j=0;j<a[i];j++){
                if(x)printf(" ");
                x=true;
                printf("%d",i);
            }
        }
        printf("\n");
    }
    return 0;
}

