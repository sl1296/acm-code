
#include<cstdio>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
priority_queue<int,vector<int>,greater<int> > qu;

int main(){
    int n;
    while(~scanf("%d",&n)){
        ll ans=0;
        int a;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            qu.push(a);
        }
        for(int i=1;i<n;i++){
            int sum=qu.top();
            qu.pop();
            sum+=qu.top();
            qu.pop();
            qu.push(sum);
            ans+=sum;
        }
        printf("%lld\n",ans);
        qu.pop();
    }
    return 0;
}

