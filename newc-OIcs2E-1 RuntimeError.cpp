
#include<cstdio>
char s[5000010];
int main(){
    int n,now=0,pos=n-1,cnt=0;
    scanf("%d%s",&n,s);
    for(int i=0;i<n;++i){
        if(s[i]=='(')++now;
        else --now;
        if(now==-1){
            while(s[pos]!='(')--pos;
            s[pos]=')';
            s[i]='(';
            now=1;
            ++cnt;
        }
    }
    printf("%d\n",cnt);
    return 0;
}

