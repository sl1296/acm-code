
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
struct no{
    char sid[15];
    int cid;
    char name[15];
    int score[5];
    int tot;
    double avg;
    int rrank;
};
vector<no> ve;
void Add(){
    no tmp;
    while(1){
        printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
        scanf("%s",tmp.sid);
        if(strcmp(tmp.sid,"0")==0)break;
        scanf("%d%s%d%d%d%d",&tmp.cid,tmp.name,&tmp.score[0],&tmp.score[1],&tmp.score[2],&tmp.score[3]);
        tmp.tot=tmp.score[0]+tmp.score[1]+tmp.score[2]+tmp.score[3];
        tmp.avg=tmp.tot/4.0;
        tmp.rrank=1;
        int i;
        for(i=0;i<ve.size();i++){
            if(strcmp(tmp.sid,ve[i].sid)==0)break;
            if(ve[i].tot>tmp.tot)tmp.rrank++;
        }
        if(i<ve.size())printf("Duplicated SID.\n");
        else ve.push_back(tmp);
    }
}
void Remove(){
    while(1){
        printf("Please enter SID or name. Enter 0 to finish.\n");
        char ss[100];
        scanf("%s",ss);
        if(strcmp(ss,"0")==0)break;
        int c=0;
        for(int i=0;i<ve.size();i++){
            if(strcmp(ve[i].sid,ss)==0 || strcmp(ve[i].name,ss)==0){
                c++;
                for(int j=0;j<ve.size();j++){
                    if(j==i)continue;
                    if(ve[j].tot<ve[i].tot)ve[j].tot--;
                }
                ve.erase(ve.begin()+i);
                i--;
            }
        }
        printf("%d student(s) removed.\n",c);
    }
}
void Query(){
    while(1){
        printf("Please enter SID or name. Enter 0 to finish.\n");
        char ss[100];
        scanf("%s",ss);
        if(strcmp(ss,"0")==0)break;

        for(int i=0;i<ve.size();i++){
            if(strcmp(ss,ve[i].name)==0 || strcmp(ss,ve[i].sid)==0){
                printf("%d %s %d %s %d %d %d %d %d %.2f\n",ve[i].rrank,ve[i].sid,ve[i].cid,ve[i].name,ve[i].score[0],ve[i].score[1],ve[i].score[2],ve[i].score[3],ve[i].tot,ve[i].avg+1e-5);
            }
        }
    }
}
void Showstat(){
    printf("Please enter class ID, 0 for the whole statistics.\n");
    int in;
    scanf("%d",&in);
    int total[6]={0},pass[6]={0},fail[6]={0},ccc[6]={0};
    for(int i=0;i<ve.size();i++){
    	if((in!=0 && ve[i].cid==in) || in==0){
    		int cou=0;
    		for(int j=0;j<4;j++){
    			total[j]+=ve[i].score[j];
    			if(ve[i].score[j]<60){
    				fail[j]++;
    				cou++;
    			}
    			else pass[j]++;
    		}
    		for(int j=cou+1;j<4;j++)ccc[j]++;
    		ccc[cou]++;
    	}
    }
    printf("Chinese\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\n",total[0]/(double)(pass[0]+fail[0])+1e-5,pass[0],fail[0]);
    printf("Mathematics\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\n",total[1]/(double)(pass[1]+fail[1])+1e-5,pass[1],fail[1]);
    printf("English\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\n",total[2]/(double)(pass[2]+fail[2])+1e-5,pass[2],fail[2]);
    printf("Programming\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\n",total[3]/(double)(pass[3]+fail[3])+1e-5,pass[3],fail[3]);
    printf("Overall:\nNumber of students who passed all subjects: %d\nNumber of students who passed 3 or more subjects: %d\nNumber of students who passed 2 or more subjects: %d\nNumber of students who passed 1 or more subjects: %d\nNumber of students who failed all subjects: %d\n\n",ccc[0],ccc[1],ccc[2],ccc[3],ccc[4]);
}
int main(){
    bool exi=true;
    ve.clear();
    while(exi){
        printf("Welcome to Student Performance Management System (SPMS).\n\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n\n");
        int in;
        scanf("%d",&in);
        switch(in){
            case 1:Add();break;
            case 2:Remove();break;
            case 3:Query();break;
            case 4:printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");break;
            case 5:Showstat();break;
            case 0:exi=false;
        }
    }
    return 0;
}

