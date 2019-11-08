
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
double money;
double per[100];
char in[1010];
struct peo{
    char name[21];
    int s[4];
    int tot,tot1;
    int cnt;
    int rnk;
    bool ist,ismoney;
    double money;
};
peo a[200];
bool cmp(peo a,peo b){
    if(a.cnt!=b.cnt)return a.cnt>b.cnt;
    return a.tot1<b.tot1;
}
bool cmp2(peo a,peo b){
    if(a.cnt!=b.cnt)return a.cnt>b.cnt;
    if(a.tot!=b.tot)return a.tot<b.tot;
    return strcmp(a.name,b.name)<0;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lf",&money);
        for(int i=0;i<70;i++){
            scanf("%lf",&per[i]);
            per[i]/=100;
        }
        int n;
        scanf("%d",&n);
        gets(in);
        for(int i=0;i<n;i++){
            gets(in);
            for(int j=0;j<20;j++)a[i].name[j]=in[j];
            a[i].name[20]=0;
            for(int j=19;a[i].name[j]==' ';j--)a[i].name[j]=0;
            a[i].cnt=0;
            a[i].tot=0;
            a[i].tot1=0;
            for(int j=0;j<4;j++){
                a[i].s[j]=0;
                int now=20+j*3;
                if((in[now]=='D'&&in[now+1]=='Q')||(in[now+1]=='D'&&in[now+2]=='Q')){
                    break;
                }
                for(int k=0;k<3;k++){
                    if(in[now+k]!=' '&&in[now+k]!=0){
                        a[i].s[j]=a[i].s[j]*10+in[now+k]-48;
                    }
                }
                a[i].cnt++;
                a[i].tot+=a[i].s[j];
                if(j<2)a[i].tot1+=a[i].s[j];
            }
        }
        sort(a,a+n,cmp);
        while(a[n-1].cnt<2)n--;
        if(n>70){
            int en=69;
            while(en+1<n&&a[en+1].tot1==a[en].tot1)en++;
            n=en+1;
        }
        sort(a,a+n,cmp2);
        int rrnnkk=1;
        int acrnk=0;
        for(int i=0;i<n;i++){
            if(a[i].cnt<4){
                a[i].rnk=-1;
                a[i].ist=false;
                a[i].ismoney=false;
            }else{
                int ss=i;
                int cnt=1;
                while(i+1<n&&a[i+1].tot==a[i].tot){
                    i++;
                    if(a[i].name[strlen(a[i].name)-1]!='*')cnt++;
                }
                double mm=0;
                bool pd=true;
                if(acrnk>=70)pd=false;
                for(int j=acrnk;j<min(acrnk+cnt,70);j++)mm+=per[j];
                mm=mm*money/cnt;
                if(cnt>1){
                    for(int j=ss;j<=i;j++){
                        if(a[j].name[strlen(a[j].name)-1]!='*')a[j].ist=true,a[j].money=mm,a[j].ismoney=true;
                        else a[j].ist=false,a[j].ismoney=false;
                        a[j].rnk=rrnnkk;
                        if(!pd)a[j].ismoney=false;
                    }
                }else{
                    for(int j=ss;j<=i;j++){
                        a[j].ist=false;
                        if(a[j].name[strlen(a[j].name)-1]!='*')a[j].ismoney=true,a[j].money=mm;
                        else a[j].ismoney=false;
                        if(!pd)a[j].ismoney=false;
                        a[j].rnk=rrnnkk;
                    }
                }
                rrnnkk+=(i-ss+1);
                acrnk+=cnt;
            }
        }
        printf("Player Name          Place     RDJ  RD2  RD3  RD4  TOTAL     Money Won\n");
        printf("-----------------------------------------------------------------------\n");
        for(int i=0;i<n;i++){
            printf("%-21s",a[i].name);
            int last=10;
            if(a[i].rnk!=-1){
                printf("%d",a[i].rnk);
                if(a[i].rnk<10)last--;else if(a[i].rnk<100)last-=2;else last-=3;
                if(a[i].ist){printf("T");last--;}
            }
            for(int j=0;j<last;j++)printf(" ");
            for(int j=0;j<a[i].cnt;j++)printf("%-5d",a[i].s[j]);
            for(int j=a[i].cnt;j<4;j++)printf("     ");
            if(a[i].cnt<4)printf("DQ        ");else printf("%-10d",a[i].tot);
            if(a[i].ismoney)printf("$%9.2f",a[i].money);
            printf("\n");
        }
    }
    return 0;
}
/*

1
1000000.00
18.0000
10.8000
6.8000
4.8000
4.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
1.0000
0.9000
0.5000
0.5000
0.5000
0.5000
0.5000
0.5000
0.5000
0.5000
0.5000
0.5000
0.5000
0.5000
0.5000
0.5000
0.5000
0.5000
0.5000
0.5000
0.5000
0.5000
0.2980
0.2020
0.2000
0.0000
11
WALLY WEDGE         70 70 70 70
HENRY HACKER        77 70 70 70
TOMMY TWO IRON      71 72 72 72
EDDIE EAGLE         71 71 DQ
BEN BIRDIE          70 74 72 72
NORMAN NIBLICK*     72 72 72 72
SID SHANKER*        90 99 62 61
LEE THREE WINES     99 99 99 99
JIMMY ABLE          69 73 80 DQ
JOHNY MELAVO        99 99 99 99
SANDY LIE           80 DQ
*/

