
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=150010;
char s[maxn];
int sa[maxn],Rank[maxn];
int t1[maxn],t2[maxn],c[maxn],n;
int to[maxn][20];
void build_sa(int m) {
    int *x = t1, *y = t2;
    //基数排序
    for(int i = 0; i < m; i++) c[i] = 0;
    for(int i = 0; i < n; i++) c[x[i] = s[i]]++;
    for(int i = 1; i < m; i++) c[i] += c[i-1];
    for(int i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
    for(int i = n-1; i>= 0; i--) Rank[sa[i]] = i;
    int l=0;
    for(int k = 1; k <= n; k <<= 1) {
        l++;
        int p = 0;
        //直接利用sa数组排序第二关键字
        for(int i = 0; i < n; i++) c[i] = 0;
        for(int i = 0; i < n; i++) c[Rank[to[i][l]]]++;
        for(int i = 1; i < n; i++) c[i] += c[i-1];
        for(int i = 0; i < n; i++) y[--c[Rank[to[i][l]]]]=i;
        //基数排序第一关键字
        for(int i = 0; i < m; i++) c[i] = 0;
        for(int i = 0; i < n; i++) c[x[y[i]]]++;
        for(int i = 1; i < m; i++) c[i] += c[i-1];
        for(int i = n-1; i>= 0; i--) sa[--c[x[y[i]]]] = y[i];
        for(int i = n-1; i>= 0; i--) Rank[sa[i]] = i;
        //根据sa和y数组计算新的x数组
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for(int i = 1; i < n; i++)
            x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[to[sa[i-1]][l]]==y[to[sa[i]][l]] ? p-1:p++;
        if(p >= n) break;
        m = p;
    }
}
int main() {
    int ca,kase=0;
//    freopen("data.txt","r",stdin);
//    freopen("ans.txt","w",stdout);
    scanf("%d",&ca);
    while(ca--){
        scanf("%d",&n);
        scanf("%s",s);
        for(int i=0;i<n;i++){
            int u=i,v=((ll)i*i+1)%n;
            to[u][1]=v;
        }
        for(int i=0;i<n;i++){
            for(int j=2;(1<<j)<=2*n;j++){
                to[i][j]=to[to[i][j-1]][j-1];
            }
        }
        build_sa(100);
        int p=sa[n-1];
        printf("Case #%d: ",++kase);
        for(int i=0;i<n;i++){
            printf("%c",s[p]);
            p=((ll)p*p+1)%n;
        }
        printf("\n");
    }
    return 0;
}
/*
1
6
615661
*/

