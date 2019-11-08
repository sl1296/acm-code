
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[100010];
int main(){
    while(~scanf("%s",s)){
        int len=strlen(s);
        int p=len-1;
        int ans=1;
        while(p>=0){
            int tmp=0;
            while(s[p]=='0')p--,tmp++;
            int num=s[p];
            p--;
            if(tmp<p||(tmp==p&&num<=s[0]))ans++;else break;
        }
        printf("%d\n",ans);
    }
    return 0;
}

