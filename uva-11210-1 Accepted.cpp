
#include<bits/stdc++.h>
using namespace std;
int a[40];
map<string,int> ma;
map<int,string> am;
bool ffi;
void dfs(int x){
  //  printf("dfs:x=%d\n",x);
  //  for(int i=0;i<34;i++)printf("%d ",a[i]);printf("\n");
 //   getchar();
    if(x==0){
        for(int i=0;i<34;i++){
            if(a[i]>1){
                a[i]-=2;
                dfs(x+1);
                a[i]+=2;
                if(ffi)return;
            }
        }
    }else if(x<5){
        for(int i=0;i<34;i++){
            if(a[i]>2){
                a[i]-=3;
                dfs(x+1);
                a[i]+=3;
                if(ffi)return;
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<7;j++){
                int k=i*9+j;
                if(a[k] && a[k+1] && a[k+2]){
                    a[k]--;a[k+1]--;a[k+2]--;
                    dfs(x+1);
                    a[k]++;a[k+1]++;a[k+2]++;
                    if(ffi)return;
                }
            }
        }
    }else{
        ffi=true;
    }
}
int main(){
    char s[10]="1T";
    string xx=s;
    ma.clear();
    am.clear();
    for(int i=0;i<9;i++){
        ma[xx]=i;
        am[i]=xx;
        xx[0]++;
    }
    xx="1S";
    for(int i=9;i<18;i++){
        ma[xx]=i;
        am[i]=xx;
        xx[0]++;
    }
    xx="1W";
    for(int i=18;i<27;i++){
        ma[xx]=i;
        am[i]=xx;
        xx[0]++;
    }
    ma["DONG"]=27;ma["NAN"]=28;ma["XI"]=29;ma["BEI"]=30;ma["ZHONG"]=31;ma["FA"]=32;ma["BAI"]=33;
    am[27]="DONG";am[28]="NAN";am[29]="XI";am[30]="BEI";am[31]="ZHONG";am[32]="FA";am[33]="BAI";
    int cas=1;
    while(1){
        scanf("%s",s);
        memset(a,0,sizeof(a));
        if(strcmp(s,"0")==0)break;
        xx=s;
        a[ma[xx]]++;
        for(int i=1;i<13;i++){
            scanf("%s",s);
            xx=s;
            a[ma[xx]]++;
        }
        printf("Case %d:",cas);
        cas++;
        bool is=false;
     //   printf("\n");for(int i=0;i<34;i++)printf("%d ",a[i]);printf("\n");
        for(int i=0;i<34;i++){
            if(a[i]<4){
           //     printf("i=%d\n",i);
                a[i]++;
                ffi=false;
                dfs(0);
                if(ffi){
                    is=true;
                    xx=am[i];
                    xx.copy(s,xx.size(),0);
                    s[xx.size()]=0;
                    printf(" %s",s);
                }
                a[i]--;
            }
        }
        if(!is)printf(" Not ready");
        printf("\n");
    }
    return 0;
}

