
#include <cstdio>
#include <map>
using namespace std;
map<int,int>b;
int a[50];
int main(){
    int t,n;
    a[1]=1;
    b[0]=0;
    int i;
    for(i=2;;i++){
        a[i]=a[i-1]+a[i-2];
        b[a[i]]=i;
        if(a[i]>1000000000)break;
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(b.find(n)==b.end())printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}

