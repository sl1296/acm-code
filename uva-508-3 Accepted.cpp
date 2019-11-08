
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;
char c[110],t[110][10],word[110][500],wc[110][500],s[200];
int n,wn,clen[110],llen[110];
bool fi,duo;
int num,dis;
map<char,int> ma;
int main(){
    ma.clear();
    bool exit=false;
    while(1){
        while(1){
            scanf("%c",&c[n]);
            if(c[n]=='*'){
                exit=true;
                break;
            }
            if((c[n]>='A' && c[n]<='Z') ||(c[n]>='0' && c[n]<='9'))break;
        }
        if(exit)break;
        ma[c[n]]=n;
        scanf("%s",t[n]);
        clen[n]=strlen(t[n]);
        n++;
    }
    while(1){
        scanf("%s",word[wn]);
        if(strcmp(word[wn],"*")==0)break;
        int l=strlen(word[wn]);
        int p=0,x;
        for(int i=0;i<l;i++){
            x=ma[word[wn][i]];
            strcpy(&wc[wn][p],t[x]);
            p+=clen[x];
        }
        llen[wn]=p;
        wn++;
    }
    while(1){
        scanf("%s",s);
        if(strcmp(s,"*")==0)break;
        fi=duo=false;
        num=-1;
        dis=9999;
        int l=strlen(s);
        for(int i=0;i<wn;i++){
            bool is=true;
            for(int j=0;j<l&&j<llen[i];j++){
                if(s[j]!=wc[i][j]){
                    is=false;
                    break;
                }
            }
            if(is){
                if(l==llen[i]){
                    if(fi){
                        duo=true;
                        break;
                    }else{
                        fi=true;
                        num=i;
                    }
                }else if(!fi){
                    int tmp=abs(l-llen[i]);
                    if(tmp<dis){
                        dis=tmp;
                        num=i;
                    }
                }
            }
        }
        printf("%s",word[num]);
        if(duo)printf("!");else if(!fi)printf("?");
        printf("\n");
    }
    return 0;
}
/*
A .-
B -...
C -.-.
D -..
E .
F ..-.
G --.
H ....
I ..
J .---
K -.-
L .-..
M --
N -.
O ---
P .--.
Q --.-
R .-.
S ...
T -
U ..-
V ...-
W .--
X -..-
Y -.--
Z --..
0 ------
1 .-----
2 ..---
3 ...--
4 ....-
5 .....
6 -....
7 --...
8 ---..
9 ----.
*
AN
EARTHQUAKE
EAT
GOD
HATH
IM
READY
TO
WHAT
WROTH
*
.--.....-- .....--....
--.----.. .--.-.----..
.--.....-- .--.
..-.-.-....--.-..-.--.-.
..-- .-...--..-.--
---- ..--
*
*/

