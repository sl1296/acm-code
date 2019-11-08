
#include <stdio.h>
int main(){
	int z,n,i,j,v[110],x[110],min=0,ti;
	double t[110];
	char m[110][110];
	scanf("%d",&z);
	for(i=0;i<z;i++){
		min=0;
		t[0]=999999999;
		scanf("%d",&n);
		for(j=1;j<=n;j++){
			scanf("%s%d%d",m[j],&v[j],&x[j]);
			if(x[j]<200)continue;
			ti=x[j]/200;
			if(ti>5)ti=5;
			t[j]=v[j]/ti;
			if(t[j]<t[min])min=j;
			if(t[j]==t[min] && x[j]>x[min])min=j;
		}
		printf("%s\n",m[min]);		
	}
	return 0;
}

