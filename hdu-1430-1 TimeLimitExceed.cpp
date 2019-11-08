
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int maxn = 10 ;
char str1[maxn];
char str2[maxn];
unsigned long long S[maxn] ;
int seed = 13331;
unsigned long long st,ed;
unsigned long long gethash(char * s) {
    S[0] = 0 ;
    int len = strlen(s) ;
    for(int i=1; i<=len; i++) {
        S[i] = S[i-1]*seed + s[i] ;
    }
    return S[len] ;
}
struct node {
    unsigned long long state ;
    char ss[maxn];
    int pre;
    char act;
};
node qq[100010];
void bfs() {
    map<unsigned long long,int> mapp ;
    node p;
    p.state = st ;
    p.act = -1 ;
    p.pre = -1 ;
    strcpy(p.ss,str1);
    mapp[st] = 1;
    qq[0]=p ;
    int f=0;
    int e=1;
    while(f<e) {
        node &top = qq[f++];
        if(top.state==ed) {
            vector<char> ans ;
            node &tmp = top ;
            while(tmp.pre!=-1){
                ans.push_back(tmp.act) ;
                tmp = qq[tmp.pre] ;
            }
            int sz = ans.size() ;
            for(int i=sz-1;i>=0;i--){
                printf("%c",ans[i]) ;
            }
            printf("\n") ;
            return ;
        }
        for(int i=1; i<=3; i++) {
            node newnode;
            newnode.pre = f-1;
            if(i==1) {
                for(int j=0; j<8; j++) {
                    newnode.ss[j] = top.ss["87654321"[j]-'1'];
                }
                newnode.ss[8]='\0' ;
                newnode.state = gethash(newnode.ss) ;
                newnode.act = 'A';
            } else if(i==2) {
                for(int j=0; j<8; j++) {
                    newnode.ss[j] = top.ss["41236785"[j]-'1'];
                }
                newnode.ss[8]='\0' ;
                newnode.state = gethash(newnode.ss) ;
                newnode.act = 'B';
            } else if(i==3) {
                for(int j=0; j<8; j++) {
                    newnode.ss[j] = top.ss["17245368"[j]-'1'];
                }
                newnode.ss[8]='\0' ;
                newnode.state = gethash(newnode.ss);
                newnode.act = 'C';
            }
            if(mapp[newnode.state]==1)continue ;
            else mapp[newnode.state]=1 ;
            qq[e++]=newnode ;
        }
    }

}
int main() {
    while(~scanf("%s",str1)) {
        scanf("%s",str2) ;
        st = gethash(str1) ;
        ed = gethash(str2) ;
        bfs() ;
    }
    return 0;
}
/*
12345678
17245368
12345678
82754631

12345678
17254368
12345678
12574638
*/


