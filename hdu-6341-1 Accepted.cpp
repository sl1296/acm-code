
#include <bits/stdc++.h>
using namespace std;
struct rec{
    char c[4][4];
}a[16][4];
char g[20][20];
bool f1[16][16],f2[16][16];
int ans;
rec Rotate(const rec &r1)
{
    rec r2;
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
//            r2.c[3-j][i]=r1.c[i][j];
            r2.c[i][j]=r1.c[3-j][i];
    return r2;
}
inline bool check(int x,int y,int dep,int z)
{
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
        {
//            printf("%d %d %d ##\n",x+i,y+j,a[dep][z].c[i][j]);
            if(f1[x+i][a[dep][z].c[i][j]]) return false;
            if(f2[y+j][a[dep][z].c[i][j]]) return false;
        }
        return true;
}
void dfs(int dep,int tot)
{
//    printf("%d ?\n",dep);
    if(dep==16)
    {
//        printf("%d %d ?\n",dep,tot);
        ans=min(ans,tot);
        return;
    }
    int x=dep/4*4,y=dep%4*4;
    for(int z=0;z<4;++z)
    {
//        printf("%d !\n",z);
        if(!check(x,y,dep,z)) continue;
//        printf("%d !\n",z);
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
            {
                f1[x+i][a[dep][z].c[i][j]]=true;
                f2[y+j][a[dep][z].c[i][j]]=true;
            }
        dfs(dep+1,tot+z);
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
            {
                f1[x+i][a[dep][z].c[i][j]]=false;
                f2[y+j][a[dep][z].c[i][j]]=false;
            }
    }
}
char change(char c)
{
    if('0'<=c&&c<='9') return c-'0';
    if('A'<=c&&c<='F') return c-'A'+10;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        int x,y,z;
        for(int i=0;i<16;++i)
        {
            scanf("%s",g[i]);
            for(int j=0;j<16;++j)
            {
                z=i/4*4+j/4;
                x=i-i/4*4;
                y=j-j/4*4;
                a[z][0].c[x][y]=change(g[i][j]);
            }
        }
        for(int i=0;i<16;++i)
            for(int j=1;j<4;++j)
                a[i][j]=Rotate(a[i][j-1]);
//        for(int i=0;i<4;++i)
//        {
//            for(int j=0;j<4;++j)
//            {
//                for(int k=0;k<4;++k)
//                    printf("%2d ",a[2][i].c[j][k]);
//                printf("\n");
//            }
//            printf("\n");
//        }
        ans=0x3f3f3f3f;
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
/*
3
681D5A0C9FDBB2F7
0A734B62E167D9E5
5C9B73EF3C208410
F24ED18948A5CA63
39FAED5616400B74
D120C4B7CA3DEF38
7EC829A085BE6D51
B56438F129F79C2A
5C7FBC4E3D08719F
AE8B1673BF42A58D
60D3AF25619C30BE
294190D8EA57264C
C7D1B35606835EAB
AF52A1E019BE4306
8B36DC78D425F7C9
E409492FC7FA18D2

681D5A0C9FDBB2F7
0A734B62E167D9E5
5C9B73EF3C208410
F24ED18948A5CA63
39FAED5616400B74
D120C4B7CA3DEF38
7EC829A085BE6D51
B56438F129F79C2A
5C7FBC4E3D08719F
AE8B1673BF42A58D
60D3AF25619C30BE
294190D8EA57264C
C7D1B35606835EAB
AF52A1E019BE4306
8B36DC78D425F7C9
E409492FC7FA18D2

681D5A0C9FDBB2F7
0A734B62E167D9E5
5C9B73EF3C208410
F24ED18948A5CA63
39FAED5616400B74
D120C4B7CA3DEF38
7EC829A085BE6D51
B56438F129F79C2A
5C7FBC4E3D08719F
AE8B1673BF42A58D
60D3AF25619C30BE
294190D8EA57264C
C7D1B35606835EAB
AF52A1E019BE4306
8B36DC78D425F7C9
E409492FC7FA18D2
*/

