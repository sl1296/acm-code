
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
inline void rcx(const int& id,const int& cs){
    rc(dm[id],n-cs+1);
}
inline void U(){rf(3);rc(3,1);}inline void Ux(){rfx(3);rcx(3,1);}
inline void D(){rf(6);rc(6,1);}inline void Dx(){rfx(6);rcx(6,1);}
inline void F(){rf(4);rc(4,1);}inline void Fx(){rfx(4);rcx(4,1);}
inline void B(){rf(2);rc(2,1);}inline void Bx(){rfx(2);rcx(2,1);}
inline void L(){rf(1);rc(1,1);}inline void Lx(){rfx(1);rcx(1,1);}
inline void R(){rf(5);rc(5,1);}inline void Rx(){rfx(5);rcx(5,1);}
char ss[10];
int pre[100];
int TO[100]={
0,
10,11,12,22,23,24,34,35,36,
1,2,3,4,5,6,7,8,9,
13,14,15,25,26,27,37,38,39,
46,47,48,49,50,51,52,53,54,
16,17,18,28,29,30,40,41,42,
19,20,21,31,32,33,43,44,45
};
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=1;i<=54;i++){
            scanf("%s",ss);
            pre[i]=ss[0];
        }
        for(int i=1;i<=54;i++){
            in[i]=pre[TO[i]];
        }
        init();
        int op;
        scanf("%d",&op);
        for(int i=0;i<op;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            switch(a){
                case 0:if(b==1)L();else Lx();break;
                case 1:if(b==1)U();else Ux();break;
                case 2:if(b==1)R();else Rx();break;
                case 3:if(b==1)D();else Dx();break;
                case 4:if(b==1)B();else Bx();break;
                case 5:if(b==1)F();else Fx();break;
            }
        }
        printf("Scenario #%d:\n",z);
        for(int i=1;i<=3;i++){
            for(int j=0;j<5;j++)printf(" ");
            for(int j=1;j<=3;j++){
                printf(" %c",mf[2][i][j]);
            }
            printf("\n");
        }
        int tt[4]={1,3,5,6};
        for(int i=1;i<=3;i++){
            int cc=0;
            for(int j=0;j<4;j++){
                for(int k=1;k<=n;k++){
                    if(cc)printf(" ");
                    cc++;
                    printf("%c",mf[tt[j]][i][k]);
                }
            }
            printf("\n");
        }
        for(int i=1;i<=3;i++){
            for(int j=0;j<5;j++)printf(" ");
            for(int j=1;j<=3;j++){
                printf(" %c",mf[4][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}


