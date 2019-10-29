
#include<bits/stdc++.h>
using namespace std;
vector<int> vec[3];
int main(){
    int n;
    scanf("%d",&n);
    int ans=0,op,v,x=0;
    for(int i=0;i<n;i++){
        scanf("%d%d",&op,&v);
        if(op==11){
            ans+=v;
            x++;
        }
        else if(op==0) vec[0].push_back(v);
        else if(op==1) vec[1].push_back(v);
        else vec[2].push_back(v);
    }
    int k=min(vec[1].size(),vec[2].size());
    sort(vec[1].begin(),vec[1].end(),greater<int>());
    sort(vec[2].begin(),vec[2].end(),greater<int>());
    for(int i=0;i<k;i++) ans+=vec[1][i]+vec[2][i];
    for(int i=k;i<vec[1].size();i++) vec[0].push_back(vec[1][i]);
    for(int i=k;i<vec[2].size();i++) vec[0].push_back(vec[2][i]);
    sort(vec[0].begin(),vec[0].end(),greater<int>());
    k=min((int)vec[0].size(),x);
    for(int i=0;i<k;i++) ans+=vec[0][i];
    printf("%d\n",ans);
    return 0;
}

