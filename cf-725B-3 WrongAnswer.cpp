
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
using namespace std;
map<char,int> ma;
char s[50];
int main(){
    int n;
    ma['f']=1;
    ma['e']=2;
    ma['d']=3;
    ma['a']=4;
    ma['b']=5;
    ma['c']=6;
    while(scanf("%s",s)!=EOF){
        int l=strlen(s);
        unsigned long long r=0;
        char c=s[l-1];
        for(int i=l-2;i>-1;i--){
            r=r*10+s[i]-'0';
        }
        unsigned long long bl=(r-1)/4;
        unsigned long long ans=bl*16;
        if(r%2==0)ans+=7;
        ans+=ma[c];
        printf("%I64u\n",ans);
    }
    return 0;
}

