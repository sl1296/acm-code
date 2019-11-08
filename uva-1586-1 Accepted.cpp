
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;
map<char,double> ma;
int main(){
    int t;
    double ans;
    scanf("%d",&t);
    ma['C']=12.01;
    ma['H']=1.008;
    ma['O']=16;
    ma['N']=14.01;
    while(t--){
        char s[100];
        ans=0;
        scanf("%s",s);
        int l=strlen(s);
        for(int i=0;i<l;i++){
            double tmp=ma[s[i]];
            if(s[i+1]==0 || s[i+1]>'9'){
                ans+=tmp;
            }else{
                int tt=s[i+1]-'0';
                if(s[i+2]==0 || s[i+2]>'9'){
                    ans+=tmp*tt;
                    i++;
                }else{
                    tt=tt*10+s[i+2]-'0';
                    i+=2;
                    ans+=tmp*tt;
                }
            }
        }
        printf("%.3f\n",ans);
    }
    return 0;
}

