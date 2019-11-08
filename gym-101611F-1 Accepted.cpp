
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define N 1010
struct pro{
    char c;
    int a,t;
    pro(){}
    pro(char c,int a,int t):c(c),a(a),t(t){}
};
struct person{
    string nam;
    vector<pro> vec;
}l1[N],l2[N];
int n,m,k;
pii calc(person &p,int &last)
{
    int num=0,consum=0;
    last=0;
    for(auto e:p.vec)
    {
        if(e.c=='+')
        {
            ++num;
            consum+=20*(e.a-1)+e.t;
            last=max(last,e.t);
        }
    }
//    cout<<p.nam<<' '<<num<<' '<<consum<<endl;
    return make_pair(num,consum);
}
bool cmp(person &a,person &b)
{
    int lasta=0,lastb=0;
    pii pa=calc(a,lasta),pb=calc(b,lastb);
    if(pa.first!=pb.first) return pa.first>pb.first;
    if(pa.second!=pb.second) return pa.second<pb.second;
    if(lasta!=lastb) return lasta<lastb;
    return a.nam<b.nam;
}
void doing(person &a)
{
    for(auto &e:a.vec)
    {
        if(e.c!='+')
        {
            e.c='+';
            ++e.a;
            e.t=240;
        }
    }
}
int main()
{
    cin>>n>>m>>k;
    int x,y;
    string st;
    for(int i=1;i<=m;++i)
    {
        cin>>l1[i].nam;
        for(int j=1;j<=n;++j)
        {
            cin>>st>>x>>y;
            l1[i].vec.push_back(pro(st[0],x,y));
        }
    }
    set<string> se;
    for(int i=1;i<=k;++i)
    {
        cin>>l2[i].nam;
        se.insert(l2[i].nam);
        for(int j=1;j<=n;++j)
        {
            cin>>st>>x>>y;
            l2[i].vec.push_back(pro(st[0],x,y));
        }
    }
    sort(l2+1,l2+k+1,cmp);
    bool flag=true;
    for(int i=1;i<=m;++i)
    {
        if(se.count(l1[i].nam)) continue;
//        printf("%d !\n",i);
        if(cmp(l2[1],l1[i])&&cmp(l1[i],l2[k]))
        {
//            printf("%d ?\n",i);
            doing(l1[i]);
            if(cmp(l2[1],l1[i]))
            {
                flag=false;break;
            }
        }
    }
    if(flag) cout<<"Leaked"<<endl;
    else cout<<"Fake"<<endl;
    return 0;
}

