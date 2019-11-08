
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100002;
int sz[100010];
int lowbit(int x){
    return x&(-x);
}
void add(int x,int v){
    for(int i=x;i<maxn;i+=lowbit(i))sz[i]+=v;
}
int sum(int x){
    int r=0;
    for(int i=x;i>0;i-=lowbit(i))r+=sz[i];
    return r;
}
int main(){
    int m;
    while(~scanf("%d",&m)){
        int all=0;
        for(int i=0;i<m;i++){
            int p;
            scanf("%d",&p);
            if(p==0){
                int e;
                scanf("%d",&e);
                add(e,1);
                all++;
            }else if(p==1){
                int e;
                scanf("%d",&e);
                int cc=sum(e)-sum(e-1);
                if(cc){add(e,-1);all--;}else printf("No Elment!\n");
            }else{
                int a,k;
                scanf("%d%d",&a,&k);
                int cc=sum(a);
                if(all-cc<k){
                    printf("Not Find!\n");
                    continue;
                }
                int l=a+1,r=maxn;
                while(r-l){
                    int m=l+(r-l)/2;
                    int pd=sum(m)-cc;
                    if(pd>k){
                        r=m;
                    }else if(pd<k){
                        l=m+1;
                    }else{
                        if(sum(m-1)-cc==k){
                            r=m-1;
                        }else{
                            l=r=m;
                        }
                    }
                }
                printf("%d\n",l);
            }
        }
    }
    return 0;
}

