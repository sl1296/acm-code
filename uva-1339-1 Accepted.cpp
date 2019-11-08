
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char a[110],b[110];
int sa[110],sb[110],ca,cb;
int main(){
    while(scanf("%s%s",a,b)!=EOF){
        int la=strlen(a),lb=strlen(b);
        sort(a,a+la);
        sort(b,b+lb);
        ca=cb=0;
        for(int i=0;i<la;i++){
            sa[ca]=1;
            while(i+1<la && a[i+1]==a[i]){
                i++;
                sa[ca]++;
            }
            ca++;
        }
        for(int i=0;i<lb;i++){
            sb[cb]=1;
            while(i+1<lb && b[i+1]==b[i]){
                i++;
                sb[cb]++;
            }
            cb++;
        }
        if(ca!=cb){
            printf("NO\n");
            continue;
        }
        sort(sa,sa+ca);
        sort(sb,sb+cb);
        int i;
        for(i=0;i<ca;i++){
            if(sa[i]!=sb[i])break;
        }
        if(i<ca){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
    return 0;
}

