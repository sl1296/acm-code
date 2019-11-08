
//948D
#include<cstdio>
int a[300010];
int tmp[50];
struct node{
	int num,left,right;
};
node x[9000010];
int cnt=1;
int main(){
	int n,p;
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	x[0].left=x[0].right=-1;
	for(int i=0;i<n;++i){
		scanf("%d",&p);
		for(int j=0;j<30;++j){
			tmp[j]=p&1;
			p>>=1;
		}
		int now=0;
		for(int j=29;j>=0;--j){
            if(tmp[j]==0){
                if(x[now].left==-1){
                    x[now].left=cnt++;
                    now=x[now].left;
                    x[now].num=0;
                    x[now].left=x[now].right=-1;
                }else{
                    now=x[now].left;
                }
            }else{
                if(x[now].right==-1){
                    x[now].right=cnt++;
                    now=x[now].right;
                    x[now].num=0;
                    x[now].left=x[now].right=-1;
                }else{
                    now=x[now].right;
                }
            }
            ++x[now].num;
		}
	}
    for(int i=0;i<n;++i){
		for(int j=0;j<30;++j){
			tmp[j]=a[i]&1;
			a[i]>>=1;
		}
		int now=0,out=0;
		for(int j=29;j>=0;--j){
            if(tmp[j]==0){
                if(x[now].left!=-1 && x[x[now].left].num!=0){
                    now=x[now].left;
                    --x[now].num;
                }else{
                    now=x[now].right;
                    --x[now].num;
                    out+=1<<j;
                }
            }else{
                if(x[now].right!=-1 && x[x[now].right].num!=0){
                    now=x[now].right;
                    --x[now].num;
                }else{
                    now=x[now].left;
                    --x[now].num;
                    out+=1<<j;
                }
            }
		}
		printf("%d%c",out,i==n-1?'\n':' ');
    }
    return 0;
}


