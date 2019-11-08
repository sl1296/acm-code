
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
char a[10010];
string x[10010];
int cnt;
map<string,int> ma;
int main(){
//	freopen("q.txt","r",stdin);
	while(~scanf("%s",a)){
		int len=strlen(a);
		for(int i=0;i<len;i++){
			while(i<len&&(a[i]<'A'||(a[i]>'Z'&&a[i]<'a')||a[i]>'z'))i++;
			string tmp;
			while((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z')){
				if(a[i]<'a')a[i]+=32;
				tmp=tmp+a[i];
				i++;
			}
			if(tmp.size()){
				if(ma[tmp]==0){
					ma[tmp]=1;
					x[cnt++]=tmp;
				}
			}
		}
	}
	sort(x,x+cnt);
	for(int i=0;i<cnt;i++){
		printf("%s\n",x[i].c_str());
	}
	return 0;
}

