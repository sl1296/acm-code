
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000010];
int type[1000010],le[1000010],fdn;
int main(){
    int t,x,y;
    scanf("%d",&t);
    for(int z=1;z<=t;++z){
        scanf("%s%d%d",s,&x,&y);
        int len=strlen(s);
        fdn=0;
        int cyy=0,cfy=0,nyy=0,nfy=0;
        for(int i=0;i<len;++i){
            if(s[i]=='?'){
                s[i]=0;
                ++nyy;
                ++nfy;
            }else if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                s[i]=1;
                cfy=max(cfy,nfy);
                nfy=0;
                ++nyy;
            }else{
                s[i]=2;
                cyy=max(cyy,nyy);
                nyy=0;
                ++nfy;
            }
        }
        cyy=max(cyy,nyy);
        cfy=max(cfy,nfy);
//        for(int i=0;i<len;++i){
//            printf("%d ",s[i]);
//        }
//        printf("\n");
//        printf("cyy=%d cfy=%d\n",cyy,cfy);
        int yy=0,fy=0;
        for(int i=0;i<len;++i){
            le[fdn]=1;
            while(i+1<len && s[i+1]==s[i])++i,++le[fdn];
            if(s[i]==1)yy=max(yy,le[fdn]);
            else if(s[i]==2)fy=max(fy,le[fdn]);
            type[fdn++]=s[i];
        }
        if(yy>=x || fy>=y){
            printf("Case #%d: DISLIKE\n",z);
            continue;
        }
        if(fdn==1 && type[0]==0){
            if(x>1 && y>1)printf("Case #%d: SURPRISE\n",z);
            else printf("Case #%d: DISLIKE\n",z);
            continue;
        }
        for(int i=0;i<fdn;++i){
            if(type[i]==0){
                if(i==0||i==fdn-1)type[i]=-1;
                else if(type[i-1]==type[i+1])type[i]=-1;
                else if(le[i]>1)type[i]=-1;
            }
        }
        bool ok=true;
        int cyc=0,cfc=0;
        for(int i=0;i<fdn;++i){
            if(type[i]==1){
                cyc+=le[i];
                cfc=0;
                if(cyc>=x)ok=false;
            }else if(type[i]==2){
                cfc+=le[i];
                cyc=0;
                if(cfc>=y)ok=false;
            }else if(type[i]==-1){
                cyc=cfc=0;
            }else{
                if(type[i-1]==1){
                    if(cyc+1<x)cyc=cfc=0;
                    else cyc=0,cfc=1;
                }else{
                    if(cfc+1<x)cyc=cfc=0;
                    else cyc=1,cfc=0;
                }
            }
        }
        if(cyy<x && cfy<y && ok==true){
            printf("Case #%d: LIKE\n",z);
        }else if((cyy>=x || cfy>=y) && ok==false){
            printf("Case #%d: DISLIKE\n",z);
        }else{
            printf("Case #%d: SURPRISE\n",z);
        }
    }
    return 0;
}

