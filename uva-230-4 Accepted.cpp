
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
struct book{
    string name,author;
    bool operator < (const book &p) const{
        if(author!=p.author)return author<p.author;
        return name<p.name;
    }
};
book a[1000010];
int tmp[1000010];
bool use[1000010];
int tc;
char in[1010];
char gg[1010];
int main(){
    int cnt=0;
    while(1){
        gets(in);
        if(strcmp(in,"END")==0)break;
        int len=strlen(in);
        int p=0;
        while(p<len&&in[p]!='\"')p++;
        int pos=0;
        p++;
        while(p<len&&in[p]!='\"')gg[pos++]=in[p++];
        gg[pos]=0;
        a[cnt].name=gg;
        while(p<len&&in[p]!='b')p++;
        p+=2;
        while(p<len&&in[p]==' ')p++;
        a[cnt++].author=&in[p];
    }
    sort(a,a+cnt);
    map<string,int> ma;
    for(int i=0;i<cnt;i++){
        ma[a[i].name]=i;
    }
    while(1){
        gets(in);
        if(strcmp(in,"END")==0)break;
        int len=strlen(in);
        if(in[0]=='B'){
            int p=0;
            while(p<len&&in[p]!='\"')p++;
            int pos=0;
            p++;
            while(p<len&&in[p]!='\"')gg[pos++]=in[p++];
            gg[pos]=0;
            use[ma[gg]]=true;
        }else if(in[0]=='R'){
            int p=0;
            while(p<len&&in[p]!='\"')p++;
            int pos=0;
            p++;
            while(p<len&&in[p]!='\"')gg[pos++]=in[p++];
            gg[pos]=0;
            tmp[tc++]=ma[gg];
        }else{
            sort(tmp,tmp+tc);
            for(int i=0;i<tc;i++){
                int pre=tmp[i]-1;
                while(pre>=0&&use[pre])pre--;
                use[tmp[i]]=false;
                if(pre>=0){
                    printf("Put \"%s\" after \"%s\"\n",a[tmp[i]].name.c_str(),a[pre].name.c_str());
                }else{
                    printf("Put \"%s\" first\n",a[tmp[i]].name.c_str());
                }
            }
            printf("END\n");
            tc=0;
        }
    }
    return 0;
}

