
#include <stdio.h>
int a[1000000][15],b[1000000][15];
int main(){
	int n,i,l,end,j,p1,p2,c,tt,cc,xx,eenndd;
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
//		printf("%d %d\n",c,l);
//		for(i=0;i<15;i++)printf("%d ",a[l][i]);printf("\n");
//		for(i=0;i<15;i++)printf("%d ",b[l][i]);printf("\n");
//
	for(;(a[l][1]-a[l][0]!=-1 && b[l][1]-b[l][0]!=-1 && a[l][1]-a[l][0]!=11 && b[l][1]-b[l][0]!=11);){
///	if(l<2){
		for(i=0;i<15;i++){
			a[l+1][i]=a[l][i];
			b[l+1][i]=b[l][i];
		}
		l++;
///	}
	c++;
		p1=a[l][a[l][0]];
		p2=b[l][b[l][0]];
		a[l][0]++;
		b[l][0]++;
		if(a[l][0]>13)a[l][0]=2;
		if(b[l][0]>13)b[l][0]=2;
		if(p1>p2){
			a[l][1]++;
			if(a[l][1]>13)a[l][1]=2;
			a[l][a[l][1]]=p2;
			a[l][1]++;
			if(a[l][1]>13)a[l][1]=2;
			a[l][a[l][1]]=p1;
		}else{
			b[l][1]++;
			if(b[l][1]>13)b[l][1]=2;
			b[l][b[l][1]]=p1;
			b[l][1]++;
			if(b[l][1]>13)b[l][1]=2;
			b[l][b[l][1]]=p2;
		}
		//
//		printf("%d %d\n",c,l);
//		for(i=0;i<15;i++)printf("%d ",a[l][i]);printf("\n");
//		for(i=0;i<15;i++)printf("%d ",b[l][i]);printf("\n");
		//
		for(tt=0;tt<l;tt++){
			//
	if((a[l][1]+13-a[l][0])%12==(a[tt][1]+13-a[tt][0])%12 && (b[l][1]+13-b[l][0])%12==(b[tt][1]+13-b[tt][0])%12){
		j=a[tt][0];
		cc=(a[tt][1]+13-a[tt][0])%12;
		eenndd=0;
		for(i=a[l][0],xx=0;xx<cc;i++,xx++){
			if(i>13)i=2;
			if(a[tt][j]!=a[l][i]){eenndd=1;break;}
//			printf("cmp%d %d %d %d %d %d %d %d\n",a[tt][j],a[l][i],i,j,l,tt,xx,cc);
			j++;
			if(j>13)j=2;
		}
//		printf("br%d-%d %d\n",j,tt,xx);
		if(eenndd)continue;
		j=b[tt][0];
		cc=(b[tt][1]+13-b[tt][0])%12;
		eenndd=0;
		for(i=b[l][0],xx=0;xx<cc;i++,xx++){
			if(i>13)i=2;
			if(b[tt][j]!=b[l][i]){eenndd=1;break;}

//			printf("2cmp%d %d %d %d %d %d %d %d\n",b[tt][j],b[l][i],i,j,l,tt,xx,cc);
			j++;
			if(j>13)j=2;
		}

//		printf("2br%d-%d %d\n",j,tt,xx);
		if(eenndd)continue;
		end=1;
		break;
	}
	//
		}
		if(end)break;
		//
//	getchar();
	//
	}
	if(end)printf("-1\n");
	else{printf("%d ",c);
	if(a[l][1]-a[l][0]==-1 || a[l][1]-a[l][0]==11)printf("2\n");
	else printf("1\n");
	}
	}
	return 0;
}

