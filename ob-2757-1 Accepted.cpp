
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010],cc;
int main(){
    int n,b;
    while(~scanf("%d%d",&n,&b)){
        cc=1;
        a[0]=b;
        for(int i=1;i<n;i++){
            scanf("%d",&b);
            int pos=lower_bound(a,a+cc,b)-a;
            a[pos]=b;
            cc=max(cc,pos+1);
        }
        printf("%d\n",cc);
    }
    return 0;
}

