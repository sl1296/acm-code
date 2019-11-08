
#include <bits/stdc++.h>
using namespace std;
char st[20];
string remove(string st,char c)
{
    string s="";
    for(int i=0;i<st.length();++i)
        if(st[i]!=c) s+=st[i];
//    cout<<s<<" !!"<<endl;
    return s;
}
int calc(string st)
{
    int ans=0;
    while(true)
    {
        bool flag=false;
        int cnt=1;
        for(int i=1;i<st.length();++i)
            if(st[i]==st[i-1])
            {
                ++cnt;
                if(cnt==3)
                {
                    st=remove(st,st[i]);
                    ++ans;
                    flag=true;
                    break;
                }
            }
            else cnt=1;
//        cout<<st<<endl;
        if(!flag) break;
    }
    return ans;
}
void test()
{
    string st="123";
    cout<<st<<endl;
}
int main()
{
//    test();
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%s",st);
        int ans=calc(st);
//        printf("%d 0\n",ans);
        string s=remove(st,'g');
        ans=max(ans,calc(s));
        s=remove(s,'a');
        ans=max(ans,calc(s));
        s=remove(st,'a');
        ans=max(ans,calc(s));
        s=remove(st,'o');
        ans=max(ans,calc(s));
        s=remove(st,'o');
        ans=max(ans,calc(s));
        s=remove(st,'g');
        ans=max(ans,calc(s));
        printf("%d\n",ans);
    }
    return 0;
}

