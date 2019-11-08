
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
using namespace std;
int main(){
    char s[50];
    while(scanf("%s",s)!=EOF){
        map<char,int> ma;
        int i;
        for(i=0;i<27;i++){
            if(ma[s[i]] && ma[s[i]]!=i){
                break;
            }else{
                ma[s[i]]=i+1;
            }
        }
        if(i>=27){
            printf("Impossible\n");
        }else{
            int st=ma[s[i]];
            int e=i+1;
            char ss[3][50];
            int len=(e-st)/2+1;
            int j,k;
            int p=st;
            for(j=len-1;j>-1;j--){
                ss[0][j]=s[p-1];
                p++;
            }
            for(j=0;p<e;j++){
                ss[1][j]=s[p-1];
                p++;
            }
            int tt=1;
            int xx=1;
            for(p=e+1;p<28;p++){
                if(j==13){
                    tt=0;
                    xx=-1;
                    j=12;
                }
                ss[tt][j]=s[p-1];
                j+=xx;
            }
            tt=0;
            xx=1;
            j=len;
            for(p=st-1;p>0;p--){
                if(j==13){
                    tt=1;
                    xx=-1;
                    j=12;
                }
                ss[tt][j]=s[p-1];
                j+=xx;
            }
            ss[0][13]=ss[1][13]=0;
            printf("%s\n%s\n",ss[0],ss[1]);
        }
    }
    return 0;
}

