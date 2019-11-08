
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
char in[100010];
string s[100010];
int len[100010];
int main(){
    int n;
    while(~scanf("%d",&n)){
        if(n==0)break;
        gets(in);
        int m=0;
        for(int i=0;i<n;i++){
            gets(in);
            s[i]=in;
        }
        sort(s,s+n);
        for(int i=0;i<n;i++){
            len[i]=s[i].size();
            m=max(m,len[i]);
        }
        int col=(60-m)/(m+2)+1;
        int line=(n+col-1)/col;
        for(int i=0;i<60;i++)printf("-");
        printf("\n");
        for(int i=0;i<line;i++){
            for(int j=0;j<col;j++){
                int id=j*line+i;
                if(id>=n)break;
                printf("%s",s[id].c_str());
                int add=m-len[id];
                if(j<col-1)add+=2;
                for(int i=0;i<add;i++)printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}

