
/*
0_0_21149818_10121\Main.java:1: 错误: 非法字符: '#'
#include <cstdio>
^
0_0_21149818_10121\Main.java:1: 错误: 需要class, interface或enum
#include <cstdio>
         ^
0_0_21149818_10121\Main.java:2: 错误: 非法字符: '#'
#include <cstring>
^
0_0_21149818_10121\Main.java:4: 错误: 需要class, interface或enum
int a[110];
^
0_0_21149818_10121\Main.java:5: 错误: 需要class, interface或enum
int main() {
^
0_0_21149818_10121\Main.java:7: 错误: 需要class, interface或enum
    jc[0]=1;
    ^
0_0_21149818_10121\Main.java:8: 错误: 需要class, interface或enum
    for(int i=1;i<101;i++)jc[i]=jc[i-1]*i;
    ^
0_0_21149818_10121\Main.java:8: 错误: 需要class, interface或enum
    for(int i=1;i<101;i++)jc[i]=jc[i-1]*i;
                ^
0_0_21149818_10121\Main.java:8: 错误: 需要class, interface或enum
    for(int i=1;i<101;i++)jc[i]=jc[i-1]*i;
                      ^
0_0_21149818_10121\Main.java:9: 错误: 需要class, interface或enum
    while(~scanf("%d%d",&n,&m)){
    ^
0_0_21149818_10121\Main.java:10: 错误: 需要class, interface或enum
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
                    ^
0_0_21149818_10121\Main.java:10: 错误: 需要class, interface或enum
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
                        ^
0_0_21149818_10121\Main.java:11: 错误: 需要class, interface或enum
        memset(c1,0,sizeof(c1));
        ^
0_0_21149818_10121\Main.java:12: 错误: 需要class, interface或enum
        memset(c2,0,sizeof(c2));
        ^
0_0_21149818_10121\Main.java:13: 错误: 需要class, interface或enum
        for(int i=0;i<=a[0];i++)c1[i]=1/jc[i];
        ^
0_0_21149818_10121\Main.java:13: 错误: 需要class, interface或enum
        for(int i=0;i<=a[0];i++)c1[i]=1/jc[i];
                    ^
0_0_21149818_10121\Main.java:13: 错误: 需要class, interface或enum
        for(int i=0;i<=a[0];i++)c1[i]=1/jc[i];
                            ^
0_0_21149818_10121\Main.java:14: 错误: 需要class, interface或enum
        for(int i=1;i<n;i++){
        ^
0_0_21149818_10121\Main.java:14: 错误: 需要class, interface或enum
        for(int i=1;i<n;i++){
                    ^
0_0_21149818_10121\Main.java:14: 错误: 需要class, interface或enum
        for(int i=1;i<n;i++){
                        ^
0_0_21149818_10121\Main.java:15: 错误: 需要class, interface或enum
            for(int j=0;j<=m;j++){
                        ^
0_0_21149818_10121\Main.java:15: 错误: 需要class, interface或enum
            for(int j=0;j<=m;j++){
                             ^
0_0_21149818_10121\Main.java:16: 错误: 需要class, interface或enum
                for(int k=0;k+j<=m&&k<=a[i];k++){
                            ^
0_0_21149818_10121\Main.java:16: 错误: 需要class, interface或enum
                for(int k=0;k+j<=m&&k<=a[i];k++){
                                            ^
0_0_21149818_10121\Main.java:18: 错误: 需要class, interface或enum
                }
                ^
0_0_21149818_10121\Main.java:20: 错误: 需要class, interface或enum
            for(int j=0;j<=m;j++)c1[j]=c2[j],c2[j]=0;
                        ^
0_0_21149818_10121\Main.java:20: 错误: 需要class, interface或enum
            for(int j=0;j<=m;j++)c1[j]=c2[j],c2[j]=0;
                             ^
0_0_21149818_10121\Main.java:21: 错误: 需要class, interface或enum
        }
        ^
0_0_21149818_10121\Main.java:23: 错误: 需要class, interface或enum
    }
    ^
0_0_21149818_10121\Main.java:25: 错误: 需要class, interface或enum
}
^
30 个错误
*/
#include <cstdio>
#include <cstring>
double c1[110],c2[110],jc[110];
int a[110];
int main() {
    int n,m;
    jc[0]=1;
    for(int i=1;i<101;i++)jc[i]=jc[i-1]*i;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=0;i<=a[0];i++)c1[i]=1/jc[i];
        for(int i=1;i<n;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k+j<=m&&k<=a[i];k++){
                    c2[j+k]+=c1[j]/jc[k];
                }
            }
            for(int j=0;j<=m;j++)c1[j]=c2[j],c2[j]=0;
        }
        printf("%.0f\n", c1[m]*jc[m]);
    }
    return 0;
}

