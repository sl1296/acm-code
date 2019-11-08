
#include<bits/stdc++.h>
using namespace std;
int a[100010],s[100010][12];
int main(){
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d%s",&a[i],s[i]);
    }
    int p=0;
    for(int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        if(x^a[p])p+=y;else p-=y;
        p=(p%n+n)%n;
    }
    printf("%s\n",s[p]);
    return 0;
}

