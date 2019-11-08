
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
struct node{
    char z[3][3];
    bool operator < (const node &p) const{
        for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(z[i][j]!=p.z[i][j])return z[i][j]<p.z[i][j];
        return false;
    }
};
struct stt{
    int x,y,pre;
    char now;
    node s;
};
char nxt[5]="udlr";
int tx[5]={-1,1,0,0};
int ty[5]={0,0,-1,1};
int sx,sy;
stt qu[1000010];
int qus,que;
char ans[100010];
int main(){
    system("chcp 936");
    node sss;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            sss.z[i][j]=(i==2&&j==2)?'x':49+i*3+j;
        }
    }
    char in[5];
    while(~scanf("%s",in)){
        node s;
        s.z[0][0]=in[0];
        if(in[0]=='x')sx=sy=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==0&&j==0)continue;
                scanf("%s",in);
                s.z[i][j]=in[0];
                if(in[0]=='x')sx=i,sy=j;
            }
        }
        map<node,int> ma;ma[sss]=2;ma[s]=1;
        qu[0]=(stt){sx,sy,-1,0,s};qus=0;que=1;
        int ansc=0;
        while(qus<que){
            for(int i=0;i<4;i++){
                stt v=qu[qus];
                if(v.x+tx[i]<0||v.x+tx[i]>2||v.y+ty[i]<0||v.y+ty[i]>2)continue;
                swap(v.s.z[v.x][v.y],v.s.z[v.x+tx[i]][v.y+ty[i]]);v.x+=tx[i];v.y+=ty[i];
                if(ma[v.s]==1)continue;
                v.now=nxt[i];v.pre=qus;
                qu[que++]=v;
                if(ma[v.s]==2){
                    int pp=que-1;
                    while(qu[pp].pre!=-1){
                        ans[ansc++]=qu[pp].now;
                        pp=qu[pp].pre;
                    }
                    goto ed;
                }
                ma[v.s]=1;
            }
            qus++;
        }
        ed:
        if(ansc){
            for(int i=ansc-1;i>=0;i--)printf("%c",ans[i]);
            printf("\n");
        }else{
            printf("unsolvable\n");
        }
    }
    return 0;
}

