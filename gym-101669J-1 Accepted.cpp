
#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int a[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    if(n==1){
        printf("Win\n");
    }else if(n%3==0&&a[n-1]==1||n>2&&a[n-3]>1){
        printf("Lose\n");
    }else{
        if(a[n-2]==1||a[n-2]==2&&n%3!=2) printf("Win\n");
        else printf("Lose\n");
    }
    return 0;
}

