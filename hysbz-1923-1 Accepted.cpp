
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<bitset>
#include<cstring>
#define ll long long
#define inf 2000000000
using namespace std;
bitset<1005> a[2005];
int n,m,ans;
char s[1005];
void gauss(){
	int now=0,i,j,k;
	for(i=1;i<=n;i++){
		j=now+1;
		while((!a[j][i]) && j<=m)j++;
		if(j==m+1){
            ans=-1;
            return;
        }else ans=max(ans,j);
		now++;
		swap(a[j],a[now]);
		for(k=1;k<=m;k++)if(k!=now && a[k][i])a[k]^=a[now];
	}
}
int main(){
    int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
        scanf("%s%s",s,&s[n]);
        for(j=0;j<=n;j++)a[i][j+1]=s[j]-'0';
	}
	gauss();
	if(ans==-1)printf("Cannot Determine\n");
	else
	{
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)if(a[i][n+1])printf("?y7M#\n"); else printf("Earth\n");
	}
	return 0;
}

