
#include<cstdio>
#include<cstring>
using namespace std;
int l;
char s[105];
bool cmp(int a,int b){
    int i;
    for(i=0;i<l;i++){
        if(s[(b+i)%l]!=s[(a+i)%l])return s[(b+i)%l]<s[(a+i)%l];
    }
    return false;
}
int main(){
    int t,ans,i;
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%s",s);
        l=strlen(s);
        for(i=1;i<l;i++)if(cmp(ans,i))ans=i;
        for(i=0;i<l;i++)printf("%c",s[(i+ans)%l]);
        printf("\n");
    }
    return 0;
}

