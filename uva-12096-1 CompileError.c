
/*
code.c:1:9: fatal error: cstdio: No such file or directory
 #include
         ^~~~~~~~
compilation terminated.
*/
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
struct sett{
	vector<sett> x;
	sett(){
		x.clear();
	}
	bool operator == (const sett &p) const{
        if(x.size()!=p.x.size())return false;
        int sz=x.size();
        for(int i=0;i<sz;i++){
            if(!(x[i]==p.x[i]))return false;
        }
        return true;
	}
};
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		stack<sett> s;
		int n;
		scanf("%d",&n);
		char in[9];
		for(int i=0;i<n;i++){
			scanf("%s",in);
			if(in[0]=='P'){
                s.push(sett());
			}else if(in[0]=='D'){
                s.push(s.top());
			}else if(in[0]=='U'){
                sett t1=s.top();
                s.pop();
                sett t2=s.top();
                s.pop();
                int sz=t2.x.size();
                int sza=t1.x.size();
                for(int i=0;i<sz;i++){
                    bool pd=true;
                    for(int j=0;j<sza;j++){
                        if(t1.x[j]==t2.x[i]){
                            pd=false;
                            break;
                        }
                    }
                    if(pd)t1.x.push_back(t2.x[i]);
                }
                s.push(t1);
			}else if(in[0]=='I'){
                sett t1=s.top();
                s.pop();
                sett t2=s.top();
                s.pop();
                sett tt=sett();
                int sz=t2.x.size();
                int sza=t1.x.size();
                for(int i=0;i<sz;i++){
                    bool fin=false;
                    for(int j=0;j<sza;j++){
                        if(t1.x[j]==t2.x[i]){
                            fin=true;
                            break;
                        }
                    }
                    if(fin)tt.x.push_back(t2.x[i]);
                }
                s.push(tt);
			}else{
                sett t1=s.top();
                s.pop();
                sett t2=s.top();
                s.pop();
                bool have=false;
                int sz=t2.x.size();
                for(int i=0;i<sz;i++){
                    if(t2.x[i]==t1){
                        have=true;
                        break;
                    }
                }
                if(have==false)t2.x.push_back(t1);
                s.push(t2);
			}
			printf("%d\n",s.top().x.size());
		}
		printf("***\n");
	}
	return 0;
}

