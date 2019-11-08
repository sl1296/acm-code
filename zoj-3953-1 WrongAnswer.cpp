
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
    int l,r;
    bool operator < (const node &p) const{
        return r<p.r;
    }
};
node a[50010];
int dec[500101],cc;
int main(){
    //system("chcp 936");
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        cc=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].l,&a[i].r);
        }
        if(n<3){
            printf("0\n\n");
            continue;
        }
        sort(a,a+n);
        int last=a[0].r;
        int pos=1;
        for(int i=2;i<n;i++){
            if(a[i].l>last){
                last=a[pos].r;
                pos=i;
            }else{
                dec[cc++]=i+1;
            }
        }
        printf("%d\n",cc);
        for(int i=0;i<cc;i++){
            if(i)printf(" ");
            printf("%d",dec[i]);
        }
        printf("\n");
    }
    return 0;
}

