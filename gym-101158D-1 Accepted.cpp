
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
string s1,s2;
set<ull> se;
vector<int> vec;
ull Hash(){
    ull h=0;
    for(int i=0;i<26;i++)
        h=h*10007+vec[i];
    return h;
}
int main()
{
    cin>>s1>>s2;
    int len=min(s1.size(),s2.size());
    bool flag=false;
    for(int l=len;l>=0;--l)
    {
        if(l==0)
        {
            printf("0\n");break;
        }
        vec=vector<int>(26);
        for(int j=0;j<l;j++)
            vec[s2[j]-'a']++;
        se.insert(Hash());
        for(int i=l;i<s2.size();++i)
        {
            vec[s2[i-l]-'a']--;
            vec[s2[i]-'a']++;
            se.insert(Hash());
        }
        vec=vector<int>(26);
        for(int i=0;i<l;i++)
            vec[s1[i]-'a']++;
        flag=se.count(Hash());
        for(int i=l;i<s1.size()&&!flag;++i)
        {
            vec[s1[i-l]-'a']--;
            vec[s1[i]-'a']++;
            if(se.count(Hash()))
            {
                flag=true;
                break;
            }
        }
        if(flag){
            printf("%d\n",l);
            break;
        }
        se.clear();
    }
    return 0;
}

