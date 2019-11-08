
#include <stdio.h>
#define N 1010
int pre[N],mid[N];

struct node{
	int key;
	int ch[2];
}tree[N];
int cnt;
int n;
int all;

int build(int pb,int mb,int n){
	int i,k;

	if(n==0) return -1;
	k = cnt++;
	tree[k].key = pre[pb];
	for(i=0;i<n&&mid[mb+i]!=pre[pb];i++);
	tree[k].ch[0] = build(pb+1,mb,i);
	tree[k].ch[1] = build(pb+i+1,mb+i+1,n-1-i);
	return k;
}

void out(int x){
    if(tree[x].ch[0]>-1)out(tree[x].ch[0]);
    if(tree[x].ch[1]>-1)out(tree[x].ch[1]);
    all++;
    printf("%d",tree[x].key);
    if(all<n)printf(" ");
    else printf("\n");
}
int main(){
    int i;
    while(scanf("%d",&n)!=EOF){
    cnt=all=0;
    for(i=0;i<n;i++){
        scanf("%d",&pre[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&mid[i]);
    }
    build(0,0,n);
    out(0);
    }
}

