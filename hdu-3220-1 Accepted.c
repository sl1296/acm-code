
#include <stdio.h>
char z[9][5]={{0},{2,3,5},{1,4,6},{1,4,7},{2,3,8},{6,7,1},{5,8,2},{5,8,3},{6,7,4}};
int main(){
	int x[20];
	int l[9],ln,r[9],rn;
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		ln=rn=0;
		for(j=1;j<9;j++){
			scanf("%d",&x[j]);
			if(x[j]){
				l[ln]=j;
				ln++;
			}
		}
		for(;j<17;j++){
			scanf("%d",&x[j]);
			if(!x[j]){
				r[rn]=j-8;
				rn++;
			}
		}
		if(ln>3){
			printf("Case #%d: more\n",i);
		}else if(ln<1){
			printf("Case #%d: 0\n",i);
		}else if(ln==3){
			if(l[0]==r[0] && l[1]==r[1] && l[2]==r[2]){
				printf("Case #%d: 3\n",i);
			}else{
				printf("Case #%d: more\n",i);
			}
		}else if(ln==2){
			if(l[0]==r[0] && l[1]==r[1]){
				printf("Case #%d: 2\n",i);
			}else if(l[0]!=r[0] && l[1]!=r[1] && l[0]!=r[1] && l[1]!=r[0]){
				printf("Case #%d: more\n",i);
			}else if(l[0]==r[0]){
				if(z[l[1]][0]==r[1] || z[l[1]][1]==r[1] || z[l[1]][2]==r[1]){
					printf("Case #%d: 3\n",i);
				}else{
					printf("Case #%d: more\n",i);
				}
			}else if(l[1]==r[1]){
				if(z[l[0]][0]==r[0] || z[l[0]][1]==r[0] || z[l[0]][2]==r[0]){
					printf("Case #%d: 3\n",i);
				}else{
					printf("Case #%d: more\n",i);
				}
			}else if(l[0]==r[1]){
				if(z[l[1]][0]==r[0] || z[l[1]][1]==r[0] || z[l[1]][2]==r[0]){
					printf("Case #%d: 3\n",i);
				}else{
					printf("Case #%d: more\n",i);
				}
			}else{
				if(z[l[0]][0]==r[1] || z[l[0]][1]==r[1] || z[l[0]][2]==r[1]){
					printf("Case #%d: 3\n",i);
				}else{
					printf("Case #%d: more\n",i);
				}
			}
		}else{
			if(l[0]==r[0]){
				printf("Case #%d: 1\n",i);
			}else if(z[l[0]][0]==r[0] || z[l[0]][1]==r[0] || z[l[0]][2]==r[0]){
				printf("Case #%d: 2\n",i);
			}else if(l[0]+r[0]==9){
				printf("Case #%d: more\n",i);
			}else{
				printf("Case #%d: 3\n",i);
			}
		}
	}
	return 0;
}

