
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
using namespace std;
struct node{
    int x[15];
    node(){
        memset(x,0,sizeof(x));
    }
    bool operator < (const node &p) const{
        for(int i=0;i<15;i++)if(x[i]!=p.x[i])return x[i]<p.x[i];
        return false;
    }
};
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        map<node,int> ma;
        node tmp=node();
        ma[tmp]=2;
        for(int i=0;i<n;i++)scanf("%d",&tmp.x[i]);
        int ans=ma[tmp];
        while(ans==0){
            ma[tmp]=1;
            node add=node();
            for(int i=1;i<n;i++)add.x[i-1]=abs(tmp.x[i]-tmp.x[i-1]);
            add.x[n-1]=abs(tmp.x[0]-tmp.x[n-1]);
            tmp=add;
            ans=ma[tmp];
        }
        if(ans==2){
            printf("ZERO\n");
        }else{
            printf("LOOP\n");
        }
    }
    return 0;
}

