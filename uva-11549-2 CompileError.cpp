
/*
code.cpp: In function 'int main()':
code.cpp:15:16: error: wrong number of template arguments (1, should be at least 2)
         map s;
                ^
In file included from /usr/include/c++/6.3.1/map:61:0,
                 from /usr/include/c++/6.3.1/x86_64-pc-linux-gnu/bits/stdc++.h:81,
                 from code.cpp:2:
/usr/include/c++/6.3.1/bits/stl_map.h:96:11: note: provided for 'template class std::map'
     class map
           ^~~
code.cpp:16:18: error: request for member 'count' in 's', which is of non-class type 'int'
         while(!s.count(e)){
                  ^~~~~
code.cpp:17:15: error: request for member 'insert' in 's', which is of non-class type 'int'
             s.insert(e);
               ^~~~~~
*/
//adxtm
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        ll pd=1;
        for(int i=0;i<n;i++)pd*=10;
        ll e=k;
        int ans=k;
        map<int> s;
        while(!s.count(e)){
            s.insert(e);
            if(e>ans)ans=e;
            e=e*e;
            while(e>=pd)e/=10;
        }
        printf("%d\n",ans);
    }
    return 0;
}

