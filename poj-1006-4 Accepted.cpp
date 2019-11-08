
#include <stdio.h>
int main(){
	int i,a,b,c,d,aa,bb,cc;
	for(i=1;;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a==-1 && b==-1 && c==-1 && d==-1)break;
		aa=a+23;
		bb=b+28;
		cc=c+33;
		do{
			for(;aa<bb;aa+=23);
			for(;bb<cc;bb+=28);
			for(;cc<aa;cc+=33);
		}while(aa!=bb || bb!=cc || cc!=aa);
		if(aa<d){aa=21252+aa;}else if(aa-d>21252){aa=aa-21252;}
		printf("Case %d: the next triple peak occurs in %d days.\n",i,aa-d);
	}
	return 0;
}

