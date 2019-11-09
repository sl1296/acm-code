#include <stdio.h>
int main() {
    int n,i,k,j;
    int vis[100]={0};                //vis[i]为0表示数字i未删，1表示已删
    scanf("%d%d%d",&n,&i,&k);       //输入n,i,k的值
    --i;                              //下面循环先+1再判断，所以-1
    for(j=0;j<n;++j) {               //一共n个数字需要删n次，循环n次
        int cnt=0;                    //cnt记录这次移动了几个位置
        while(cnt<k) {                //每次数k个位置
            ++i;
            if(i==n+1) i=1;           //移动i到下一个位置
            if(vis[i]==0) ++cnt;     //只数没被删掉的位置
        }
        vis[i]=1;                     //删掉第k个数
        printf("%d ",i);             //输出结果
    }
    printf("\n");
    return 0;
}
