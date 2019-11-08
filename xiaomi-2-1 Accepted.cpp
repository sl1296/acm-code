
#include<cstdio>
#include<set>
using namespace std;
int main(){
    set<int> s;
    int x;
    while(~scanf("%d",&x)){
        auto now=s.find(x);
        if(now!=s.end())s.erase(now);
        else s.insert(x);
    }
    for(auto i:s)printf("%d\n",i);
    return 0;
}

