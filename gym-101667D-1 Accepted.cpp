
#include<bits/stdc++.h>
using namespace std;
set<int> st;
int main(){
    int n;
    scanf("%d",&n);
    bool flag=false;
    while(!st.count(n)){
        st.insert(n);
        int ans=0;
        while(n){
            ans+=(n%10)*(n%10);
            n/=10;
        }
        if(ans==1){
            flag=true;break;
        }
        n=ans;
    }
    printf("%s\n",flag?"HAPPY":"UNHAPPY");
    return 0;
}

