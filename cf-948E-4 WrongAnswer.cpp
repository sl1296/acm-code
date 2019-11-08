
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[100010],t[100010];
int ss[100010],tt[100010];
int ks[100010],kt[100010];
int main(){
    int n;
    scanf("%s%s%d",s,t,&n);
    int sl=strlen(s),tl=strlen(t);
    for(int i=1;i<=sl;++i)ss[i]=ss[i-1]+(s[i-1]=='B' || s[i-1]=='C');
    for(int i=1;i<=tl;++i)tt[i]=tt[i-1]+(t[i-1]=='B' || t[i-1]=='C');
    int tmp=0;
    for(int i=0;i<sl;++i){
        if(s[i]=='A')++tmp;else tmp=0;
        ks[i]=tmp;
    }
    tmp=0;
    for(int i=0;i<tl;++i){
        if(t[i]=='A')++tmp;else tmp=0;
        kt[i]=tmp;
    }
    for(int i=0;i<n;++i){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int c1=ss[b]-ss[a-1],c2=tt[d]-tt[c-1];
        int ad=min(b-a+1,ks[b])-min(d-c+1,kt[d]);
        ad*=2;
        printf("%c",(c1%2==c2%2 && c2>=c1 && ad>=0 && c2>=ad)?'1':'0');
    }
    printf("\n");
    return 0;
}


