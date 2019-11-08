
#include<cstdio>
#include<queue>
using namespace std;
int ys[1000010];
queue<int> num[1010];
queue<int> qu;
int main(){
    int n,cas=1;
    while(~scanf("%d",&n)){
        if(n==0)break;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            for(int j=0;j<x;j++){
                int tmp;
                scanf("%d",&tmp);
                ys[tmp]=i;
            }
        }
        printf("Scenario #%d\n",cas++);
        while(!qu.empty())qu.pop();
        for(int i=0;i<1010;i++)while(!num[i].empty())num[i].pop();
        while(1){
            char in[10];
            scanf("%s",in);
            if(in[0]=='S')break;
            if(in[0]=='D'){
                int xx=qu.front();
                printf("%d\n",num[xx].front());
                num[xx].pop();
                if(num[xx].empty())qu.pop();
            }else{
                int m;
                scanf("%d",&m);
                int a=ys[m];
                if(num[a].empty())qu.push(a);
                num[a].push(m);
            }
        }
        printf("\n");
    }
    return 0;
}

