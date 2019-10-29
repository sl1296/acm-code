
#include <bits/stdc++.h>
using namespace std;
bool vis[5010][510];
struct node{
    int sum,mod,pre,ch;
};
int r[5010],rn;
int main(){
    int d,s;
    scanf("%d%d",&d,&s);
    vector<node> ve;
    int ss=0,ee=1;
    ve.push_back((node){0,0,-1,-1});
    vis[0][0]=true;
    int ans=-1;
    while(ss<ee){
        for(int i=0;i<10;++i){
            int as=ve[ss].sum+i;
            if(as>s)continue;
            int add=(ve[ss].mod*10+i)%d;
            if(!vis[as][add]){
                vis[as][add]=true;
                ve.push_back((node){as,add,ss,i});
                if(as==s && add==0){
                    ans=ee;
                    goto en;
                }
                ++ee;
            }
        }
        ++ss;
    }
    en:
    if(ans==-1){
        printf("-1\n");
    }else{
        for(int i=ans;i!=-1;i=ve[i].pre){
            r[rn++]=ve[i].ch;
        }
        for(int i=rn-2;i>=0;--i)printf("%d",r[i]);
        printf("\n");
    }
    return 0;
}

