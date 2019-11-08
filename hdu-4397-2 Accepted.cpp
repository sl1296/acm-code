
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
inline void rcx(const int& id,const int& cs){
    rc(dm[id],n-cs+1);
}
inline void U(){rf(3);rc(3,1);}inline void Ux(){rfx(3);rcx(3,1);}
inline void D(){rf(6);rc(6,1);}inline void Dx(){rfx(6);rcx(6,1);}
inline void F(){rf(4);rc(4,1);}inline void Fx(){rfx(4);rcx(4,1);}
inline void B(){rf(2);rc(2,1);}inline void Bx(){rfx(2);rcx(2,1);}
inline void L(){rf(1);rc(1,1);}inline void Lx(){rfx(1);rcx(1,1);}
inline void R(){rf(5);rc(5,1);}inline void Rx(){rfx(5);rcx(5,1);}
inline void M(){rc(5,2);}inline void Mx(){rcx(5,2);}
inline void E(){rc(3,2);}inline void Ex(){rcx(3,2);}
inline void S(){rc(4,2);}inline void Sx(){rcx(4,2);}
char ss[10010];
int CC[100];
int main(){
    int cas=0;
    for(int i=0;i<6;i++){
        for(int j=1;j<=9;j++){
            CC[i*9+j]=i;
        }
    }
    while(~scanf("%s",ss)){
        int len=strlen(ss);
        for(int i=1;i<=54;i++)in[i]=CC[i];
        init();
        for(int i=0;i<len;i++){
            switch(ss[i]){
                case 'U':U();break;
                case 'u':Ux();break;
                case 'F':F();break;
                case 'f':Fx();break;
                case 'D':D();break;
                case 'd':Dx();break;
                case 'B':B();break;
                case 'b':Bx();break;
                case 'L':L();break;
                case 'l':Lx();break;
                case 'R':R();break;
                case 'r':Rx();break;
                case 'X':E();break;
                case 'x':Ex();break;
                case 'Y':M();break;
                case 'y':Mx();break;
                case 'Z':Sx();break;
                case 'z':S();break;
            }
        }
        out();
        bool pd=true;
        for(int i=1;i<=54;i++){
            if(in[i]!=CC[i]){
                pd=false;
                break;
            }
        }
        if(cas)printf("\n");
        cas++;
        if(pd){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}

