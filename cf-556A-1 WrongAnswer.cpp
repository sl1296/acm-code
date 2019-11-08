
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[100010];
int main(){
    int n;
    while(~scanf("%d%s",&n,s)){
        int l=strlen(s),cnt=0;
        for(int i=0;i<l;i++)if(s[i]=='0')cnt++;
        printf("%d\n",max(cnt,l-cnt));
    }
    return 0;
}

