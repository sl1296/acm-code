
#include<cstdio>
#include<map>
using namespace std;
int a[100010];
int n;
int sg[100010];
int cal(int x){
    if(sg[x]!=-1)return sg[x];
    map<int,bool> ma;
    for(int i=x%a[x];i<n;i+=a[x]){
        if(a[i]>a[x]){
            ma[cal(i)]=true;
        }
    }
    for(int i=0;;++i){
        if(!ma[i])return sg[x]=i;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        sg[i]=-1;
    }
    for(int i=0;i<n;++i){
        if(cal(i))printf("A");
        else printf("B");
    }
    return 0;
}

