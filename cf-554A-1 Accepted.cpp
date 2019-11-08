
#include<bits/stdc++.h>
using namespace std;
char s[30],t[30];
map<string,int> ma;
int c;
int main(){
    while(scanf("%s",&s)!=EOF){
        c=0;
        ma.clear();
        int len=strlen(s);
        for(int i=0;i<=len;i++){
            int p=0;
            for(int j=0;j<=len;j++){
                if(p==i)p++;
                t[p]=s[j];
                p++;
            }
            for(int j=0;j<26;j++){
                t[i]='a'+j;
               // printf("%d %s\n",i,t);
                string tmp=t;
                if(ma[tmp]!=1){
                    c++;
                    ma[tmp]=1;
                }
            }
        }
        printf("%d\n",c);
    }
    return 0;
}

