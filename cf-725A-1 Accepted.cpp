
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
char s[200100];
int main(){
    int n;
    while(scanf("%d%s",&n,s)!=EOF){
        int l=strlen(s);
        int ans=0;
        for(int i=0;i<l;i++){
            if(s[i]=='>')break;
            ans++;
        }
        for(int i=l-1;i>-1;i--){
            if(s[i]=='<')break;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

