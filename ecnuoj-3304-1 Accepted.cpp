
#include<bits/stdc++.h>
using namespace std;
char s[20];
char e[20];
int a;
struct node{
    int x,y,n;
};
vector<node> x;
int high=1e9+2,low=-2;
int main(){
    int n;
    scanf("%d",&n);
    x.push_back((node){low,high,0});
    for(int i=0;i<n;i++){
        scanf("%s%s%d",e,s,&a);
        int ll,rr;
        if(strcmp(s,"<")==0){
            ll=low;rr=a-1;
        }else if(strcmp(s,"<=")==0){
            ll=low;rr=a;
        }else if(strcmp(s,"=")==0){
            ll=rr=a;
        }else if(strcmp(s,">")==0){
            ll=a+1;rr=high;
        }else if(strcmp(s,">=")==0){
            ll=a;rr=high;
        }
        int sz=x.size();
        for(int j=0;j<sz;j++){
            if(x[j].x>=ll&&x[j].y<=rr){
                x[j].n++;
            }else if(x[j].x<=ll&&x[j].y>=rr){
                if(x[j].x==ll){
                    x.push_back((node){rr+1,x[j].y,x[j].n});
                    x[j].y=rr;
                    x[j].n++;
                }else if(x[j].y==rr){
                    x.push_back((node){x[j].x,ll-1,x[j].n});
                    x[j].x=ll;
                    x[j].n++;
                }else{
                    x.push_back((node){x[j].x,ll-1,x[j].n});
                    x.push_back((node){rr+1,x[j].y,x[j].n});
                    x[j].x=ll;
                    x[j].y=rr;
                    x[j].n++;
                }
            }else if(x[j].x<ll&&x[j].y>=ll){
                x.push_back((node){x[j].x,ll-1,x[j].n});
                x[j].x=ll;
                x[j].n++;
            }else if(ll<x[j].x&&rr>=x[j].x){
                x.push_back((node){rr+1,x[j].y,x[j].n});
                x[j].y=rr;
                x[j].n++;
            }
        }
    }
    int sz=x.size();
    int ans=0;
    for(int i=0;i<sz;i++){
        ans=max(ans,x[i].n);
    }
    printf("%d\n",ans);
    return 0;
}

