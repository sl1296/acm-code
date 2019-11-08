
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[110],d[110],x[110],ad[110];
bool us[110];
int an,dn;
char s[10];
int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++){
    int l;
    scanf("%s%d",s,&l);
    ad[i]=l;
    if(s[0]=='A'){a[an]=l;an++;}else{d[dn]=l;dn++;}
  }
  for(int i=0;i<m;i++){
    scanf("%d",&x[i]);
  }
  sort(a,a+an);sort(d,d+dn);sort(x,x+m);sort(ad,ad+n);
  //ans1
  int ans1=0,t=0,i;
  for(i=0;i<an;i++){
    while(x[t]<a[i]&&t<m)t++;
    if(t>=m)break;
    t++;
  }
  int ttt=0;
  t=i;
  for(i=m-1;ttt<t;i--,ttt++)ans1+=x[i];
  int start=i+1;
  for(i=0;i<t;i++)ans1-=a[i];
  int tmp=ans1;
  for(i=t-1;i>-1;i--){
    tmp=tmp-x[start]+a[i];
    start++;
    if(tmp>ans1)ans1=tmp;
  }
  //ans2
  int ans2=0,po=0;
  for(i=0;i<dn;i++){
    while(x[po]<=d[i]&&po<m)po++;
    if(po>=m)break;
    us[po]=true;
    po++;
  }
  if(i>=dn&&m>=n){
    po=0;
    int j;
    for(j=0;j<an;j++){
      while((us[po]||x[po]<a[j])&&po<m)po++;
      if(po>=m)break;
      po++;
    }
    if(j>=an){
      for(int k=0;k<m;k++)if(us[k]==false)ans2+=x[k];
      for(int k=0;k<an;k++)ans2-=a[k];
    }else{
      ans2=0;
    }
   // printf("%d %d\n",ans1,ans2);
    if(ans2>ans1)ans1=ans2;
    printf("%d\n",ans1);
  }
  return 0;
}

