
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
book a[1000010],tmp[1000010];
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
    map<string,book>ma2;
    priority_queue<int,vector<int>,greater<int> > qu;
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
            int ff=ma[gg];
            qu.push(ff);
            ma2[gg]=a[ff];
          //  printf("pos=%d dc=%d\n",ff,dc);
        }else if(in[0]=='R'){
            int p=0;
            while(p<len&&in[p]!='\"')p++;
            int pos=0;
            p++;
            while(p<len&&in[p]!='\"')gg[pos++]=in[p++];
            gg[pos]=0;
            tmp[tc++]=ma2[gg];
         //   printf("get=%d tc=%d\n",ff,tc);
        }else{
            sort(tmp,tmp+tc);
            for(int i=0;i<tc;i++){
                int ff=qu.top();
                qu.pop();
                a[ff]=tmp[i];
                ma[tmp[i].name]=ff;
       //         printf("i=%d ff=%d\n",i,ff);
                if(ff){
                    printf("Put \"%s\" after \"%s\"\n",a[ff].name.c_str(),a[ff-1].name.c_str());
                }else{
                    printf("Put \"%s\" first\n",a[ff].name.c_str());
                }
            }
            printf("END\n");
            tc=0;
        }
    }
    return 0;
}

