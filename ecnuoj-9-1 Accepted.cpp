
#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int now=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j)printf(" ");
            printf("%d",now++);
        }
        printf("\n");
    }
    return 0;
}

