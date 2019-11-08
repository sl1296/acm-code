
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
struct nod{
    int x,step;
};
bool is[100010];
int ans;
queue<nod> q;
int main(){
    int s,e;
    nod l,l2;
    while(scanf("%d%d",&s,&e)!=EOF){
        if(s>=e){
            printf("%d\n",s-e);
            continue;
        }
        memset(is,false,sizeof(is));
        while(!q.empty())q.pop();
        l.x=s;
        l.step=0;
        is[s]=1;
        q.push(l);
        while(!q.empty()){
            l=q.front();
            q.pop();
            l2.step=l.step+1;
            if(l.x+1<100001 && !is[l.x+1]){
                if(l.x+1==e){
                    ans=l.step+1;
                    break;
                }
                is[l.x+1]=1;
                l2.x=l.x+1;
                q.push(l2);
            }
            if(l.x-1>-1 && !is[l.x-1]){
                if(l.x-1==e){
                    ans=l.step+1;
                    break;
                }
                is[l.x-1]=1;
                l2.x=l.x-1;
                q.push(l2);
            }
            if(l.x*2<100001 && !is[l.x*2]){
                if(l.x*2==e){
                    ans=l.step+1;
                    break;
                }
                is[l.x*2]=1;
                l2.x=l.x*2;
                q.push(l2);
            }
        }
        printf("%d\n",ans);
        break;
    }
    return 0;
}

