
/*
�����߶���,���߶��������0,1��Ǳ�ʾ�������Ƿ������s��

U T S �� S �� T ����[l,r]���Ϊ1
I T S �� S �� T ����-oo~l��r~+oo���Ϊ0,��Ϊ�ǲ���,���Բ�����ļ���sһ����[l,r]��,����l,r�ڵļ��ϱ������ʲô״̬����ʲô״̬(��ʾ�Ƿ�����s),[l,r]��ļ��ϲ�����s���Ա��Ϊ0
D T S �� S - T  ����[l,r]���Ϊ0,����[l,r]�ڱ�s�����ļ���Ҳ����Ϊ0��ʾ��������s
C T S �� T - S  ���Ƚ�-oo~l,r~+oo���Ϊ0,�ⲿ�ֲ�����[l,r]��һ��������s,Ȼ��[l,r]�ı��0/1����,��Ϊ����s�Ĳ�������s,������s�Ľ�����s
S T S �� S �� T  ������s�Ĳ���,[l,r]�в�����s��(����)0���Ϊ1,����s��(����)1���Ϊ0,����[l,r]�ı��0/1����

��������l,r���ʱ��ǽ�l*2,r*2���,����Ǳ��������l*2+1,��r*2-1���б��,�������ʱ��ֻ���ж���ż�����жϿ�������
�Ƿ񸲸�0,1�Ƿ�ת��0,1��0,1ת�������������ȥת��
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=65535*2+2;
int cover[MAX<<2],Xor[MAX<<2];//cover��ʾ�����0,1״̬,Xor��ʾ������ת����״̬
int mark[MAX];

void UpXor(int n){
    if(cover[n] != -1)cover[n]^=1;//��ʾ�����������ͬʱת��
    else Xor[n]^=1;
}

void Upchild(int n){
    if(cover[n] != -1){//��ʾ�ýڵ����˵��Ǻ���δ���
        cover[n<<1]=cover[n<<1|1]=cover[n];
        Xor[n<<1]=Xor[n<<1|1]=0;//����ȫ��������ԭ����ת�����κ�������
        cover[n]=-1;
    }
    if(Xor[n]){//��ʾ�õ�ת���˵��Ǻ���δת��
        UpXor(n<<1);
        UpXor(n<<1|1);
        Xor[n]=0;
    }
}

void Update(int L,int R,char ch,int n,int left,int right){
    if(L<=left && right<=R){
        if(ch == 'U')cover[n]=1,Xor[n]=0;
        if(ch == 'D')cover[n]=Xor[n]=0;
        if(ch == 'S' || ch == 'C')UpXor(n);
        return;
    }
    Upchild(n);//�Ƿ�ýڵ��ǻ�ת����������δ��ǻ�ת��
    int mid=left+right>>1;
    if(L<=mid)Update(L,R,ch,n<<1,left,mid);
    else if(ch == 'I' || ch == 'C')cover[n<<1]=Xor[n<<1]=0;//��-oo~l�е�-oo~mid���Ϊ0
    if(R>mid)Update(L,R,ch,n<<1|1,mid+1,right);
    else if(ch == 'I' || ch == 'C')cover[n<<1|1]=Xor[n<<1|1]=0;//��r~+oo�е�mid+1~+oo���Ϊ0
}

void Query(int n,int left,int right){
    if(cover[n] == 1){
        for(int i=left;i<=right;++i)mark[i]=true;
        return;
    }
    if(cover[n] == 0)return;
    if(left == right)return;
    Upchild(n);
    int mid=left+right>>1;
    Query(n<<1,left,mid);
    Query(n<<1|1,mid+1,right);
}

int main(){
    int l,r;
    char a,b,c;
    while(scanf("%c %c%d,%d%c",&a,&b,&l,&r,&c)!=EOF){
        l<<=1,r<<=1;
        if(b == '(')++l;
        if(c == ')')--r;
        if(l>r){//������������ΪI (1,1)��C (1,1)
            if(a == 'I' || a == 'C')cover[1]=Xor[1]=0;//��-oo~l,r~+oo���Ϊ0
        }else Update(l,r,a,1,0,MAX);
        getchar();
    }
    bool flag=false;
    int s=-1,t=-1;
    Query(1,0,MAX);
    for(int i=0;i<MAX;++i){
        if(mark[i])s=(s==-1?i:s),t=i;
        else if(s != -1){
            if(flag)printf(" ");
            flag=true;
            printf("%c%d,%d%c",s&1?'(':'[',s>>1,(t+1)>>1,t&1?')':']');
            s=-1;
        }
    }
    if(!flag)printf("empty set");
    printf("\n");
    return 0;
}

