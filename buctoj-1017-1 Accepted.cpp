
#include<cstdio>
#include<set>
using namespace std;
int a[100010];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
        }
        int cal=0,mx=0;
        for(int i=29;i>=0;--i){
            set<int> se;
            cal|=(1<<i);
            for(int j=0;j<n;++j){
                se.insert(cal&a[j]);
            }
            int tmp=mx|(1<<i);
            for(set<int>::iterator j=se.begin();j!=se.end();++j){
                if(se.find(tmp^(*j))!=se.end()){
                    mx=tmp;
                    break;
                }
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
 
/**************************************************************
    Problem: 1017
    User: asdcvbn
    Language: C++
    Result: ÕýÈ·
    Time:708 ms
    Memory:6320 kb
****************************************************************/

