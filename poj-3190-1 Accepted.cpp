
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n;
struct node{
    int l,r,id;
    bool operator < (const node &p) const{
        return l<p.l;
    }
};
struct stt{
    int id,en;
    bool operator < (const stt &p) const{
        return en>p.en;
    }
};
node a[50010];
int ans[50010];
int main(){
   // system("chcp 936");
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].l,&a[i].r);
            a[i].id=i;
        }
        sort(a,a+n);
        priority_queue<stt> qu;
        qu.push((stt){1,a[0].r});
        ans[a[0].id]=1;
        int cnt=1;
        for(int i=1;i<n;i++){
            stt tmp=qu.top();
            if(a[i].l>tmp.en){
                qu.pop();
                qu.push((stt){tmp.id,a[i].r});
                ans[a[i].id]=tmp.id;
            }else{
                qu.push((stt){++cnt,a[i].r});
                ans[a[i].id]=cnt;
            }
        }
        printf("%d\n",cnt);
        for(int i=0;i<n;i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}

