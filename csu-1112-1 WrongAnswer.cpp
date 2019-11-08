
#include<cstdio>
#include<cstring>
using namespace std;
char str[110];
bool judge(char c)
{
    if(c>='0'&&c<='9') return true;
    else return false;
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        int n;
        scanf("%d",&n);
        getchar();
        int pos=0;
        int op[110];
        memset(op,0,sizeof(op));
        for(int i=1;i<=n;i++)
        {
            //getchar();
            gets(str);
            //printf("str=%s\n",str);
            if(str[0]=='L') op[i]=-1;
            else if(str[0]=='R') op[i]=1;
            else
            {
                int len=strlen(str);
                int k=0;
                int num=0;
                while(!judge(str[k])&&k<len)
                {
                  //  printf("k=%d\n",k);
                    k++;
                }
               // printf("---\n");
                while(judge(str[k])&&k<len)
                {
               //     printf("k=%d\n",k);
                    num=num*10+(str[k]-'0');
                    k++;
                }
                op[i]=op[num];
            }
            //printf("op[%d]=%d\n",i,op[i]);
        }
        for(int i=1;i<=n;i++)
            pos+=op[i];
        printf("%d\n",pos);
    }
    return 0;
}


