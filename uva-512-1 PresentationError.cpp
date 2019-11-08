
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct no{
	int x,y;
};
vector<vector<no>> ve;
vector<no> vex;
no re[60][60];
int main(){
	int r,c;
	no tmp;
	int cas=0;
	while(scanf("%d%d",&r,&c),r+c){
		memset(re,0,sizeof(re));
		ve.clear();
		for(int i=0;i<r;i++){
			vex.clear();
			for(int j=0;j<c;j++){
				tmp.x=i+1;
				tmp.y=j+1;
				vex.push_back(tmp);
			}
			ve.push_back(vex);
		}
		/*
		for(int ii=0;ii<ve.size();ii++){
			for(int jj=0;jj<ve[0].size();jj++){
				printf("%d,%d ",ve[ii][jj].x,ve[ii][jj].y);
			}
			printf("\n");
		}*/
		int num;
		scanf("%d",&num);
		for(int i=0;i<num;i++){
			char ss[6];
			scanf("%s",ss);
			if(strcmp(ss,"EX")==0){
				int x1,x2,y1,y2;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				tmp=ve[x1-1][y1-1];
				ve[x1-1][y1-1]=ve[x2-1][y2-1];
				ve[x2-1][y2-1]=tmp;
			}else{
				int opn;
				int opd[20];
				scanf("%d",&opn);
				for(int j=0;j<opn;j++)scanf("%d",&opd[j]);
				sort(opd,opd+opn);
				if(strcmp(ss,"DR")==0){
					for(int j=opn-1;j>-1;j--){
						ve.erase(ve.begin()+opd[j]-1);
					}
				}else if(strcmp(ss,"DC")==0){
					for(int j=opn-1;j>-1;j--){
						for(int k=0;k<ve.size();k++){
							ve[k].erase(ve[k].begin()+opd[j]-1);
						}
					}
				}else if(strcmp(ss,"IR")==0){
					vex.clear();
					tmp.x=tmp.y=0;
					for(int j=0;j<ve[0].size();j++)vex.push_back(tmp);
					for(int j=opn-1;j>-1;j--)ve.insert(ve.begin()+opd[j]-1,vex);
				}else{
					tmp.x=tmp.y=0;
					for(int j=opn-1;j>-1;j--){
						for(int k=0;k<ve.size();k++)ve[k].insert(ve[k].begin()+opd[j]-1,tmp);
					}
				}
			}
	/*	for(int ii=0;ii<ve.size();ii++){
			for(int jj=0;jj<ve[0].size();jj++){
				printf("%d,%d ",ve[ii][jj].x,ve[ii][jj].y);
			}
			printf("\n");
		}*/
		}
		for(int i=0;i<ve.size();i++){
			for(int j=0;j<ve[0].size();j++){
				tmp.x=i+1;
				tmp.y=j+1;
				re[ve[i][j].x][ve[i][j].y]=tmp;
				//printf("%d,%d-%d,%d\n",ve[i][j].x,ve[i][j].y,i+1,j+1);
			}
		}
		if(cas)printf("\n");
		scanf("%d",&num);
		cas++;
		printf("Spreadsheet #%d\n",cas);
		for(int i=0;i<num;i++){
			scanf("%d%d",&tmp.x,&tmp.y);
			printf("Cell data in(%d,%d) ",tmp.x,tmp.y);
			tmp=re[tmp.x][tmp.y];
			if(tmp.x==0){
				printf("GONE\n");
			}else{
				printf("moved to (%d,%d)\n",tmp.x,tmp.y);
			}
		}
	}
	return 0;
}

