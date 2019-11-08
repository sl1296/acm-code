
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
	bool operator < (const sett &p) const{
	    int sz=x.size(),sza=p.x.size();
        if(sz!=sza)return sz<sza;
        for(int i=0;i<sz;i++){
            return x[i]<p.x[i];
        }
        return false;
	}
	bool operator == (const sett &p) const{
	    int sz=x.size(),sza=p.x.size();
        if(sz!=sza)return false;
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
                t1.x.resize(sz+sza);
                for(int i=0;i<sz;i++)t1.x[i+sza]=t2.x[i];
                sort(t1.x.begin(),t1.x.end());
                int szr=sz+sza;
                int pp=0;
                for(int i=0;i<szr;i++){
                    if(i+1<szr&&t1.x[i+1]==t1.x[i])i++;
                    t1.x[pp++]=t1.x[i];
                }
                t1.x.resize(pp);
                s.push(t1);
			}else if(in[0]=='I'){
                sett t1=s.top();
                s.pop();
                sett t2=s.top();
                s.pop();
                sett tt=sett();
                int sz=t2.x.size();
                int sza=t1.x.size();
                int szr=sz+sza;
                t1.x.resize(sz+sza);
                for(int i=0;i<sz;i++)t1.x[i+sza]=t2.x[i];
                sort(t1.x.begin(),t1.x.end());
                for(int i=1;i<szr;i++){
                    if(t1.x[i-1]==t1.x[i])tt.x.push_back(t1.x[i]);
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
                sort(t2.x.begin(),t2.x.end());
                s.push(t2);
			}
			printf("%d\n",s.top().x.size());
		}
		printf("***\n");
	}
	return 0;
}

