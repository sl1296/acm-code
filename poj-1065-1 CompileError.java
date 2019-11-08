
/*
F:\temp\17471611.77250\Main.java:1: illegal character: \35
#include<cstdio>
^
F:\temp\17471611.77250\Main.java:2: illegal character: \35
#include<algorithm>
^
F:\temp\17471611.77250\Main.java:4: class, interface, or enum expected
struct node{
^
F:\temp\17471611.77250\Main.java:6: class, interface, or enum expected
    bool operator < (const node &p) const{
    ^
F:\temp\17471611.77250\Main.java:8: class, interface, or enum expected
        return r<p.r;
        ^
F:\temp\17471611.77250\Main.java:9: class, interface, or enum expected
    }
    ^
F:\temp\17471611.77250\Main.java:11: class, interface, or enum expected
node a[5010];
^
F:\temp\17471611.77250\Main.java:12: class, interface, or enum expected
int main(){
^
F:\temp\17471611.77250\Main.java:14: class, interface, or enum expected
    scanf("%d",&t);
    ^
F:\temp\17471611.77250\Main.java:15: class, interface, or enum expected
    while(t--){
    ^
F:\temp\17471611.77250\Main.java:17: class, interface, or enum expected
        scanf("%d",&n);
        ^
F:\temp\17471611.77250\Main.java:18: class, interface, or enum expected
        for(int i=0;i<n;i++){
        ^
F:\temp\17471611.77250\Main.java:18: class, interface, or enum expected
        for(int i=0;i<n;i++){
                    ^
F:\temp\17471611.77250\Main.java:18: class, interface, or enum expected
        for(int i=0;i<n;i++){
                        ^
F:\temp\17471611.77250\Main.java:20: class, interface, or enum expected
        }
        ^
F:\temp\17471611.77250\Main.java:22: class, interface, or enum expected
        int p=0;
        ^
F:\temp\17471611.77250\Main.java:23: class, interface, or enum expected
        for(int i=0;i<n;i++){
        ^
F:\temp\17471611.77250\Main.java:23: class, interface, or enum expected
        for(int i=0;i<n;i++){
                    ^
F:\temp\17471611.77250\Main.java:23: class, interface, or enum expected
        for(int i=0;i<n;i++){
                        ^
F:\temp\17471611.77250\Main.java:25: class, interface, or enum expected
            a[p++]=a[i];
            ^
F:\temp\17471611.77250\Main.java:26: class, interface, or enum expected
        }
        ^
F:\temp\17471611.77250\Main.java:28: class, interface, or enum expected
        int cnt=0;
        ^
F:\temp\17471611.77250\Main.java:29: class, interface, or enum expected
        for(int i=p-1;i>=0;i--){
        ^
F:\temp\17471611.77250\Main.java:29: class, interface, or enum expected
        for(int i=p-1;i>=0;i--){
                      ^
F:\temp\17471611.77250\Main.java:29: class, interface, or enum expected
        for(int i=p-1;i>=0;i--){
                           ^
F:\temp\17471611.77250\Main.java:32: class, interface, or enum expected
                ans++;
                ^
F:\temp\17471611.77250\Main.java:33: class, interface, or enum expected
            }
            ^
F:\temp\17471611.77250\Main.java:36: class, interface, or enum expected
    }
    ^
F:\temp\17471611.77250\Main.java:38: class, interface, or enum expected
}
^
29 errors
*/
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
    int l,r;
    bool operator < (const node &p) const{
        if(l!=p.l)return l<p.l;
        return r<p.r;
    }
};
node a[5010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].l,&a[i].r);
        }
        sort(a,a+n);
        int p=0;
        for(int i=0;i<n;i++){
            while(i+1<n&&a[i+1].l==a[i].l)i++;
            a[p++]=a[i];
        }
        int ans=0;
        int cnt=0;
        for(int i=p-1;i>=0;i--){
            if(a[i].r>cnt){
                cnt=a[i].r;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

