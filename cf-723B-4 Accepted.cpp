
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int n,i;
    char s[260];
    int c=0,omax=0;
    int p=0;
    bool is=false;
    bool in=false;
    while(scanf("%d%s",&n,s)!=EOF){
        c=p=omax=0;
        is=in=false;
        for(i=0;i<n;i++){
            if(s[i]=='_'){
                if(is){
                    is=false;
                    if(in){
                        c++;
                    }else{
                        omax=max(omax,p);
                    }
                    p=0;
                }
            }else if(s[i]=='('){
                if(is){
                    is=false;
                    omax=max(omax,p);
                    p=0;
                }
                in=true;
            }else if(s[i]==')'){
                if(is){
                    is=false;
                    c++;
                    p=0;
                }
                in=false;
            }else{
                is=true;
                p++;
            }
        }
        if(is){
            omax=max(omax,p);
        }
        printf("%d %d\n",omax,c);
    }
    return 0;
}

