
/*
0_0_21726899_15222.cpp: In function 'int main()':
0_0_21726899_15222.cpp:70:33: error: reference to 'next' is ambiguous
                 v.way.push_back(next[i]);
                                 ^
0_0_21726899_15222.cpp:19:6: note: candidates are: char next [5]
 char next[5]="udlr";
      ^
In file included from 4.9.2/x86_64-w64-mingw32/include/c++/bits/stl_algobase.h:66:0,
                 from 4.9.2/x86_64-w64-mingw32/include/c++/algorithm:61,
                 from 0_0_21726899_15222.cpp:3:
4.9.2/x86_64-w64-mingw32/include/c++/bits/stl_iterator_base_funcs.h:184:5: note:                 template<class _ForwardIterator> _ForwardIterator std::next(_ForwardIterator, typename std::iterator_traits<_Iter>::difference_type)
     next(_ForwardIterator __x, typename
     ^
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
struct node{
    char z[3][3];
    bool operator < (const node &p) const{
        for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(z[i][j]!=p.z[i][j])return z[i][j]<p.z[i][j];
        return false;
    }
};
struct stt{
    int x,y;
    vector<char> way;
    node s;
};
char next[5]="udlr";
int tx[5]={-1,1,0,0};
int ty[5]={0,0,-1,1};
int sx,sy;
int main(){
    system("chcp 936");
    node sss;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            sss.z[i][j]=(i==2&&j==2)?'x':49+i*3+j;
          //  printf("%c ",sss.z[i][j]);
        }
    }
    char in[5];
    while(~scanf("%s",in)){
        node s;
        s.z[0][0]=in[0];
        if(in[0]=='x')sx=sy=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==0&&j==0)continue;
                scanf("%s",in);
                s.z[i][j]=in[0];
                if(in[0]=='x')sx=i,sy=j;
            }
        }
        map<node,int> ma;
        ma.clear();
        ma[sss]=2;
        //printf(":::%d\n",ma[sss]);
        queue<stt> qu;
      //  printf("::%d\n",ma[s]);
        ma[s]=1;
     //   printf("::%d\n",ma[s]);
        stt ad;
        ad.way.clear();
        ad.s=s;
        ad.x=sx;
        ad.y=sy;
        vector<char> ans;
        ans.clear();
        qu.push(ad);
        while(!qu.empty()){
            //    printf("---");
            stt u=qu.front();
            qu.pop();
            for(int i=0;i<4;i++){
                stt v=u;
                if(v.x+tx[i]<0||v.x+tx[i]>2||v.y+ty[i]<0||v.y+ty[i]>2)continue;
                swap(v.s.z[v.x][v.y],v.s.z[v.x+tx[i]][v.y+ty[i]]);
                if(ma[v.s]==1)continue;
                v.way.push_back(next[i]);
                v.x+=tx[i];
                v.y+=ty[i];
                if(ma[v.s]==2){
                    ans=v.way;
                    goto ed;
                }
                ma[v.s]=1;
            /*    for(int ii=0;ii<3;ii++){
                    for(int j=0;j<3;j++)printf("%c",v.s.z[ii][j]);printf("\n");
                }
                printf("x=%d y=%d\n",v.x,v.y);
                for(int ii=0;ii<v.way.size();ii++)printf("%c",v.way[ii]);printf("\n");*/
                qu.push(v);
            }
        }
        ed:
        int sz=ans.size();
        if(sz){
            for(int i=0;i<sz;i++)printf("%c",ans[i]);
            printf("\n");
        }else{
            printf("unsolvable\n");
        }
    }
    return 0;
}

