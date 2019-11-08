
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
unsigned x,y,z;
int n,m;
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
int a[110],xx[110],r[110];
bool cmp(int i,int j){
    return a[i]<a[j];
}
unsigned b[10000010];
int main(){
    int cas=1;
    while(~scanf("%d%d%u%u%u",&n,&m,&x,&y,&z)){
        for(int i=0;i<m;i++){
            scanf("%d",&a[i]);
            xx[i]=i;
        }
        for(int i=0;i<n;i++)b[i]=rng61();
        sort(a,a+m,cmp);
        xx[a[m]=m]=n;
        for(int i=m-1;~i;i--){
            if(a[xx[i]]==a[xx[i+1]]){
                r[xx[i]]=r[xx[i+1]];
            }else{
                nth_element(b,b+a[xx[i]],b+a[xx[i+1]]);
                r[xx[i]]=b[a[xx[i]]];
            }
        }
        printf("Case #%d:",cas++);
        for(int i=0;i<m;i++)printf(" %d",r[i]);
        printf("\n");
    }
    return 0;
}

