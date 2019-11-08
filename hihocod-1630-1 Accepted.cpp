
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int mp[20][50],pd[20][50];
int st[20]={12,11,10,9,0,1,2,3,4,3,2,1,0,9,10,11,12};
int en[20]={12,13,14,15,24,23,22,21,20,21,22,23,24,15,14,13,12};
int dx[6]={0,0,-1,-1,1,1};
int dy[6]={-2,2,-1,1,-1,1};
int tox[50],toy[50],toc;
int main(){
    pd[0][12]=1;
    pd[1][11]=pd[1][13]=1;
    pd[2][10]=pd[2][12]=pd[2][14]=1;
    pd[3][9]=pd[3][11]=pd[3][13]=pd[3][15]=1;
    pd[13][9]=pd[13][11]=pd[13][13]=pd[13][15]=2;
    pd[14][10]=pd[14][12]=pd[14][14]=2;
    pd[15][11]=pd[15][13]=2;
    pd[16][12]=2;
    pd[4][0]=pd[4][2]=pd[4][4]=pd[4][6]=6;
    pd[5][1]=pd[5][3]=pd[5][5]=6;
    pd[6][2]=pd[6][4]=6;
    pd[7][3]=6;
    pd[4][18]=pd[4][20]=pd[4][22]=pd[4][24]=4;
    pd[5][19]=pd[5][21]=pd[5][23]=4;
    pd[6][20]=pd[6][22]=4;
    pd[7][21]=4;
    pd[9][3]=3;
    pd[10][2]=pd[10][4]=3;
    pd[11][1]=pd[11][3]=pd[11][5]=3;
    pd[12][0]=pd[12][2]=pd[12][4]=pd[12][6]=3;
    pd[9][21]=5;
    pd[10][20]=pd[10][22]=5;
    pd[11][19]=pd[11][21]=pd[11][23]=5;
    pd[12][18]=pd[12][20]=pd[12][22]=pd[12][24]=5;
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<20;++i)for(int j=0;j<50;++j)mp[i][j]=pd[i][j];
//        for(int ii=0;ii<17;++ii){
//            for(int jj=0;jj<25;++jj){
//                printf("%d",mp[ii][jj]);
//            }
//            printf("\n");
//        }
        for(int i=0,id=1;i<n;++i,++id){
            if(id==7)id=1;
            int x,y,d;
            char in[10];
            scanf("%d%d%s",&x,&y,in);
            if(strcmp(in,"L")==0)d=0;
            else if(strcmp(in,"R")==0)d=1;
            else if(strcmp(in,"UL")==0)d=2;
            else if(strcmp(in,"UR")==0)d=3;
            else if(strcmp(in,"LL")==0)d=4;
            else if(strcmp(in,"LR")==0)d=5;
            --x;
            y=st[x]+2*y-2;
            if(mp[x][y]!=id)continue;
            int tx=x,ty=y,ch=-1,cc=0;
            toc=0;
            while(tx+dx[d]>=0 && tx+dx[d]<17 && st[tx+dx[d]]<=ty+dy[d] && en[tx+dx[d]]>=ty+dy[d] && (pd[tx+dx[d]][ty+dy[d]]==0 || (pd[tx+dx[d]][ty+dy[d]]+1)/2==(id+1)/2)){
                tx+=dx[d];
                ty+=dy[d];
                if(toc==0 && mp[tx][ty]==0)ch=toc;
                if(toc && cc && mp[tx][ty]==0){
                    bool pp=true;
                    for(int i=0;i<toc;++i){
                        if((mp[tox[i]][toy[i]]==0 && mp[tox[toc-i-1]][toy[toc-i-1]])||(mp[tox[i]][toy[i]] && mp[tox[toc-i-1]][toy[toc-i-1]]==0)){
                            pp=false;
                            break;
                        }
                    }
                    if(pp)ch=toc;
                }
                if(mp[tx][ty])++cc;
                tox[toc]=tx;toy[toc++]=ty;
            }
            if(ch!=-1){
                mp[x][y]=0;
                mp[tox[ch]][toy[ch]]=id;
            }
//            for(int ii=0;ii<17;++ii){
//                for(int jj=0;jj<25;++jj){
//                    printf("%d",mp[ii][jj]);
//                }
//                printf("\n");
//            }
        }
        for(int xx=1;xx<7;++xx){
            int ccc=0;
            for(int i=0;i<17;++i){
                for(int j=st[i];j<=en[i];++j){
                    if(mp[i][j]==xx){
                        if(ccc)printf(" ");
                        printf("%d %d",i+1,(j-st[i]+2)/2);
                        ++ccc;
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}

