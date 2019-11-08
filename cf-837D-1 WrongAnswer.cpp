
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
struct node{
    int x,e,w;
};
node a[210];
bool cmp1(node a,node b){
    if(a.e!=b.e)return a.e>b.e;
    return a.w>b.w;
}
bool cmp2(node a,node b){
    if(a.w!=b.w)return a.w>b.w;
    return a.e>b.e;
}
bool cmp3(node a,node b){
    return max(a.e,a.w)>max(b.e,b.w);
}
int main(){
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        int ze=0,zw=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i].x);
            int tmp=a[i].x,cnt=0;
            while(tmp%2==0){
                tmp/=2;
                cnt++;
            }
            a[i].e=cnt;
            ze+=cnt;
            cnt=0;
            while(tmp%5==0){
                tmp/=5;
                cnt++;
            }
            a[i].w=cnt;
            zw+=cnt;
        }
        k=n-k;
        int cc=n;
        for(int i=0;i<k;i++){
            if(zw>ze){
                sort(a,a+cc,cmp1);
            }else if(zw<ze){
                sort(a,a+cc,cmp2);
            }else{
                sort(a,a+cc,cmp3);
            }
            cc--;
            zw-=a[cc].w;
            ze-=a[cc].e;
        }
        printf("%d\n",min(zw,ze));
    }
    return 0;
}

