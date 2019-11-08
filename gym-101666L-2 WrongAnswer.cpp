
#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
typedef unsigned long long ull;
double v[maxn];
char s1[111],s2[111];
map<string,int> mp;
int main(){
    int n;
    scanf("%d",&n);
    double w;
    int sz=0;
    mp["pink"]=sz++;
    mp["blue"]=sz++;
    v[0]=1.0;
    for(int i=0;i<n;i++){
        cin>>s1>>s2>>w;
        int x1,x2;
        if(mp.count(s1)) x1=mp[s1];
        else x1=mp[s1]=sz++;
        if(mp.count(s2)) x2=mp[s2];
        else x2=mp[s2]=sz++;
        v[x1]=max(v[x1],v[x2]*w);
    }
    printf("%.10f\n",min(v[1],10.0));
    return 0;
}

