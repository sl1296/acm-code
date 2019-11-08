
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;
ll x[110],y[110];
char s[110];
int a,b;
ll xx[5]={0,0,1,-1};
ll yy[5]={1,-1,0,0};
ll ax,ay;
map<char,ll> ma;
int main(){
  ma['U']=0;ma['D']=1;ma['L']=3;ma['R']=2;
  while(scanf("%d%d%s",&a,&b,s)!=EOF){
      int len=strlen(s);
      x[0]=y[0]=0;
      for(int i=0;i<len;i++){
        x[i+1]=x[i]+xx[ma[s[i]]];
        y[i+1]=y[i]+yy[ma[s[i]]];
      }
      ax=x[len];ay=y[len];
     // printf("%d %d\n",ax,ay);
      bool p=false;
      for(int i=0;i<len;i++){
        ll lx=a-x[i],ly=b-y[i];
        if(lx*ay==ly*ax){
	//  printf("%d %d %d %d %d %d\n",ax,ay,lx,ly,x[i],y[i]);
	  p=true;
	}
      }
      if(p)printf("Yes\n");else printf("No\n");
  }
  return 0;
}

