
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(char* a,char* b){
    int i=0;
    for(;a[i]&&b[i];++i)if(a[i]<b[i])return true;else if(a[i]>b[i])return false;
    if(a[i])return cmp(&a[i],b);else if(b[i])return cmp(a,&b[i]);else return false;
}
int main(){
    int n;
    char x[22][7];
    char* a[22];
    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i){
            scanf("%s",x[i]);
            a[i]=x[i];
        }
        sort(a,a+n,cmp);
        for(int i=n-1;i>=0;--i)printf("%s",a[i]);
        printf("\n");
    }
    return 0;
}

