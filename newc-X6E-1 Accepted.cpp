
#include<cstdio>
char s[1020][1020];
int xx[8]={1,-1,0,0,1,-1,-1,1};
int yy[8]={0,0,1,-1,1,-1,1,-1};
int main(){
    int n,m,now,x,y;
    scanf("%d%d",&n,&m);
    bool ans=false;
    int re,num;
    for(int i=1;i<=m;++i){
        if(i&1)now=1;else now=2;
        scanf("%d%d",&x,&y);
        if(!ans){
            x+=6;
            y+=6;
            s[x][y]=now;
            int cnt;
            for(int j=0;j<8;++j){
                if(j%2==0)cnt=1;
                int tx=x+xx[j],ty=y+yy[j];
                while(s[tx][ty]==now){
                    ++cnt;
                    tx+=xx[j];
                    ty+=yy[j];
                }
                if(j%2==1 && cnt>=5){
                    ans=true;
                    re=now;
                    num=i;
                    break;
                }
            }
        }
    }
    if(ans){
        if(re==1){
            printf("HtBest %d\n",num);
        }else{
            printf("WHZ %d\n",num);
        }
    }else{
        printf("UNK %d\n",m);
    }
}

