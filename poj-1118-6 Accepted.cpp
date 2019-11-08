
#include<iostream>  
#include<cstring>  
#include<cstdio>  
  
struct Node  
{  
      int a,b;  
}p[1005];  
  
  
int main()  
{  
      int i,j,k,n;  
      int cnt,ans;  
  
      while(~scanf("%d",&n) && n)  
      {  
            for(i=0;i<n;i++)  
                  scanf("%d%d",&p[i].a,&p[i].b);  
  
            ans=0;  
            for(i=0;i<n;i++)  
                  for(j=i+1;j<n;j++)  
                  {  
                        cnt=2;  
                        for(k=j+1;k<n;k++)  
                              if( (p[k].b-p[i].b)*(p[j].a-p[i].a)== (p[j].b-p[i].b)*(p[k].a-p[i].a) )  // 避开斜率问题   
                                     cnt++;  
  
                        if(cnt>ans) ans=cnt;  
                  }  
  
            printf("%d\n",ans);  
      }  
  
  
      return 0;  
}  

