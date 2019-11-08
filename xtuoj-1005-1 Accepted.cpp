
#include <stdio.h>
#include <stdlib.h>
int r,c,sx,sy,ex,ey,isend,re;
typedef struct f{
    int x,y,step;
    struct f *p;
}f;
//f *mapfind[1010][1010];
char map[1010][1010];
int mapfinded[1010][1010];
int ttx[10]={-1,-1,0,1,1,1,0,-1},tty[10]={0,1,1,1,0,-1,-1,-1};
f *start,*end;
void add(int ax,int ay,int as/*,f *next*/){
//    printf("add %d %d %d\n",ax,ay,as);
    if(ax==ex && ay==ey){isend=0;re=as;return;}
    mapfinded[ax][ay]=1;
    end->p=(f*)malloc(sizeof(f));
    end=end->p;
    end->x=ax;
    end->y=ay;
    end->step=as;
/*    next->p=(f*)malloc(sizeof(f));
    next=next->p;
    next->x=ax;
    next->y=ay;
    next->p=NULL;*/
    if(!mapfinded[ax+ttx[map[ax][ay]-48]][ay+tty[map[ax][ay]-48]])
        add(ax+ttx[map[ax][ay]-48],ay+tty[map[ax][ay]-48],as/*,next*/);
}
void find(){
    f *e;
    int i,now=map[start->x][start->y]-48;
//    printf("find %d %d\n",start->x,start->y);
/*    if(maped[start->x][start->y]){
        e=mapfind[start->x][start->y]->p;
        while(e->p!=NULL){
            if(end->x==ex && end->y==ey){isend=0;re=start->step+1;return;}
            if(!mapfinded[e->x][e->y]){
            mapfinded[e->x][e->y]=1;
            end->p=(f*)malloc(sizeof(f));
            end=end->p;
            end->x=e->x;
            end->y=e->y;
            end->step=start->step+1;}
            e=e->p;
        }
        if(end->x==ex && end->y==ey){isend=0;re=start->step+1;return;}
        if(!mapfinded[e->x][e->y]){
        mapfinded[e->x][e->y]=1;
        end->p=(f*)malloc(sizeof(f));
        end=end->p;
        end->x=e->x;
        end->y=e->y;
        end->step=start->step+1;}
    }else{*/
    //    maped[start->x][start->y]=1;
    //    mapfind[start->x][start->y]=(f*)malloc(sizeof(f));
    //    mapfind[start->x][start->y]->p=NULL;
        for(i=0;i<8;i++)if(!mapfinded[start->x+ttx[i]][start->y+tty[i]]){
            add(start->x+ttx[i],start->y+tty[i],start->step+1/*,mapfind[start->x][start->y]*/);
            if(!isend)return;
        }
//    }
    e=start;
    start=start->p;
    free(e);
}
int main(){
    int i,j,k,n;
    f *e;
    scanf("%d%d",&r,&c);
    for(i=1;i<=r;i++)scanf("%s",&map[i][1]);
    for(i=0;i<r+2;i++)mapfinded[i][0]=mapfinded[i][c+1]=1;
    for(i=1;i<=c;i++)mapfinded[0][i]=mapfinded[r+1][i]=1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        isend=1;
        if(sx==ex && sy==ey){
            printf("0\n");
        }else{
            for(j=1;j<=r;j++)for(k=1;k<=c;k++)mapfinded[j][k]=0;
            start=(f*)malloc(sizeof(f));
            end=start;
            start->x=sx;
            start->y=sy;
            start->step=0;
            mapfinded[sx][sy]=1;
            if(!mapfinded[sx+ttx[map[sx][sy]-48]][sy+tty[map[sx][sy]-48]])
        add(sx+ttx[map[sx][sy]-48],sy+tty[map[sx][sy]-48],0);
            while(isend)find();
            while(start!=end){
                e=start;
                start=start->p;
                free(e);
            }
            free(start);
            printf("%d\n",re);
        }
    }
    return 0;
}

