
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x;
        scanf("%d",&n);
        int a=0,b=0;
        for(int i=0;i<n;++i){
            scanf("%d",&x);
            a+=x;
        }
        for(int i=0;i<n;++i){
            scanf("%d",&x);
            b+=x;
        }
        if(a>b){
            printf("BaoBao\n");
        }else{
            printf("DreamGrid\n");
        }
    }
    return 0;
}

