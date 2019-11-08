
#include<cstdio>
#include<map>
using namespace std;
map<int,int>b;
int num;
int a[50];
void dfs(int i,long long l){
    b[l]=1;
    if(i==num)return;
    while(1){
        dfs(i+1,l);
        l*=a[i];
        if(l>1000000000)break;
    }
}
int main(){
    int t,n;
    a[1]=1;
    b[0]=0;
    int i;
    for(i=2;;i++){
        a[i]=a[i-1]+a[i-2];
        b[a[i]]=1;
        if(a[i]>1000000000)break;
    }
    num=i;
    dfs(3,1);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(b.find(n)==b.end())printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}

