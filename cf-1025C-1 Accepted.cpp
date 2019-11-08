
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[100010];
int main(){
    scanf("%s",s);
    int len=strlen(s);
    int mx=0,now=0,pre=-1;
    for(int i=0;i<len;++i){
        if(s[i]!=pre){
            ++now;
            pre=s[i];
        }else{
            mx=max(mx,now);
            now=1;
            pre=s[i];
        }
    }
    mx=max(mx,now);
    if(s[0]!=s[len-1]){
        int p=0,cnt=1;
        while(p+1<len&&s[p+1]!=s[p]){
            ++p;
            ++cnt;
        }
        p=len-1;
        ++cnt;
        while(p-1>=0&&s[p-1]!=s[p]){
            --p;
            ++cnt;
        }
        cnt=min(cnt,len);
        mx=max(mx,cnt);
    }
    printf("%d\n",mx);
    return 0;
}

