
/*
0_0_21149818_10121\Main.java:1: ����: �Ƿ��ַ�: '#'
#include <cstdio>
^
0_0_21149818_10121\Main.java:1: ����: ��Ҫclass, interface��enum
#include <cstdio>
         ^
0_0_21149818_10121\Main.java:2: ����: �Ƿ��ַ�: '#'
#include <cstring>
^
0_0_21149818_10121\Main.java:4: ����: ��Ҫclass, interface��enum
int a[110];
^
0_0_21149818_10121\Main.java:5: ����: ��Ҫclass, interface��enum
int main() {
^
0_0_21149818_10121\Main.java:7: ����: ��Ҫclass, interface��enum
    jc[0]=1;
    ^
0_0_21149818_10121\Main.java:8: ����: ��Ҫclass, interface��enum
    for(int i=1;i<101;i++)jc[i]=jc[i-1]*i;
    ^
0_0_21149818_10121\Main.java:8: ����: ��Ҫclass, interface��enum
    for(int i=1;i<101;i++)jc[i]=jc[i-1]*i;
                ^
0_0_21149818_10121\Main.java:8: ����: ��Ҫclass, interface��enum
    for(int i=1;i<101;i++)jc[i]=jc[i-1]*i;
                      ^
0_0_21149818_10121\Main.java:9: ����: ��Ҫclass, interface��enum
    while(~scanf("%d%d",&n,&m)){
    ^
0_0_21149818_10121\Main.java:10: ����: ��Ҫclass, interface��enum
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
                    ^
0_0_21149818_10121\Main.java:10: ����: ��Ҫclass, interface��enum
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
                        ^
0_0_21149818_10121\Main.java:11: ����: ��Ҫclass, interface��enum
        memset(c1,0,sizeof(c1));
        ^
0_0_21149818_10121\Main.java:12: ����: ��Ҫclass, interface��enum
        memset(c2,0,sizeof(c2));
        ^
0_0_21149818_10121\Main.java:13: ����: ��Ҫclass, interface��enum
        for(int i=0;i<=a[0];i++)c1[i]=1/jc[i];
        ^
0_0_21149818_10121\Main.java:13: ����: ��Ҫclass, interface��enum
        for(int i=0;i<=a[0];i++)c1[i]=1/jc[i];
                    ^
0_0_21149818_10121\Main.java:13: ����: ��Ҫclass, interface��enum
        for(int i=0;i<=a[0];i++)c1[i]=1/jc[i];
                            ^
0_0_21149818_10121\Main.java:14: ����: ��Ҫclass, interface��enum
        for(int i=1;i<n;i++){
        ^
0_0_21149818_10121\Main.java:14: ����: ��Ҫclass, interface��enum
        for(int i=1;i<n;i++){
                    ^
0_0_21149818_10121\Main.java:14: ����: ��Ҫclass, interface��enum
        for(int i=1;i<n;i++){
                        ^
0_0_21149818_10121\Main.java:15: ����: ��Ҫclass, interface��enum
            for(int j=0;j<=m;j++){
                        ^
0_0_21149818_10121\Main.java:15: ����: ��Ҫclass, interface��enum
            for(int j=0;j<=m;j++){
                             ^
0_0_21149818_10121\Main.java:16: ����: ��Ҫclass, interface��enum
                for(int k=0;k+j<=m&&k<=a[i];k++){
                            ^
0_0_21149818_10121\Main.java:16: ����: ��Ҫclass, interface��enum
                for(int k=0;k+j<=m&&k<=a[i];k++){
                                            ^
0_0_21149818_10121\Main.java:18: ����: ��Ҫclass, interface��enum
                }
                ^
0_0_21149818_10121\Main.java:20: ����: ��Ҫclass, interface��enum
            for(int j=0;j<=m;j++)c1[j]=c2[j],c2[j]=0;
                        ^
0_0_21149818_10121\Main.java:20: ����: ��Ҫclass, interface��enum
            for(int j=0;j<=m;j++)c1[j]=c2[j],c2[j]=0;
                             ^
0_0_21149818_10121\Main.java:21: ����: ��Ҫclass, interface��enum
        }
        ^
0_0_21149818_10121\Main.java:23: ����: ��Ҫclass, interface��enum
    }
    ^
0_0_21149818_10121\Main.java:25: ����: ��Ҫclass, interface��enum
}
^
30 ������
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

