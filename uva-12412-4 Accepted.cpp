
#include<bits/stdc++.h>
using namespace std;
struct po{
    char sid[20];
    int cid;
    char name[20];
    int x[4];
    int tot;
    double avg;
};
vector<po> st;
int main(){
   // freopen("in.txt","r",stdin);
    int c,i;
    bool exit=true;
    st.clear();
    while(exit){
        printf("Welcome to Student Performance Management System (SPMS).\n\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n\n");
        scanf("%d",&c);
        switch(c){
            case 1:
                while(1){
                    po tmp;
                    printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
                    scanf("%s",tmp.sid);
                    if(strcmp(tmp.sid,"0")==0)break;
                    for(i=0;i<st.size();i++)if(strcmp(tmp.sid,st[i].sid)==0)break;
                    if(i<st.size()){
                        printf("Duplicated SID.\n");
                        scanf("%s%s%s%s%s%s",tmp.sid,tmp.sid,tmp.sid,tmp.sid,tmp.sid,tmp.sid);
                    }else{
                        scanf("%d%s",&tmp.cid,tmp.name);
                        tmp.tot=0;
                        for(int j=0;j<4;j++){
                            scanf("%d",&tmp.x[j]);
                            tmp.tot+=tmp.x[j];
                        }
                        tmp.avg=tmp.tot/4.0+1e-5;
                        st.push_back(tmp);
                    }
                }
                break;
            case 2:
                while(1){
                    char tmp[500];
                    printf("Please enter SID or name. Enter 0 to finish.\n");
                    scanf("%s",tmp);
                    if(strcmp(tmp,"0")==0)break;
                    i=0;
                    for(int j=st.size()-1;j>-1;j--){
                        if(strcmp(st[j].sid,tmp)==0 || strcmp(st[j].name,tmp)==0){
                            i++;
                            st.erase(st.begin()+j);
                        }
                    }
                    printf("%d student(s) removed.\n",i);
                }
                break;
            case 3:
                while(1){
                    char tmp[500];
                    printf("Please enter SID or name. Enter 0 to finish.\n");
                    scanf("%s",tmp);
                    if(strcmp(tmp,"0")==0)break;
                    for(int j=0;j<st.size();j++){
                        if(strcmp(tmp,st[j].name)==0 || strcmp(tmp,st[j].sid)==0){
                            int rak=1;
                            for(int k=0;k<st.size();k++){
                                if(st[k].tot>st[j].tot)rak++;
                            }
                            printf("%d %s %d %s ",rak,st[j].sid,st[j].cid,st[j].name);
                            for(int k=0;k<4;k++)printf("%d ",st[j].x[k]);
                            printf("%d %.2f\n",st[j].tot,st[j].avg);
                        }
                    }
                }
                break;
            case 4:
                printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
                break;
            case 5:
                {
                    printf("Please enter class ID, 0 for the whole statistics.\n");
                    int id,cc=0;
                    scanf("%d",&id);
                    double avg[4]={0};
                    int pass[4]={0},fail[4]={0},pac[5]={0};
                    for(int j=0;j<st.size();j++){
                        if(id==st[j].cid || id==0){
                            cc++;
                            int xb=0;
                            for(int k=0;k<4;k++){
                                avg[k]+=st[j].x[k];
                                if(st[j].x[k]>=60){
                                    pass[k]++;
                                    xb++;
                                }
                                else{
                                    fail[k]++;
                                }
                            }
                            for(int k=xb;k>0;k--)pac[k]++;
                            if(xb==0)pac[0]++;
                        }
                    }
                    for(int j=0;j<4;j++)avg[j]=avg[j]/cc+1e-5;
                    printf("Chinese\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\n",avg[0],pass[0],fail[0]);
                    printf("Mathematics\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\n",avg[1],pass[1],fail[1]);
                    printf("English\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\n",avg[2],pass[2],fail[2]);
                    printf("Programming\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\n",avg[3],pass[3],fail[3]);
                    printf("Overall:\nNumber of students who passed all subjects: %d\nNumber of students who passed 3 or more subjects: %d\nNumber of students who passed 2 or more subjects: %d\nNumber of students who passed 1 or more subjects: %d\nNumber of students who failed all subjects: %d\n\n",pac[4],pac[3],pac[2],pac[1],pac[0]);
                }
                break;
            case 0:
                exit=false;
        }
    }
    return 0;
}

