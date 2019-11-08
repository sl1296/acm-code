
#include<cstdio>
#include<cstring>
char s[100010],t[100010];
int ss[100010],tt[100010];
int main(){
    int n;
    scanf("%s%s%d",s,t,&n);
    int sl=strlen(s),tl=strlen(t);
    for(int i=1;i<=sl;++i)ss[i]=ss[i-1]+(s[i-1]=='B' || s[i-1]=='C');
    for(int i=1;i<=tl;++i)tt[i]=tt[i-1]+(t[i-1]=='B' || t[i-1]=='C');
    for(int i=0;i<n;++i){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int c1=ss[b]-ss[a-1],c2=tt[d]-tt[c-1];
        printf("%c",c1%2==c2%2?'1':'0');
    }
    printf("\n");
    return 0;
}


