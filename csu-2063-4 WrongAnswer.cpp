
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll a[6]={1,2,3,3,4,10};
ll b[7]={1,2,2,2,3,5,11};
int main(){
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--){
		ll an=0,bn=0,tmp;
		for(int i=0;i<6;i++){
			scanf("%lld",&tmp);
			an+=tmp*a[i];
		}
		for(int i=0;i<7;i++){
			scanf("%lld",&tmp);
			bn+=tmp*b[i];
		}
		printf("Battle %d: ",cas++);
		if(an>bn){
			printf("Good triumphs over Evil.");
		}else if(an<bn){
			printf("Evil eradicates all trace of Good.");
		}else{
			printf("No victor on this battle field.");
		}
		printf("\n");
	}
	return 0;
}
/**********************************************************************
	Problem: 2063
	User: asdcvbn
	Language: C++
	Result: WA
**********************************************************************/



