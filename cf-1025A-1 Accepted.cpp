
#include<cstdio>
#include<algorithm>
using namespace std;
char s[100010];
int main(){
    int n;
    scanf("%d%s",&n,s);
    if(n==1){
        printf("Yes\n");
    }else{
        sort(s,s+n);
        bool ans=false;
        for(int i=1;i<n;++i){
            if(s[i-1]==s[i]){
                ans=true;
                break;
            }
        }
        if(ans){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}

