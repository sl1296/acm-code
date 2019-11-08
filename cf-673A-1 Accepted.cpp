
#include<bits/stdc++.h>
using namespace std;
bool x[100];
int main(){
    int n,a,i;
    while(scanf("%d",&n)!=EOF){
        memset(x,false,sizeof(x));
        for(i=0;i<n;i++){
            scanf("%d",&a);
            x[a]=true;
        }
        int p=0;
        for(i=1;i<91;i++){
            p++;
            if(x[i])p=0;
            if(p==15)break;
        }
        if(i>90)i=90;
        printf("%d\n",i);
    }
    return 0;
}

