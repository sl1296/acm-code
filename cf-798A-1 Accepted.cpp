
#include<bits/stdc++.h>
using namespace std;
char s[200],t[200];
int main(){
    while(scanf("%s",s)!=EOF){
        int ans=0;
        int len=strlen(s);
        for(int j=0;j<len;j++){
            if(s[j]!=s[len-1-j])ans++;
          //  printf("%c %c\n",s[j],s[len-1-j]);
        }
        if(ans==2 || (ans==0 && len%2))printf("YES\n");else printf("NO\n");
    }
    return 0;
}

