
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int lev[1024];
int main(){
	for(int i=7;i<1020;i++){
		int cnt=0;
		for(int j=0;j<13;j++)if(i&(1<<j))cnt++;
		if(cnt%3==0)lev[i]=lev[i-1]+1;else lev[i]=lev[i-1];
	}
	int n;
	while(~scanf("%d",&n)){
		printf("Day %d: Level = %d\n",n,lev[n]);
	}
	return 0;
}
/**********************************************************************
	Problem: 2069
	User: asdcvbn
	Language: C++
	Result: RE
**********************************************************************/



