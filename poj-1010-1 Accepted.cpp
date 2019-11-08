
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct node{
    char id[4],cnt,dif;
    int sum;
    bool operator < (const node &p) const{
        if(sum!=p.sum)return sum<p.sum;
        if(dif!=p.dif)return dif>p.dif;
        if(cnt!=p.cnt)return cnt<p.cnt;
        return id[0]>p.id[0];
    }
    void out(){
        printf("[");
        for(int i=0;i<4;i++)printf("%d ",id[i]);
        printf("] sum=%d cnt=%d dif=%d\n",sum,cnt,dif);
    }
};
node ans[700010];
int ansc;
int *a;
bool *use;
bool cmp(char x,char y){
    return a[x]>a[y];
}
int main(){
    a=(int*)malloc(400);
    use=(bool*)malloc(100);
    while(~scanf("%d",&a[1])){
        int n=2;
        int mx=1;
        while(1){
            scanf("%d",&a[n]);
            if(!a[n])break;
            if(a[n]>a[mx])mx=n;
            n++;
        }
        if(n>100)while(1);
        n--;
        ansc=0;
        for(int i=n;i>0;i--){
            for(int j=i;j>=0;j--){
                for(int k=j;k>=0;k--){
                    for(int l=k;l>=0;l--){
                        ans[ansc].id[0]=i;
                        ans[ansc].id[1]=j;
                        ans[ansc].id[2]=k;
                        ans[ansc].id[3]=l;
                        ans[ansc].sum=0;
                        ans[ansc].dif=0;
                        sort(ans[ansc].id,ans[ansc].id+4,cmp);
                        for(int ii=0;ii<4;ii++){
                            if(ans[ansc].id[ii]){
                                ans[ansc].cnt=ii+1;
                                ans[ansc].sum+=a[ans[ansc].id[ii]];
                                if(!use[ans[ansc].id[ii]]){
                                    use[ans[ansc].id[ii]]=true;
                                    ans[ansc].dif++;
                                }
                            }
                        }
                        use[i]=use[j]=use[k]=use[l]=false;
                        ansc++;
//                        if(ansc>400000)while(1);
                    }
                }
            }
        }
        sort(ans,ans+ansc);
//        for(int i=0;i<ansc;i++){printf("%d: ",i);ans[i].out();}
        while(1){
            int x;
            scanf("%d",&x);
            if(!x)break;
            int fin=lower_bound(ans,ans+ansc,(node){{mx,0,0,0},0,9,x})-ans;
//            printf("fin=%d\n",fin);
            printf("%d ",x);
            if(fin==ansc||(fin<ansc&&ans[fin].sum!=x)){
                printf("---- none\n");
            }else{
                printf("(%d):",ans[fin].dif);
                if(fin==ansc-1||(fin<ansc-1&&ans[fin]<ans[fin+1])){
                    int out[4];
                    for(int i=0;ans[fin].id[i];i++)out[i]=a[ans[fin].id[i]];
                    sort(out,out+ans[fin].cnt);
                    for(int i=0;i<ans[fin].cnt;i++){
                        printf(" %d",out[i]);
                    }
                    printf("\n");
                }else{
                    printf(" tie\n");
                }
            }
        }
    }
    return 0;
}

