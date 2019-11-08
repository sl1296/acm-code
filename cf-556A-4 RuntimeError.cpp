
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char s[100010];
int main(){
    int n;
    while(~scanf("%d%s",&n,s)){
        int cnt=0;
        for(int i=0;i<n;i++)if(s[i]=='0')cnt++;
        n=abs(n-2*cnt);
        printf("%d\n",n);
    }
    return 0;
}

