
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>
using namespace std;
vector<set<int> > ys;
map<set<int>,int> ma;
stack<set<int> > zh;
int id;
int getid(set<int> x){
    int re=ma[x];
    if(re)return re;
    ma[x]=++id;
    ys.push_back(x);
    return id;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        while(!zh.empty())zh.pop();
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            char in[10];
            scanf("%s",in);
            if(in[0]=='P'){
                zh.push(set<int>());
            }else if(in[0]=='D'){
                zh.push(zh.top());
            }else if(in[0]=='A'){
                set<int> t1=zh.top();
                zh.pop();
                set<int> t2=zh.top();
                zh.pop();
                t2.insert(getid(t1));
                zh.push(t2);
            }else if(in[0]=='U'){
                set<int> t1=zh.top();
                zh.pop();
                set<int> t2=zh.top();
                zh.pop();
                set<int> xx;
                set_union(t1.begin(),t1.end(),t2.begin(),t2.end(),inserter(xx,xx.begin()));
                zh.push(xx);
            }else if(in[0]=='I'){
                set<int> t1=zh.top();
                zh.pop();
                set<int> t2=zh.top();
                zh.pop();
                set<int> xx;
                set_intersection(t1.begin(),t1.end(),t2.begin(),t2.end(),inserter(xx,xx.begin()));
                zh.push(xx);
            }
            printf("%d\n",zh.top().size());
        }
        printf("***\n");
    }
	return 0;
}

