
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
    int l,r,id;
    bool operator < (const node &p) const{
        if(r!=p.r)return r<p.r;
        return l>p.l;
    }
};
node a[50010];
int dec[500101],cc;
int main(){
    //freopen("in.txt","r",stdin);
   // freopen("out.txt","w+",stdout);
   // system("chcp 936");
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        cc=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].l,&a[i].r);
            a[i].id=i+1;
        }
        if(n<3){
            printf("0\n\n");
            continue;
        }
        sort(a,a+n);
        int last=a[0].r;
        int pos=1;
        if(a[0].r<a[1].l)last=-5;
        for(int i=2;i<n;i++){
            if(a[i].l>last){
                if(a[i].l<=a[pos].r)last=a[pos].r;
                pos=i;
            }else{
                dec[cc++]=a[i].id;
            }
        }
        sort(dec,dec+cc);
        printf("%d\n",cc);
        for(int i=0;i<cc;i++){
            if(i)printf(" ");
            printf("%d",dec[i]);
        }
        printf("\n");
    }
    return 0;
}


