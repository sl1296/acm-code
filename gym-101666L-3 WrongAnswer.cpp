
#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
string s1,s2;
map<string,double> mp;
int main(){
    int n;
    cin>>n;
    double w;
    int sz=0;
    mp["pink"]=1.0;
    for(int i=0;i<n;i++){
        cin>>s1>>s2>>w;
        mp[s1]=max(mp[s1],mp[s2]*w);
    }
    printf("%.10f\n",min(mp["blue"],10.0));
    return 0;
}

