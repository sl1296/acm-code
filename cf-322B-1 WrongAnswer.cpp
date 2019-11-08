
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
  int r,g,b;
  while(scanf("%d%d%d",&r,&g,&b)!=EOF){
    int ans=0;
    ans=r/3+g/3+b/3;
    r%=3;b%=3;g%=3;
    int k=min(r,min(g,b));
    ans+=k;
    printf("%d\n",ans);
  }
  return 0;
}

