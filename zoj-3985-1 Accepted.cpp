
#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int v[maxn];
char s[maxn];
int main(){
    int ca;
    scanf("%d",&ca);
    while(ca--){
        int len=0,n;
        char c='C';
        scanf("%d%s",&n,s);
        int ans=0;
        v[0]=0;
        for(int i=0;i<n;i++){
            if(s[i]==c) v[len]++;
            else{
                v[++len]=1;
                c=s[i];
            }
        }
        bool flag=false;
        v[len+1]=0;
        for(int i=0;i<=len;i++){
            if(i%2==0){
                if(v[i]>3||v[i]==3&&i==len) flag=true;
            }else{
                if(v[i]==1&&v[i-1]>1&&v[i+1]>0) ans++;
                if(v[i]>1&&v[i-1]>1) flag=true;
                if(v[i]==1&&v[i-1]>1&&i==len) flag=true;
                if(v[i]==1&&v[i-1]==1&&v[i+1]>0) flag=true;
            }
        }
        printf("%d\n",ans+flag);
    }
    return 0;
}

