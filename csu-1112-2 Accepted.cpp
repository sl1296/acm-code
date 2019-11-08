
#include<cstdio>
#include<cstring>
using namespace std;
char str[110],s1[110];
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        int n;
        scanf("%d",&n);
        int pos=0;
        int op[110];
        memset(op,0,sizeof(op));
        for(int i=1;i<=n;i++)
        {
            scanf("%s",str);
            if(str[0]=='L') op[i]=-1;
            else if(str[0]=='R') op[i]=1;
            else
            {
                int num;
                scanf("%s%d",s1,&num);
                op[i]=op[num];
            }
        }
        for(int i=1;i<=n;i++)
            pos+=op[i];
        printf("%d\n",pos);
    }
    return 0;
}


