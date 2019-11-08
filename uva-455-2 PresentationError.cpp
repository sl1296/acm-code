
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int main(){
    int t;
    char s[100];
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int l=strlen(s);
        int i;
        for(i=1;i<=l;i++){
            if(l%i!=0)continue;
            char tmp[100];
            for(int j=0;j<i;j++)tmp[j]=s[j];
            int j;
            for(j=1;j<(l/i);j++){
                int k;
                for(k=0;k<i;k++){
                    int x=j*i+k;
                    if(tmp[k]!=s[x])break;
                }
                if(k<i)break;
            }
            if(j>=(l/i))break;
        }
        if(i>l)i=l;
        printf("%d\n",i);
    }
    return 0;
}

