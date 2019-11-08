
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
char nxt[5]="durl";
int tx[5]={-1,1,0,0};
int ty[5]={0,0,-1,1};
int qus,que;
stt qu[200010];
char ans[200010];
int main(){
   // system("chcp 936");
    node sss;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            sss.z[i][j]=(i==2&&j==2)?'x':49+i*3+j;
        }
    }
    char in[5];
    map<node,int> ma;
    ma[sss]=1;
    qu[1]=(stt){2,2,-1,0,sss};qus=1;que=2;
    while(qus<que){
        for(int i=0;i<4;i++){
            stt v=qu[qus];
            if(v.x+tx[i]<0||v.x+tx[i]>2||v.y+ty[i]<0||v.y+ty[i]>2)continue;
            swap(v.s.z[v.x][v.y],v.s.z[v.x+tx[i]][v.y+ty[i]]);v.x+=tx[i];v.y+=ty[i];
            if(ma[v.s])continue;
            ma[v.s]=que;
            v.now=nxt[i];v.pre=qus;
            qu[que++]=v;
        }
        qus++;
    }
    while(~scanf("%s",in)){
        node s;
        s.z[0][0]=in[0];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==0&&j==0)continue;
                scanf("%s",in);
                s.z[i][j]=in[0];
            }
        }
        int re=ma[s];
        int ac=0;
        if(re){
            while(qu[re].pre!=-1){
                ans[ac++]=qu[re].now;
                re=qu[re].pre;
            }
            for(int i=0;i<ac;i++){
                printf("%c",ans[i]);
            }
            printf("\n");
        }else{
            printf("unsolvable\n");
        }
    }
    return 0;
}

