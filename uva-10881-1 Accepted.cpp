
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct no{
    int pos,id,dir;
    bool operator < (const no &p) const{
        return p.pos<pos;
    }
};
no my[10010],to[10010];
int pos[10010];
char so[5][20]={"L","Turning","R"};
int main(){
    int t;
    scanf("%d",&t);
    int cas=0;
    while(t--){
        int l,ti,n;
        scanf("%d%d%d",&l,&ti,&n);
        for(int i=0;i<n;i++){
            char s[5];
            scanf("%d%s",&my[i].pos,s);
            my[i].id=i;
            my[i].dir=(s[0]=='L'?-1:1);
            to[i].pos=my[i].pos+ti*my[i].dir;
            to[i].dir=my[i].dir;
        }
        sort(my,my+n);
        for(int i=0;i<n;i++)pos[my[i].id]=i;
        sort(to,to+n);
        for(int i=0;i<n-1;i++){
            if(to[i].pos==to[i+1].pos)to[i].dir=to[i+1].dir=0;
        }
        cas++;
        printf("Case #%d:\n",cas);
        for(int i=0;i<n;i++){
            int x=pos[i];
            if(to[x].pos<0 || to[x].pos>l)printf("Fell off\n");
            else printf("%d %s\n",to[x].pos,so[to[x].dir+1]);
        }
        printf("\n");
    }
    return 0;
}

