
#include <bits/stdc++.h>;
using namespace std;
#define ll long long
char a[30][30];
char ia[30],ic[30];
int ct[100010],cf[100010],tt[100010][10],ff[100010][10];
char xx[100010][30];
int n,m,cnt=1;
map<string,int> mp;
char ans[30][30];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%s",a[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%s%s%s",ia,xx[i],ic);
        int pos=mp[ia];
        if(!pos){
            mp[ia]=cnt;
            pos=cnt++;
            ct[pos]=cf[pos]=0;
        }
        if(ic[0]=='c')tt[pos][ct[pos]++]=i;
        else ff[pos][cf[pos]++]=i;
    }
    ll tr=0,fa=0;
    bool mul=false,ch=true;
    for(int i=0;i<n;++i){
        int pos=mp[a[i]];
        if(mul){
            fa=tr*cf[pos]+fa*(cf[pos]+ct[pos]);
            tr=tr*ct[pos];
        }else{
            if(ct[pos]+cf[pos]==1){
                if(ct[pos]){
                    strcpy(ans[i],xx[tt[pos][0]]);
                }else{
                    strcpy(ans[i],xx[ff[pos][0]]);
                    ch=false;
                }
            }else{
                mul=true;
                if(ch){
                    tr=ct[pos];
                    fa=cf[pos];
                }else{
                    fa=cf[pos]+ct[pos];
                }
            }
        }
    }
    if(mul){
        printf("%lld correct\n%lld incorrect\n",tr,fa);
    }else{
        for(int i=0;i<n;++i){
            if(i)printf(" ");
            printf("%s",ans[i]);
        }
        printf("\n");
        if(ch)printf("correct\n");else printf("incorrect\n");
    }
    return 0;
}


