
#include<bits/stdc++.h>
using namespace std;
char s[100],x[100];
int xn;
int main(){
    scanf("%s",s);
    x[xn++]=s[0];
    int len=strlen(s);
    for(int i=1;i<len;i++){
        int pos=lower_bound(x,x+xn,s[i])-x;
        if(pos<xn)x[pos]=s[i];
        else x[xn++]=s[i];
    }
    printf("%d\n",26-xn);
    return 0;
}

