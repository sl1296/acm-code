
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
map<ull,int> mp;
int tot;
struct node{
    int f1[7],f2[7];
    int nz,step;
    ull h;
    node(){
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        step=h=nz=0;
    }
};
double ans=0;
double pro[213455];
bool vis[213455];
queue<node> que;
ull xp[17];
int main(){
    int n,m,d,t;
    xp[0]=1;
    for(int i=1;i<15;i++) xp[i]=xp[i-1]*10;
    scanf("%d%d%d",&n,&m,&d);
    node e;
    e.nz=n+m;
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        e.f2[t]++;
    }
    for(int i=0;i<m;i++){
        scanf("%d",&t);
        e.f1[t]++;
    }
    for(int i=0;i<7;i++) e.h+=e.f1[i]*xp[i]+e.f2[i]*xp[i+7];
    mp[e.h]=tot++;
    pro[mp[e.h]]=1;
    que.push(e);
    while(!que.empty()){
        e=que.front();que.pop();
        double p=pro[mp[e.h]];
//        for(int i=0;i<7;i++)
//            printf("%d%c",e.f1[i],i==6?'\n':' ');
//        for(int i=0;i<7;i++)
//            printf("%d%c",e.f2[i],i==6?'\n':' ');
//        printf("%llu : %d %f\n",e.h,e.nz,pro[mp[e.h]]);
        for(int i=1;i<7;i++){
            if(e.f1[i]){
                node ne=e;
                ne.step++;
                if(i==1) ne.nz--;
                ne.h+=xp[i-1]-xp[i];
                ne.f1[i]--;ne.f1[i-1]++;
                if(ne.f1[0]==m){
                    ans+=p*e.f1[i]/e.nz;
                }else{
                    if(!mp.count(ne.h)) mp[ne.h]=tot++;
                    int id=mp[ne.h];
                    pro[id]+=p*e.f1[i]/e.nz;
                    if(!vis[id]&&ne.step<d){
                        que.push(ne);
                        vis[id]=true;
                    }
                }
            }
            if(e.f2[i]){
                node ne=e;
                ne.step++;
                if(i==1) ne.nz--;
                ne.h+=xp[i+7-1]-xp[i+7];
                ne.f2[i]--;ne.f2[i-1]++;
                if(!mp.count(ne.h)) mp[ne.h]=tot++;
                int id=mp[ne.h];
                pro[id]+=p*e.f2[i]/e.nz;
                if(!vis[id]&&ne.step<d){
                    que.push(ne);
                    vis[id]=true;
                }
            }
        }
    }
    printf("%.10f\n",ans);
    return 0;
}
/*
1 2 2
2
1 1
0 2 0 0 0 0 0
0 0 1 0 0 0 0
0 : 3 1.000000
1 1 0 0 0 0 0
0 0 1 0 0 0 0
0 : 2 1.666667
0.833333
*/

