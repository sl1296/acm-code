
#include<cstdio>
#include<set>
using namespace std;
int a[20010];
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;++z){
        int n,m,pos=0,now=0,pre=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;++i){
            scanf("%d",&a[i]);
            if(a[i]<3)a[i]+=13;
        }
        multiset<int> x[210];
        for(int i=0;i<n;++i){
            for(int j=0;j<5;++j){
                x[i].insert(a[pos]);
                ++pos;
            }
        }
        int win=-1;
        while(1){
            int p=*x[now].begin();
            x[now].erase(x[now].begin());
            pre=now;
            if(x[now].size()==0){
                win=now;
                goto en;
            }
            while(1){
                ++now;
                if(now==n)now=0;
                bool out=true;
                if(p!=15){
                    if(x[now].count(p+1)==0){
                        if(x[now].count(15)!=0){
                            p=15;
                            x[now].erase(x[now].find(15));
                            pre=now;
                            if(x[now].size()==0){
                                win=now;
                                goto en;
                            }
                        }else{
                            out=false;
                        }
                    }else{
                        x[now].erase(x[now].find(p+1));
                        ++p;
                        pre=now;
                        if(x[now].size()==0){
                            win=now;
                            goto en;
                        }
                    }
                }else{
                    out=false;
                }
                if(out==false && pre==now){
                    for(int i=now,j=0;j<n;++i,++j){
                        if(i==n)i=0;
                        if(pos==m)break;
                        x[now].insert(a[pos]);
                        ++pos;
                    }
                    break;
                }
            }
        }
        en:
        printf("Case #%d:\n",z);
        for(int i=0;i<n;++i){
            if(win==i){
                printf("Winner\n");
            }else{
                int sum=0;
                for(multiset<int>::iterator j=x[i].begin();j!=x[i].end();++j){
                    sum+=*j;
                    if(*j>13)sum-=13;
                }
                printf("%d\n",sum);
            }
        }
    }
    return 0;
}

