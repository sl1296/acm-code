
#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
typedef unsigned long long ull;
double v[maxn];
char s1[111],s2[111];
map<ull,int> mp;
int main(){
    int n;
    scanf("%d",&n);
    double w;
    int sz=0;
    char s3[]="pink";
    char s4[]="blue";
    ull h1=0,h2=0;
    for(int j=0;s3[j];j++) h1=h1*10007+s3[j];
    for(int j=0;s4[j];j++) h2=h2*10007+s4[j];
    mp[h1]=sz++;
    mp[h2]=sz++;
    v[0]=1.0;
    for(int i=0;i<n;i++){
        scanf("%s%s%lf",s1,s2,&w);
        ull h1=0,h2=0;
        int x1,x2;
        for(int j=0;s1[j];j++) h1=h1*10007+s1[j];
        for(int j=0;s2[j];j++) h2=h2*10007+s2[j];
        if(mp.count(h1)) x1=mp[h1];
        else x1=mp[h1]=sz++;
        if(mp.count(h2)) x2=mp[h2];
        else x2=mp[h2]=sz++;
        v[x1]=max(v[x1],v[x2]*w);
    }
    printf("%.10f\n",min(v[1],10.0));
    return 0;
}

