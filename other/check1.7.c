#include <stdio.h>
#define N 100
int stack[N],out[N];           //stack用来存储栈内车厢，out用来存储出栈结果
int n,cc=0;                     //n用来存储车厢总数，cc用来存储结果数量

void dfs(int in_num,int stack_cnt,int out_cnt) {
    /*
      这个函数用来对于以下状态搜索结果：
      下一个进栈车厢编号为in_num
      栈中车厢数量为stack_cnt，车厢编号存在数组stack中
      已出栈车厢数量为out_cnt，车厢编号存在数组out中
    */

    //如果已出栈车厢数量为n，说明出栈完成，输出结果out数组，计一个结果数到cc
    if(out_cnt==n) {
        int i;
        for(i=0;i<n;++i) printf("%d ",out[i]);
        printf("\n");
        ++cc;
    }

    //如果当前状态还有可以进栈的车厢，尝试进栈
    if(in_num<=n) {
        //让一个车厢进栈
        stack[stack_cnt]=in_num;
        ++stack_cnt;
        ++in_num;
        //搜索进栈后的所有结果
        dfs(in_num,stack_cnt,out_cnt);
        //还原进栈操作，退回原来状态
        --in_num;
        --stack_cnt;
    }
    //如果当前状态还有可以出栈的车厢，尝试出栈
    if(stack_cnt>0) {
        //让一个车厢出栈
        out[out_cnt]=stack[stack_cnt-1];
        ++out_cnt;
        --stack_cnt;
        //搜索出栈后的结果
        dfs(in_num,stack_cnt,out_cnt);
        //还原出栈操作，退回原来状态
        stack[stack_cnt]=out[out_cnt-1];
        ++stack_cnt;
        --out_cnt;
    }
}

int main() {
    //输入车厢总数
    scanf("%d",&n);
    //搜索“下一个进栈车厢为1，栈中车厢数为0，已出栈车厢数为0”状态的结果
    dfs(1,0,0);
    printf("cc=%d\n",cc);    //输出情况数量
    return 0;
}

