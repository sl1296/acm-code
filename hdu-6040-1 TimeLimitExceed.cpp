
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
unsigned x,y,z;
int n,m;
int a[110];
unsigned rng61() {
  unsigned t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}
unsigned b[10000010];
int main(){
    int cas=1;
    while(~scanf("%d%d%u%u%u",&n,&m,&x,&y,&z)){
        for(int i=0;i<m;i++)scanf("%d",&a[i]);
        for(int i=0;i<n;i++)b[i]=rng61();
        sort(b,b+n);
        printf("Case #%d:",cas++);
        for(int i=0;i<m;i++)printf(" %d",b[i]);
        printf("\n");
    }
    return 0;
}



