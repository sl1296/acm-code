#include <stdio.h>
int main() {
    int n,i,k,j;
    int vis[100]={0};                //vis[i]Ϊ0��ʾ����iδɾ��1��ʾ��ɾ
    scanf("%d%d%d",&n,&i,&k);       //����n,i,k��ֵ
    --i;                              //����ѭ����+1���жϣ�����-1
    for(j=0;j<n;++j) {               //һ��n��������Ҫɾn�Σ�ѭ��n��
        int cnt=0;                    //cnt��¼����ƶ��˼���λ��
        while(cnt<k) {                //ÿ����k��λ��
            ++i;
            if(i==n+1) i=1;           //�ƶ�i����һ��λ��
            if(vis[i]==0) ++cnt;     //ֻ��û��ɾ����λ��
        }
        vis[i]=1;                     //ɾ����k����
        printf("%d ",i);             //������
    }
    printf("\n");
    return 0;
}
