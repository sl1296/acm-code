
#include <bits/stdc++.h>
using namespace std;
#define N 1000010
char st[N];
char to[256];
int g[30][30];
bool is_consonant(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='w'||c=='y')
        return false;
    return true;
}
int main()
{
    freopen("consonant.in","r",stdin);
    freopen("consonant.out","w",stdout);
    int cnt=0;
    for(char c='a';c<='z';++c)
        if(is_consonant(c))
            to[c]=cnt++;
    scanf("%s",st);
    int len=strlen(st);
    for(int i=1;i<len;++i)
        if(is_consonant(st[i-1])&&is_consonant(st[i]))
            g[to[st[i-1]]][to[st[i]]]++;
    int ans=0,mx=0,tmp;
    for(int s=1;s<(1<<19);++s)
    {
        tmp=0;
        for(int i=0;i<19;++i)
            for(int j=0;j<19;++j)
                if(((s>>i)&1)^((s>>j)&1))
                    tmp+=g[i][j];
        if(tmp>mx)
        {
            mx=tmp;ans=s;
        }
    }
    for(int i=0;i<len;++i)
        if(is_consonant(st[i])&&((ans>>to[st[i]])&1))
            st[i]=st[i]-'a'+'A';
    puts(st);
    return 0;
}
/*
consonants
destruction
strength
*/

