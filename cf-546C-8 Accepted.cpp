
#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n,a,b,i;
    queue<int> x,y;
    cin>>n>>a;
    for(i=0;i<a;i++){
        cin>>b;
        x.push(b);
    }
    cin>>a;
    for(i=0;i<a;i++){
        cin>>b;
        y.push(b);
    }
    int co=0;
    while(!x.empty() && !y.empty()){
        a=x.front();
        b=y.front();
        x.pop();
        y.pop();
        if(a<b){
            y.push(a);
            y.push(b);
        }else{
            x.push(b);
            x.push(a);
        }
        co++;
        if(co>100000){
            cout<<"-1"<<endl;
            return 0;
        }
    }
    if(x.empty()){
        cout<<co<<" 2"<<endl;
    }else{
        cout<<co<<" 1"<<endl;
    }
    return 0;
}

