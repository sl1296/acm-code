
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char in[1010][1010];
int len[1010];
int main(){
    int cnt=0;
    while(gets(in[cnt])!=NULL)cnt++;
    for(int i=0;i<cnt;i++){
        int l=strlen(in[i]);
        int j=0;
        while(j+1<l&&in[i][j]==' ')j++;
        int now=0;
        for(;j<l;){
            int le=0;
            while(in[i][j]!=' '&&in[i][j]!=0)j++,le++;
            len[now]=max(len[now],le);
            now++;
            while(j+1<=l&&in[i][j]==' ')j++;
        }
    }
    for(int i=0;i<cnt;i++){
        int l=strlen(in[i]);
        int j=0;
        while(j+1<l&&in[i][j]==' ')j++;
        int now=0;
        int pre=0;
        for(;j<l;){
            int le=0;
            for(int k=0;k<pre;k++)printf(" ");
            while(in[i][j]!=' '&&in[i][j]!=0)printf("%c",in[i][j]),j++,le++;
            pre=len[now]-le+1;
            now++;
            while(j+1<=l&&in[i][j]==' ')j++;
        }
        printf("\n");
    }
    return 0;
}
/*
  start:  integer;    // begins here
stop: integer; //  ends here
 s:  string;
c:   char; // temp
*/

