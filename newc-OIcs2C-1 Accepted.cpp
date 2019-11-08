
#include<cstdio>
#include<queue>
using namespace std;
struct node{
    int id,x;
    bool operator < (const node &p) const{
        return x>p.x;
    }
};
priority_queue<node> qu;
int a[10010],b[10010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        while(!qu.empty() && qu.top().x<a[i]){
            b[qu.top().id]=i;
            qu.pop();
        }
        qu.push((node){i,a[i]});
    }
    for(int i=1;i<=n;++i){
        if(i>1)printf(" ");
        printf("%d",b[i]);
    }
    printf("\n");
    return 0;
}

