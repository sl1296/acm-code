
/*
code.c:1:17: fatal error: cstdio: No such file or directory
 #include
                 ^
compilation terminated.
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char s[15][15];
int cx[120],cy[120],cc;
int main(){
	int x,y;
	int cas=0;
	while(1){
		scanf("%d",&x);
		if(x==0)break;
		cc=0;
		memset(s,0,sizeof(s));
		scanf("%d",&y);
		for(int i=1;i<=x;i++)scanf("%s",&s[i][1]);
		for(int i=1;i<=x;i++){
			for(int j=1;j<=y;j++){
				if((s[i][j-1]==0 || s[i][j-1]=='*' || s[i-1][j]==0 || s[i-1][j]=='*') && s[i][j]!='*'){
					cx[cc]=i;
					cy[cc]=j;
					cc++;
				}
			}
		}
		if(cas)printf("\n");
		printf("puzzle #%d:\nAcross\n",++cas);
		for(int i=0;i<cc;i++){
			if(s[cx[i]][cy[i]-1]==0 || s[cx[i]][cy[i]-1]=='*'){
				printf("%3d.",i+1);
				for(int j=0;(s[cx[i]][cy[i]+j]!=0 && s[cx[i]][cy[i]+j]!='*');j++){
					printf("%c",s[cx[i]][cy[i]+j]);
				}
				printf("\n");
			}
		}
		printf("Down\n");
		for(int i=0;i<cc;i++){
			if(s[cx[i]-1][cy[i]]==0 || s[cx[i]-1][cy[i]]=='*'){
				printf("%3d.",i+1);
				for(int j=0;(s[cx[i]+j][cy[i]]!=0 && s[cx[i]+j][cy[i]]!='*');j++){
					printf("%c",s[cx[i]+j][cy[i]]);
				}
				printf("\n");
			}
		}
		
	}
	return 0;
}
/*
2 2
AT
*O
6 7
AIM*DEN
*ME*ONE
UPON*TO
SO*ERIN
*SA*OR*
IES*DEA
0
*/

