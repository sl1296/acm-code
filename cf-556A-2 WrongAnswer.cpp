
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char s[100010];
int main(){
    int n;
    while(~scanf("%d%s",&n,s)){
        int l=strlen(s),cnt=0;
        for(int i=0;i<l;i++)if(s[i]=='0')cnt++;
        printf("%d\n",abs(l-cnt*2));
    }
    return 0;
}

