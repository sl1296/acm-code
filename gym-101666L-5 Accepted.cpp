
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
    mp["pink"]=log(1.0);
    for(int i=0;i<n;i++){
        cin>>s1>>s2>>w;
        if(mp.count(s2)==0) continue;
        if(mp.count(s1)==0) mp[s1]=-1e18;
        mp[s1]=max(mp[s1],mp[s2]+log(w));
//        printf("%f\n",mp[s1]);
    }
    double x=log(10);
    if(mp.count("blue")==0) printf("0\n");
    else printf("%.10f\n",x<mp["blue"]?10.0:exp(mp["blue"]));
    return 0;
}

