
#include<cstdio>
#include<cmath>
int b[100010],z[100010],a[100010];
int n;
inline int lowbit(int x){
    return x&-x;
}
inline int query(int x){
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i))ret+=z[i];
    return ret;
}
inline void update(int x){
    for(int i=x;i<=n;i+=lowbit(i))++z[i];
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&b[i]);
    }
    for(int i=n;i>0;--i){
        int s=1,e=n,mid,aim=sqrt(i);
        while(s<e){
            mid=s+(e-s)/2;
            if(mid-query(mid)<aim)s=mid+1;
            else e=mid;
        }
        update(s);
        a[s]=b[n-i];
    }
    for(int i=1;i<=n;++i){
        if(i-1)printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}
 
/**************************************************************
    Problem: 1015
    User: asdcvbn
    Language: C++
    Result: ÕýÈ·
    Time:67 ms
    Memory:2304 kb
****************************************************************/

