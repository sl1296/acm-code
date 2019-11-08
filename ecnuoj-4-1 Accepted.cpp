
#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<10;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+10);
        printf("%d %d\n",n,a[7]);
    }
    return 0;
}

