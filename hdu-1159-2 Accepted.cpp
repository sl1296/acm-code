
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char a[100010],b[100010];
int c[2][100010];
int main(){
    while(~scanf("%s%s",a,b)){
        int la=strlen(a),lb=strlen(b);
        memset(c,0,sizeof(c));
        for(int i=1;i<=lb;i++){
            for(int j=1;j<=la;j++){
                if(b[i-1]==a[j-1])c[i%2][j]=max(max(c[(i-1)%2][j-1]+1,c[(i-1)%2][j]),c[i%2][j-1]);
                else c[i%2][j]=max(c[(i-1)%2][j],c[i%2][j-1]);
            }
        }
        printf("%d\n",c[lb%2][la]);
    }
    return 0;
}

