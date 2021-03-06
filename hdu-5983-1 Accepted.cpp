
#include<cstdio>
#include<algorithm>
#define n 2
using namespace std;
int in[610];
int mf[7][10][10];
int tmp[10][10];
int toid[610]={2,4,1,3,21,22,23,24,6,8,5,7,20,19,18,17,10,12,9,11,14,16,13,15};
void init(){
    int cc=0;
    for(int i=1;i<7;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                mf[i][j][k]=in[toid[cc]];
                cc++;
            }
        }
    }
}
bool check(){
    for(int i=1;i<=6;i++){
        int now=mf[i][1][1];
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(mf[i][j][k]!=now)return false;
            }
        }
    }
    return true;
}
int dm[7]={0,5,4,6,2,1,3};
int cm[7][4]={{},{2,3,4,6},{6,5,3,1},{2,5,4,1},{3,5,6,1},{2,6,4,3},{2,1,4,5}};
int da[7][4]={{},{1,1,1,n},{1,1,1,1},{n,1,1,n},{n,n,n,n},{n,1,n,n},{1,1,n,n}};
int db[7][4]={{},{n,n,n,1},{1,1,1,1},{n,n,1,1},{n,n,n,n},{1,n,1,1},{1,n,n,1}};
int dc[7][4]={{},{1,1,1,n},{n,n,n,n},{1,1,n,n},{1,1,1,1},{n,1,n,n},{n,1,1,n}};
int dd[7][4]={{},{1,1,1,n},{1,1,1,1},{n,1,1,n},{n,n,n,n},{n,1,n,n},{1,1,n,n}};
//面旋转顺时针
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
//面旋转逆时针
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
//侧面旋转顺时针
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
//侧面旋转逆时针
inline void rcx(const int& id,const int& cs){rc(dm[id],n-cs+1);}
//基础公式
inline void U(){rf(3);rc(3,1);}inline void Ux(){rfx(3);rcx(3,1);}
inline void D(){rf(6);rc(6,1);}inline void Dx(){rfx(6);rcx(6,1);}
inline void F(){rf(4);rc(4,1);}inline void Fx(){rfx(4);rcx(4,1);}
inline void B(){rf(2);rc(2,1);}inline void Bx(){rfx(2);rcx(2,1);}
inline void L(){rf(1);rc(1,1);}inline void Lx(){rfx(1);rcx(1,1);}
inline void R(){rf(5);rc(5,1);}inline void Rx(){rfx(5);rcx(5,1);}
//旋转
inline void X(){rf(5);for(int i=1;i<=n;i++)rc(5,i);rfx(1);}
inline void Xx(){rfx(5);for(int i=1;i<=n;i++)rcx(5,i);rf(1);}
inline void Y(){rf(3);for(int i=1;i<=n;i++)rc(3,i);rfx(6);}
inline void Yx(){rfx(3);for(int i=1;i<=n;i++)rcx(3,i);rf(6);}
inline void Z(){rf(4);for(int i=1;i<=n;i++)rc(4,i);rfx(2);}
inline void Zx(){rfx(4);for(int i=1;i<=n;i++)rcx(4,i);rf(2);}
//三阶公式
inline void M(){rc(5,2);}inline void Mx(){rcx(5,2);}
inline void E(){rc(3,2);}inline void Ex(){rcx(3,2);}
inline void S(){rc(4,2);}inline void Sx(){rcx(4,2);}

/*
 2     12   123 369 741
1356   34   456 258 852
 4          789 147 963
*/
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=1;i<25;i++)scanf("%d",&in[i]);
        init();
        bool ans=false;
        if(check())ans=true;
        F();if(check())ans=true;Fx();
        U();if(check())ans=true;Ux();
        D();if(check())ans=true;Dx();
        B();if(check())ans=true;Bx();
        L();if(check())ans=true;Lx();
        R();if(check())ans=true;Rx();
        Fx();if(check())ans=true;F();
        Ux();if(check())ans=true;U();
        Dx();if(check())ans=true;D();
        Bx();if(check())ans=true;B();
        Lx();if(check())ans=true;L();
        Rx();if(check())ans=true;R();
        if(ans){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}

