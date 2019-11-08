
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
using namespace std;
map<char,string> m1;
map<string,string> m2;
map<string,string>::iterator it;
int main(){
	char in[200],inn[200];
	while(1){
		scanf("%s",in);
		if(strcmp(in,"*")==0)break;
		scanf("%s",inn);
		string str(inn);
		m1[in[0]]=str;
	//	cout<<in[0]<<' '<<str<<endl;
	}
	while(1){
		scanf("%s",in);
		if(strcmp(in,"*")==0)break;
		string str=m1[in[0]],str2(in);
		for(int i=1;in[i]!=0;i++){
			str=str+m1[in[i]];
//		cout<<str2<<'   '<<str<<endl;
		}
		m2[str2]=str;
//		cout<<str2<<'   '<<str<<endl;
	}
	while(1){
		scanf("%s",in);
		if(strcmp(in,"*")==0)break;
		string str1(in),str2,ans;
		int dec=9999990;
		bool mul=false,find=false;
		for(it=m2.begin();it!=m2.end();it++){
			str2=it->second;
			if(str1==str2){
				if(find){
					if(it->first<ans)ans=it->first;
					mul=true;
				}else{
					dec=0;
					find=true;
					ans=it->first;
				}
			}else{
				if(dec){
					int len=min(it->second.size(),str1.size());
					int i;
					for(i=0;i<len;i++)if(it->second[i]!=str1[i])break;
					if(i>=len && dec>abs(it->second.size()-str1.size())){
						dec=abs(it->second.size()-str1.size());
						ans=it->first;
					}
				}
			}
		}
		cout<<ans;
		if(mul)cout<<'!';
		if(!find)cout<<'?';
		cout<<endl;
	}
	return 0;
}
/*
A .-
B -... C -.-. D -.. E .
F ..-. G --. H .... I ..
J .--- K -.- L .-.. M -- N -. O --- P .--. Q --.- R .-. S ... T -
U ..- V ...- W .-- X -..- Y -.-- Z --.. 0 ------ 1 .----- 2 ..--- 3 ...-- 4 ....- 5 ..... 6 -.... 7 --... 8 ---.. 9 ----.
*
AN
EARTHQUAKE
EAT GOD HATH IM
READY
TO
WHAT
WROTH
*
.--.....--      .....--....
--.----.. .--.-.----.. .--.....-- .--. ..-.-.-....--.-..-.--.-. ..-- .-...--..-.--
---- ..--
*
*/

