
#include<bits/stdc++.h>
#define ll long long
using namespace std;
char n[110][110];
char in[1000];
ll p[110],c[110],t[110],r[110];
int main(){
    ll l,m;
    scanf("%I64d%I64d",&l,&m);
    vector<int> ans;
    ll pri=99999999;
    gets(in);
    for(int i=0;i<m;++i){
        gets(in);
        int pp=0,pt=0;
        while(in[pp]!=',')n[i][pt]=in[pp],++pp,++pt;
        n[i][pt]=0;
        ++pp;
        while(in[pp]!=',')p[i]=p[i]*10+in[pp]-48,++pp;
        ++pp;
        while(in[pp]!=',')c[i]=c[i]*10+in[pp]-48,++pp;
        ++pp;
        while(in[pp]!=',')t[i]=t[i]*10+in[pp]-48,++pp;
        ++pp;
        while(in[pp]!=0)r[i]=r[i]*10+in[pp]-48,++pp;
//        printf("%s||%lld||%lld||%lld||%lld\n",n[i],p[i],c[i],t[i],r[i]);
        ll zq=t[i]+r[i];
        ll cs=zq/__gcd(10080LL,zq);
        bool ch=true;
        for(int j=1;j<=cs;++j){
            ll tim=j*10080;
            ll sum=tim/zq*c[i]*t[i]+min(tim%zq,t[i])*c[i];
            if(sum<j*l){
                ch=false;
                break;
            }
        }
        if(ch){
            if(p[i]<pri){
                pri=p[i];
                ans.clear();
                ans.push_back(i);
            }else if(p[i]==pri){
                ans.push_back(i);
            }
        }
    }
    if(pri==99999999){
        printf("no such mower\n");
    }else{
        for(int i=0;i<ans.size();++i){
            printf("%s\n",n[ans[i]]);
        }
    }
    return 0;
}

