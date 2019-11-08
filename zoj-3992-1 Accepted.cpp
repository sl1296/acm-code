
#include<cstdio>
#include<algorithm>
using namespace std;
char s[100010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d%s",&n,&m,s);
        if(m==1 || m==n){
            printf("0\n");
            continue;
        }
        --m;
        int c1=0,c2=0;
        for(int i=1;i<=m;++i)if(s[i]=='R')++c1;
        for(int i=m;i<n-1;++i)if(s[i]=='L')++c2;
        printf("%d\n",min(c1,c2));
    }
    return 0;
}

