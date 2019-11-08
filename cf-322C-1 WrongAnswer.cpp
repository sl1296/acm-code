
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
int x[110],y[110];
char s[110];
int a,b;
int xx[5]={0,0,1,-1};
int yy[5]={1,-1,0,0};
int ax,ay;
map<char,int> ma;
int main(){
  int r,g,b,t;
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
        int lx=a-x[i],ly=b-y[i];
        if(((ax==0 && lx==0) || (ax!=0 && lx%ax==0)) && ((ay==0 && ly==0) || (ay!=0 && ly%ay==0)) && (ax==0 || ay==0 || (ax!=0 && ay!=0 && lx/ax==ly/ay))){
	//  printf("%d %d %d %d %d %d\n",ax,ay,lx,ly,x[i],y[i]);
	  p=true;
	}
      }
      if(p)printf("Yes\n");else printf("No\n");
  }
  return 0;
}

