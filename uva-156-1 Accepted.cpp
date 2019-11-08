
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
string a[1010];
char to[1010][1010];
int cnt;
map<string,int> ma;
int main(){
	while(1){
		scanf("%s",to[cnt]);
		if(strcmp(to[cnt],"#")==0)break;
		a[cnt]=to[cnt];
		cnt++;
	}
	sort(a,a+cnt);
	for(int i=0;i<cnt;i++){
		strcpy(to[i],a[i].c_str());
		int sz=a[i].size();
		for(int j=0;j<sz;j++){
			if(to[i][j]<'a')to[i][j]+=32;
		}
		sort(to[i],to[i]+sz);
		if(ma[to[i]]==0){
			ma[to[i]]=1;
		}else{
			ma[to[i]]++;
		}
	}
	for(int i=0;i<cnt;i++){
		if(ma[to[i]]==1)
		printf("%s\n",a[i].c_str());
	}
	return 0;
}

