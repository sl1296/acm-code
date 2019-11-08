
#include<cstdio>
#include<cstring>
#include<algorithm>
#define n 3
using namespace std;
int in[610];
int mf[7][10][10];
int tmp[10][10];
inline void init(){
    int cc=1;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                mf[i][j][k]=in[cc++];
            }
        }
    }
}
inline void out(){
    int cc=1;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                in[cc++]=mf[i][j][k];
            }
        }
    }
}
int dm[7]={0,5,4,6,2,1,3};
int cm[7][4]={{},{2,3,4,6},{6,5,3,1},{2,5,4,1},{3,5,6,1},{2,6,4,3},{2,1,4,5}};
int da[7][4]={{},{1,1,1,n},{1,1,1,1},{n,1,1,n},{n,n,n,n},{n,1,n,n},{1,1,n,n}};
int db[7][4]={{},{n,n,n,1},{1,1,1,1},{n,n,1,1},{n,n,n,n},{1,n,1,1},{1,n,n,1}};
int dc[7][4]={{},{1,1,1,n},{n,n,n,n},{1,1,n,n},{1,1,1,1},{n,1,n,n},{n,1,1,n}};
int dd[7][4]={{},{1,1,1,n},{1,1,1,1},{n,1,1,n},{n,n,n,n},{n,1,n,n},{1,1,n,n}};
inline void rf(const int& id){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            tmp[i][j]=mf[id][i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mf[id][i][j]=tmp[n-j+1][i];
        }
    }
}
inline void rfx(const int& id){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            tmp[i][j]=mf[id][i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mf[id][i][j]=tmp[j][n-i+1];
        }
    }
}
inline void rc(const int& id,const int& cs){
    for(int i=0;i<4;i++){
        int now=cm[id][i],sx=da[id][i],ex=db[id][i],sy=dc[id][i],ey=dd[id][i];
        int ai=(sx<=ex)?1:-1,aj=(sy<=ey)?1:-1;
        if(sx==ex){
            int add=(sx==1)?cs-1:1-cs;
            sx+=add;ex+=add;
        }else{
            int add=(sy==1)?cs-1:1-cs;
            sy+=add;ey+=add;
        }
        int cc=0;
        for(int j=sx;;j+=ai){
            for(int k=sy;;k+=aj){
                tmp[i][cc++]=mf[now][j][k];
                if(k==ey)break;
            }
            if(j==ex)break;
        }
    }
    int fr=3;
    for(int i=0;i<4;i++){
        int now=cm[id][i],sx=da[id][i],ex=db[id][i],sy=dc[id][i],ey=dd[id][i];
        int ai=(sx<=ex)?1:-1,aj=(sy<=ey)?1:-1;
        if(sx==ex){
            int add=(sx==1)?cs-1:1-cs;
            sx+=add;ex+=add;
        }else{
            int add=(sy==1)?cs-1:1-cs;
            sy+=add;ey+=add;
        }
        int cc=0;
        for(int j=sx;;j+=ai){
            for(int k=sy;;k+=aj){
                mf[now][j][k]=tmp[fr][cc++];
                if(k==ey)break;
            }
            if(j==ex)break;
        }
        fr++;
        if(fr==4)fr=0;
    }
}
inline void rcx(const int& id,const int& cs){rc(dm[id],n-cs+1);}
inline void U(){rf(3);rc(3,1);}
inline void D(){rf(6);rc(6,1);}
inline void F(){rf(4);rc(4,1);}
inline void B(){rf(2);rc(2,1);}
inline void L(){rf(1);rc(1,1);}
inline void R(){rf(5);rc(5,1);}
int TO[100]={
0,
6,24,42,5,23,41,4,22,40,
52,34,16,53,35,17,54,36,18,
9,27,45,8,26,44,7,25,43,
39,38,37,21,20,19,3,2,1,
12,30,48,11,29,47,10,28,46,
15,33,51,14,32,50,13,31,49
};
int pre[100];
char ss[10010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=1;i<=54;i++){
            scanf("%s",ss);
            pre[i]=ss[0];
        }
        for(int i=1;i<=54;i++){
            in[i]=pre[TO[i]];
        }
        init();
        scanf("%s",ss);
        int len=strlen(ss);
        for(int i=0;i<len;i++){
            switch(ss[i]){
                case 'W':F();break;
                case 'O':L();break;
                case 'R':U();break;
                case 'B':R();break;
                case 'G':D();break;
                case 'Y':B();break;
            }
        }
        out();
        for(int i=1;i<=54;i++){
            pre[TO[i]]=in[i];
        }
        for(int i=1;i<=54;i++){
            printf("%c%c",pre[i],i%18?' ':'\n');
        }
        printf("===================================\n");
    }
    return 0;
}

