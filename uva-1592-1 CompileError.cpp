
/*
code.cpp: In function 'int main()':
code.cpp:25:16: warning: 'char* gets(char*)' is deprecated [-Wdeprecated-declarations]
         gets(in);
                ^
In file included from /usr/include/c++/7.1.1/cstdio:42:0,
                 from code.cpp:1:
/usr/include/stdio.h:641:14: note: declared here
 extern char *gets (char *__s) __wur __attribute_deprecated__;
              ^~~~
code.cpp:28:20: warning: 'char* gets(char*)' is deprecated [-Wdeprecated-declarations]
             gets(in);
                    ^
In file included from /usr/include/c++/7.1.1/cstdio:42:0,
                 from code.cpp:1:
/usr/include/stdio.h:641:14: note: declared here
 extern char *gets (char *__s) __wur __attribute_deprecated__;
              ^~~~
code.cpp:35:21: error: reference to 'get' is ambiguous
                     get[k++]=in[pp++];
                     ^~~
code.cpp:9:6: note: candidates are: char get [100010]
 char get[100010];
      ^~~
In file included from /usr/include/c++/7.1.1/bits/stl_map.h:63:0,
                 from /usr/include/c++/7.1.1/map:61,
                 from code.cpp:2:
/usr/include/c++/7.1.1/tuple:1326:5: note:                 template constexpr std::__tuple_element_t<__i, std::tuple<_Args2 ...> >&& std::get(std::tuple<_Args2 ...>&&)
     get(tuple<_Elements...>&& __t) noexcept
     ^~~
/usr/include/c++/7.1.1/tuple:1320:5: note:                 template constexpr std::__tuple_element_t<__i, std::tuple<_Args2 ...> >& std::get(const std::tuple<_Args2 ...>&)
     get(const tuple<_Elements...>& __t) noexcept
     ^~~
/usr/include/c++/7.1.1/tuple:1314:5: note:                 template constexpr std::__tuple_element_t<__i, std::tuple<_Args2 ...> >& std::get(std::tuple<_Args2 ...>&)
     get(tuple<_Elements...>& __t) noexcept
     ^~~
In file included from /usr/include/c++/7.1.1/tuple:39:0,
                 from /usr/include/c++/7.1.1/bits/stl_map.h:63,
                 from /usr/include/c++/7.1.1/map:61,
                 from code.cpp:2:
/usr/include/c++/7.1.1/array:324:5: note:                 template constexpr const _Tp& std::get(const std::array<_Tp, _Nm>&)
     get(const array<_Tp, _Nm>& __arr) noexcept
     ^~~
/usr/include/c++/7.1.1/array:316:5: note:                 template constexpr _Tp&& std::get(std::array<_Tp, _Nm>&&)
     get(array<_Tp, _Nm>&& __arr) noexcept
     ^~~
/usr/include/c++/7.1.1/array:307:5: note:                 template constexpr _Tp& std::get(std::array<_Tp, _Nm>&)
     get(array<_Tp, _Nm>& __arr) noexcept
     ^~~
In file included from /usr/include/c++/7.1.1/tuple:38:0,
                 from /usr/include/c++/7.1.1/bits/stl_map.h:63,
                 from /usr/include/c++/7.1.1/map:61,
                 from code.cpp:2:
/usr/include/c++/7.1.1/utility:239:5: note:                 template constexpr const typename std::tuple_element<_Int, std::pair<_Tp1, _Tp2> >::type& std::get(const std::pair<_Tp1, _Tp2>&)
     get(const std::pair<_Tp1, _Tp2>& __in) noexcept
     ^~~
/usr/include/c++/7.1.1/utility:234:5: note:                 template constexpr typename std::tuple_element<_Int, std::pair<_Tp1, _Tp2> >::type&& std::get(std::pair<_Tp1, _Tp2>&&)
     get(std::pair<_Tp1, _Tp2>&& __in) noexcept
     ^~~
/usr/include/c++/7.1.1/utility:229:5: note:                 template constexpr typename std::tuple_element<_Int, std::pair<_Tp1, _Tp2> >::type& std::get(std::pair<_Tp1, _Tp2>&)
     get(std::pair<_Tp1, _Tp2>& __in) noexcept
     ^~~
code.cpp:37:17: error: reference to 'get' is ambiguous
                 get[k]=0;
                 ^~~
code.cpp:9:6: note: candidates are: char get [100010]
 char get[100010];
      ^~~
In file included from /usr/include/c++/7.1.1/bits/stl_map.h:63:0,
                 from /usr/include/c++/7.1.1/map:61,
                 from code.cpp:2:
/usr/include/c++/7.1.1/tuple:1326:5: note:                 template constexpr std::__tuple_element_t<__i, std::tuple<_Args2 ...> >&& std::get(std::tuple<_Args2 ...>&&)
     get(tuple<_Elements...>&& __t) noexcept
     ^~~
/usr/include/c++/7.1.1/tuple:1320:5: note:                 template constexpr std::__tuple_element_t<__i, std::tuple<_Args2 ...> >& std::get(const std::tuple<_Args2 ...>&)
     get(const tuple<_Elements...>& __t) noexcept
     ^~~
/usr/include/c++/7.1.1/tuple:1314:5: note:                 template constexpr std::__tuple_element_t<__i, std::tuple<_Args2 ...> >& std::get(std::tuple<_Args2 ...>&)
     get(tuple<_Elements...>& __t) noexcept
     ^~~
In file included from /usr/include/c++/7.1.1/tuple:39:0,
                 from /usr/include/c++/7.1.1/bits/stl_map.h:63,
                 from /usr/include/c++/7.1.1/map:61,
                 from code.cpp:2:
/usr/include/c++/7.1.1/array:324:5: note:                 template constexpr const _Tp& std::get(const std::array<_Tp, _Nm>&)
     get(const array<_Tp, _Nm>& __arr) noexcept
     ^~~
/usr/include/c++/7.1.1/array:316:5: note:                 template constexpr _Tp&& std::get(std::array<_Tp, _Nm>&&)
     get(array<_Tp, _Nm>&& __arr) noexcept
     ^~~
/usr/include/c++/7.1.1/array:307:5: note:                 template constexpr _Tp& std::get(std::array<_Tp, _Nm>&)
     get(array<_Tp, _Nm>& __arr) noexcept
     ^~~
In file included from /usr/include/c++/7.1.1/tuple:38:0,
                 from /usr/include/c++/7.1.1/bits/stl_map.h:63,
                 from /usr/include/c++/7.1.1/map:61,
                 from code.cpp:2:
/usr/include/c++/7.1.1/utility:239:5: note:                 template constexpr const typename std::tuple_element<_Int, std::pair<_Tp1, _Tp2> >::type& std::get(const std::pair<_Tp1, _Tp2>&)
     get(const std::pair<_Tp1, _Tp2>& __in) noexcept
     ^~~
/usr/include/c++/7.1.1/utility:234:5: note:                 template constexpr typename std::tuple_element<_Int, std::pair<_Tp1, _Tp2> >::type&& std::get(std::pair<_Tp1, _Tp2>&&)
     get(std::pair<_Tp1, _Tp2>&& __in) noexcept
     ^~~
/usr/include/c++/7.1.1/utility:229:5: note:                 template constexpr typename std::tuple_element<_Int, std::pair<_Tp1, _Tp2> >::type& std::get(std::pair<_Tp1, _Tp2>&)
     get(std::pair<_Tp1, _Tp2>& __in) noexcept
     ^~~
code.cpp:38:27: error: reference to 'get' is ambiguous
                 int id=ma[get];
                           ^~~
code.cpp:9:6: note: candidates are: char get [100010]
 char get[100010];
      ^~~
In file included from /usr/include/c++/7.1.1/bits/stl_map.h:63:0,
                 from /usr/include/c++/7.1.1/map:61,
                 from code.cpp:2:
/usr/include/c++/7.1.1/tuple:1326:5: note:                 template constexpr std::__tuple_element_t<__i, std::tuple<_Args2 ...> >&& std::get(std::tuple<_Args2 ...>&&)
     get(tuple<_Elements...>&& __t) noexcept
     ^~~
/usr/include/c++/7.1.1/tuple:1320:5: note:                 template constexpr std::__tuple_element_t<__i, std::tuple<_Args2 ...> >& std::get(const std::tuple<_Args2 ...>&)
     get(const tuple<_Elements...>& __t) noexcept
     ^~~
/usr/include/c++/7.1.1/tuple:1314:5: note:                 template constexpr std::__tuple_element_t<__i, std::tuple<_Args2 ...> >& std::get(std::tuple<_Args2 ...>&)
     get(tuple<_Elements...>& __t) noexcept
     ^~~
In file included from /usr/include/c++/7.1.1/tuple:39:0,
                 from /usr/include/c++/7.1.1/bits/stl_map.h:63,
                 from /usr/include/c++/7.1.1/map:61,
                 from code.cpp:2:
/usr/include/c++/7.1.1/array:324:5: note:                 template constexpr const _Tp& std::get(const std::array<_Tp, _Nm>&)
     get(const array<_Tp, _Nm>& __arr) noexcept
     ^~~
/usr/include/c++/7.1.1/array:316:5: note:                 template constexpr _Tp&& std::get(std::array<_Tp, _Nm>&&)
     get(array<_Tp, _Nm>&& __arr) noexcept
     ^~~
/usr/include/c++/7.1.1/array:307:5: note:                 template constexpr _Tp& std::get(std::array<_Tp, _Nm>&)
     get(array<_Tp, _Nm>& __arr) noexcept
     ^~~
In file included from /usr/include/c++/7.1.1/tuple:38:0,
                 from /usr/include/c++/7.1.1/bits/stl_map.h:63,
                 from /usr/include/c++/7.1.1/map:61,
                 from code.cpp:2:
/usr/include/c++/7.1.1/utility:239:5: note:                 template constexpr const typename std::tuple_element<_Int, std::pair<_Tp1, _Tp2> >::type& std::get(const std::pair<_Tp1, _Tp2>&)
     get(const std::pair<_Tp1, _Tp2>& __in) noexcept
     ^~~
/usr/include/c++/7.1.1/utility:234:5: note:                 template constexpr typename std::tuple_element<_Int, std::pair<_Tp1, _Tp2> >::type&& std::get(std::pair<_Tp1, _Tp2>&&)
     get(std::pair<_Tp1, _Tp2>&& __in) noexcept
     ^~~
/usr/include/c++/7.1.1/utility:229:5: note:                 template constexpr typename std::tuple_element<_Int, std::

*/
#include<cstdio>
#include<map>
#include<string>
#include<cstring>
using namespace std;
char in[100010];
map<string,int> ma;
int data[10010][15];
char get[100010];
struct node{
    int a,b;
    bool operator < (const node &p) const{
        if(a!=p.a)return a<p.a;
        return b<p.b;
    }
};
map<node,int> ys[15][15];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        int cnt=1;
        int r1,r2,c1,c2;
        ma.clear();
        for(int i=0;i<15;i++)for(int j=0;j<15;j++)ys[i][j].clear();
        gets(in);
        bool ans=true;
        for(int i=0;i<n;i++){
            gets(in);
            if(!ans)continue;
            int len=strlen(in);
            int pp=0;
            for(int j=0;j<m;j++){
                int k=0;
                while(in[pp]!=','&&in[pp]!=0){
                    get[k++]=in[pp++];
                }
                get[k]=0;
                int id=ma[get];
                if(id==0){
                    ma[get]=cnt;
                    id=cnt++;
                }
                data[i][j]=id;
            }
            for(int j=0;j<m;j++){
                for(int k=j+1;k<m;k++){
                    node to=(node){data[i][j],data[i][k]};
                    int from=ys[j][k][to];
                    if(from){
                        ans=false;
                        r1=from+1;
                        r2=i+1;
                        c1=j+1;
                        c2=k+1;
                        break;
                    }else{
                        ys[j][k][to]=i;
                    }
                }
                if(!ans)break;
            }
        }
        if(ans)printf("YES\n");
        else printf("NO\n%d %d\n%d %d\n",r1,r2,c1,c2);
    }
    return 0;
}

