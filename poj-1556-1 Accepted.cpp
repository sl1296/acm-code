
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define eps 1e-8
#define inf 10e9
typedef struct point{
    double x,y;
}point;
point w[20][2][2],s,t;
int n,ide;
double g[200][200],dist[200];
bool visit[200];
double mult(point p1,point p2,point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
bool cross(point la,point lb,point x,point y){
    if(mult(la,x,lb)*mult(la,y,lb)>eps)return false;
    return true;
}
bool judge(int i,int j,point s,point t){
    for(;i<=j;i++)if(!cross(s,t,w[i][0][0],w[i][0][1]) && !cross(s,t,w[i][1][0],w[i][1][1]))return false;
    return true;
}
double dis(point x,point y){
    return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
double dikstra(){
    int i,j,cur;
    double temp;
    memset(visit,false,sizeof(visit));
    for(i=1;i<=ide;i++)dist[i]=inf;
    dist[0]=0;
    for(i=0;i<=ide;i++){
        temp=inf;
        cur=-1;
        for(j=0;j<=ide;j++){
            if(!visit[j] && dist[j]<temp){
                temp=dist[j];
                cur=j;
            }
        }
        visit[cur]=true;
        if(cur==ide)break;
        for(j=0;j<=ide;j++)if(!visit[j] && g[cur][j]>eps && dist[cur]+g[cur][j]+eps<dist[j])dist[j]=dist[cur]+g[cur][j];
    }
    return dist[ide];
}
int main(){
    int i,id,j,k,id2,l,p,q;
    s.y=t.y=5;
    s.x=0;
    t.x=10;
    while(1){
        scanf("%d",&n);
        if(n==-1)break;
        for(i=0;i<n;i++){
            scanf("%lf%lf%lf%lf%lf",&w[i][0][0].x,&w[i][0][0].y,&w[i][0][1].y,&w[i][1][0].y,&w[i][1][1].y);
            w[i][0][1].x=w[i][1][0].x=w[i][1][1].x=w[i][0][0].x;
        }
        if(judge(0,n-1,s,t)){
            printf("10.00\n");
            continue;
        }
        memset(g,0,sizeof(g));
        ide=4*n+1;
        for(i=0;i<n;i++){
            for(j=0;j<2;j++){
                for(k=0;k<2;k++){
                    id=i*4+j*2+k+1;
                    if(judge(0,i-1,s,w[i][j][k]))g[0][id]=dis(s,w[i][j][k]);
                    if(judge(i+1,n-1,w[i][j][k],t))g[id][ide]=dis(w[i][j][k],t);
                    for(l=i+1;l<n;l++){
                        for(p=0;p<2;p++){
                            for(q=0;q<2;q++){
                                id2=l*4+p*2+q+1;
                                if(judge(i+1,l-1,w[i][j][k],w[l][p][q]))g[id][id2]=dis(w[i][j][k],w[l][p][q]);
                            }
                        }
                    }
                }
            }
        }
        printf("%.2f\n",dikstra());
    }
    return 0;
}

