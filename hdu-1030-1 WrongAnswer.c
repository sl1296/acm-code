
#include <stdio.h>
int main(){
int m,n,i,s=0;
scanf("%d%d",&m,&n);
n-=m;
for(i=1;s<n;i+=2)s+=i;
i--;
i/=2;
printf("%d\n",i);
}

