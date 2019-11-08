
#include<cstdio>
#define ll long long
double cp[25]={0,0,1};
double al[25]={0,1,2};
int main(){
    for(int i=3;i<21;i++)cp[i]=(i-1)*(cp[i-1]+cp[i-2]),al[i]=al[i-1]*i;
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%.2f%%\n",cp[n]/al[n]*100);
    }
    return 0;
}

