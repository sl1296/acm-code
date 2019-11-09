#include <stdio.h>
#define N 100
int stack[N],out[N];           //stack�����洢ջ�ڳ��ᣬout�����洢��ջ���
int n,cc=0;                     //n�����洢����������cc�����洢�������

void dfs(int in_num,int stack_cnt,int out_cnt) {
    /*
      �������������������״̬���������
      ��һ����ջ������Ϊin_num
      ջ�г�������Ϊstack_cnt�������Ŵ�������stack��
      �ѳ�ջ��������Ϊout_cnt�������Ŵ�������out��
    */

    //����ѳ�ջ��������Ϊn��˵����ջ��ɣ�������out���飬��һ���������cc
    if(out_cnt==n) {
        int i;
        for(i=0;i<n;++i) printf("%d ",out[i]);
        printf("\n");
        ++cc;
    }

    //�����ǰ״̬���п��Խ�ջ�ĳ��ᣬ���Խ�ջ
    if(in_num<=n) {
        //��һ�������ջ
        stack[stack_cnt]=in_num;
        ++stack_cnt;
        ++in_num;
        //������ջ������н��
        dfs(in_num,stack_cnt,out_cnt);
        //��ԭ��ջ�������˻�ԭ��״̬
        --in_num;
        --stack_cnt;
    }
    //�����ǰ״̬���п��Գ�ջ�ĳ��ᣬ���Գ�ջ
    if(stack_cnt>0) {
        //��һ�������ջ
        out[out_cnt]=stack[stack_cnt-1];
        ++out_cnt;
        --stack_cnt;
        //������ջ��Ľ��
        dfs(in_num,stack_cnt,out_cnt);
        //��ԭ��ջ�������˻�ԭ��״̬
        stack[stack_cnt]=out[out_cnt-1];
        ++stack_cnt;
        --out_cnt;
    }
}

int main() {
    //���복������
    scanf("%d",&n);
    //��������һ����ջ����Ϊ1��ջ�г�����Ϊ0���ѳ�ջ������Ϊ0��״̬�Ľ��
    dfs(1,0,0);
    printf("cc=%d\n",cc);    //����������
    return 0;
}

