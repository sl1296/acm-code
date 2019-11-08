
#include <stdio.h>
int a[100][15],b[100][15];
int main(){
	int n,i,l,end,j,p1,p2,c,ls;
	while(
		scanf("%d",&n)
		!=EOF
		){
		end=l=c=i=j=end=p1=p2=0;
		for(i=0;i<100;i++)for(j=0;j<15;j++)a[i][j]=b[i][j]=0;
		scanf("%d",&a[0][1]);
	for(i=2;i<a[0][1]+2;i++)scanf("%d",&a[0][i]);
	scanf("%d",&b[0][1]);
	for(i=2;i<b[0][1]+2;i++)scanf("%d",&b[0][i]);
	a[0][0]=2;
	b[0][0]=2;
	a[0][1]++;
	b[0][1]++;
	//
	//	printf("%d %d\n",c,l);
	//	for(i=0;i<12;i++)printf("%d ",a[l][i]);printf("\n");
	//	for(i=0;i<12;i++)printf("%d ",b[l][i]);printf("\n");
//
	for(;(a[l][1]-a[l][0]!=-1 && b[l][1]-b[l][0]!=-1);){
	if(l<2){
		for(i=0;i<15;i++){
			a[l+1][i]=a[l][i];
			b[l+1][i]=b[l][i];
		}
		l++;
	}
	c++;
		p1=a[l][a[l][0]];
		p2=b[l][b[l][0]];
		a[l][0]++;
		b[l][0]++;
		if(a[l][0]>13)a[l][0]=2;
		if(b[l][0]>13)b[l][0]=2;
		if(p1>p2){
			a[l][1]++;
			if(a[l][0]>13)a[l][1]=2;
			a[l][a[l][1]]=p2;
			a[l][1]++;
			if(a[l][0]>13)a[l][1]=2;
			a[l][a[l][1]]=p1;
		}else{
			b[l][1]++;
			if(b[l][0]>13)b[l][1]=2;
			b[l][b[l][1]]=p1;
			b[l][1]++;
			if(b[l][0]>13)b[l][1]=2;
			b[l][b[l][1]]=p2;
		}
		//
	//	printf("%d %d\n",c,l);
	//	for(i=0;i<12;i++)printf("%d ",a[l][i]);printf("\n");
	//	for(i=0;i<12;i++)printf("%d ",b[l][i]);printf("\n");
	if((a[l][1]+13-a[l][0])%12==a[0][1]-1 && (b[l][1]+13-b[l][0])%12==b[0][1]-1){
		j=2;
		for(i=a[l][0];j<=a[0][1];i++){
			if(i>13)i=2;
			if(a[0][j]!=a[l][i])break;
		//	printf("cmp%d %d %d %d %d\n",a[0][j],a[l][i],i,j,l);
			j++;
		}
	//	printf("br%d-",j);
		if(j<=a[0][1])continue;
		j=2;
		for(i=b[l][0];j<=b[0][1];i++){
			if(i>13)i=2;
			if(b[0][j]!=b[l][i])break;
			j++;
		}
		if(j<=b[0][1])continue;
		end=1;
		break;
	}
//	getchar();
	//
	}
	if(end)printf("-1\n");
	else{printf("%d ",c);
	if(a[l][1]-a[l][0])printf("2\n");
	else printf("1\n");
	} 
	}
	return 0;
}

