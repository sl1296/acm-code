
#include<cstdio>
#include<map>
#include<cstring>
#include<string>
using namespace std;
char in[10010];
char gg[10010];
map<string,int> ma;
int len[1010];
map<int,bool> use[1010];
map<int,int> val[1010];
int cal(int ss,int ee){
    bool pd=true;
    int ret=0;
    for(int i=ss;i<ee;i++){
        if(in[i]<'0'||in[i]>'9'){
            pd=false;
            break;
        }
        ret=ret*10+in[i]-48;
    }
    if(pd)return ret;
    int pos=0,pp=ss;
    while(in[pp]!='[')gg[pos++]=in[pp++];
    gg[pos]=0;
    int ff=ma[gg];
    if(ff==0)return -1;
    int from=cal(pp+1,ee-1);
    if(from<0||from>len[ff]-1)return -1;
    if(!use[ff][from])return -1;
    return val[ff][from];
}
int main(){
    while(1){
        ma.clear();
        for(int i=0;i<1010;i++){
            use[i].clear();
            val[i].clear();
        }
        int ans=0;
        int arn=0;
        int line=1;
        scanf("%s",in);
   //     printf("hh=%s\n",in);
        if(strcmp(in,".")==0)break;
        while(1){
            int dh=-1;
            for(int i=0;in[i];i++)if(in[i]=='='){dh=i;break;}
            if(dh==-1){
                int pos=0;
                while(in[pos]!='[')gg[pos]=in[pos],pos++;
                gg[pos]=0;
                ma[gg]=++arn;
                len[arn]=0;
                pos++;
                while(in[pos]!=']'){
                    len[arn]=len[arn]*10+in[pos]-48;
                    pos++;
                }
            }else{
                int pos=dh;
                int l=strlen(in);
                int to=cal(pos+1,l);
                if(to==-1){
                    ans=line;
                    break;
                }
                int pp=0;
                while(in[pp]!='[')gg[pp]=in[pp],pp++;
                gg[pp]=0;
                int ff=ma[gg];
                if(ff==0){
                    ans=line;
                    break;
                }
                int from=cal(pp+1,pos-1);
                if(from<0||from>len[ff]-1){
                    ans=line;
                    break;
                }
                use[ff][from]=true;
                val[ff][from]=to;
            }
            line++;
            scanf("%s",in);
          //  printf("in=%s\n",in);
            if(strcmp(in,".")==0)break;
        }
        while(strcmp(in,"."))scanf("%s",in);
        printf("%d\n",ans);
    }
    return 0;
}
/*
a[3]
a[0]=a[1]
.
x[1]
x[0]=x[0]
.
a[0]
a[0]=1
.
b[2]
b[0]=2
b[1]=b[b[0]]
b[0]=b[1]
.
g[2]
G[10]
g[0]=0
g[1]=G[0]
.
a[2147483647]
a[0]=1
B[2]
B[a[0]]=2
a[B[a[0]]]=3
a[2147483646]=a[2]
.
.
*/

