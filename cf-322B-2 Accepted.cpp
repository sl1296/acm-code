
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
  int r,g,b,t;
  while(scanf("%d%d%d",&r,&g,&b)!=EOF){
    int ans=0;
    bool p=false;
    if(r>2&&b>2&&g>2)p=true;
    ans=r/3+g/3+b/3;
    r%=3;b%=3;g%=3;
    if(r>g){t=g;g=r;r=t;}
    if(r>b){t=r;r=b;b=t;}
    if(g>b){t=g;g=b;b=t;}
    if(r==0&&g==b&&g==2&&p)ans++;
    int k=min(r,min(g,b));
    ans+=k;
    printf("%d\n",ans);
  }
  return 0;
}

