
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int main(){
    int t;
    char s[100];
    int l;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int x=0;
        int ans=0;
        l=strlen(s);
        for(int i=0;i<l;i++){
            if(s[i]=='O'){
                x++;
                ans+=x;
            }else{
                x=0;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

