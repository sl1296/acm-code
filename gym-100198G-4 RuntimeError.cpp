
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
using namespace std;
char in[1010],in2[1010];
int pre[1010];
struct node{
    bool isnum;
    int fa;
    int val;
    string name;
};
node var[100010];
map<string,int> ms;
map<int,int> mi;
int ffind(int x){
	if(var[x].fa==x)return x;
	return var[x].fa=ffind(var[x].fa);
}
int ppow(int a,int b){
    if(a==1)return 1;
    if(a==0)return 0;
    int ret=1;
    for(int i=0;i<b;i++)ret*=a;
    return ret;
}
int cal(int ss,int ee){
   // printf("ss=%d ee=%d\n",ss,ee);
    while(in[ss]=='('&&in[ee-1]==')'&&pre[ee-1]==ss&&ss<ee){
        ss++;ee--;
    }
    if(ss>=ee)return 0;
  /*  for(int i=ss;i<ee;i++){
        printf("%c",in[i]);
    }
    printf("\n");*/
	int cs=0;
	int pos[1010];
	char op[1010];
	int cnt=1;
	for(int i=ss;i<ee;i++){
		if(in[i]=='(')cs++;
		else if(in[i]==')')cs--;
		else if(cs==0){
			if((in[i]=='+'||in[i]=='-')&&i>ss&&(in[i-1]!='+'&&in[i-1]!='-'&&in[i-1]!='*'&&in[i-1]!='/'&&in[i-1]!='%'&&in[i]!='^')){
                op[cnt]=in[i];
                pos[cnt]=i;
                cnt++;
			}
		}
	}
	pos[cnt]=ee;
	if(cnt>1){
        int ans=cal(ss,pos[1]);
        for(int i=1;i<cnt;i++){
            int tmp=cal(pos[i]+1,pos[i+1]);
            if(op[i]=='+')ans+=tmp;else ans-=tmp;
        }
        return ans;
	}
	cs=0;
	cnt=1;
	for(int i=ss;i<ee;i++){
		if(in[i]=='(')cs++;
		else if(in[i]==')')cs--;
		else if(cs==0){
            if(in[i]=='*'||in[i]=='/'||in[i]=='%'){
                op[cnt]=in[i];
                pos[cnt]=i;
                cnt++;
            }
		}
	}
	pos[cnt]=ee;
	if(cnt>1){
        int ans=cal(ss,pos[1]);
        for(int i=1;i<cnt;i++){
            int tmp=cal(pos[i]+1,pos[i+1]);
            if(op[i]=='*')ans*=tmp;
            else if(op[i]=='/'){
                int fh=1;
                if(ans<0)fh*=-1;
                if(tmp<0)fh*=-1;
                ans=abs(ans)/abs(tmp);
                ans*=fh;
            }else{
                int fh=1;
                if(ans<0)fh*=-1;
                if(tmp<0)fh*=-1;
                ans=abs(ans);
                tmp=abs(tmp);
                ans=ans%tmp;
                ans*=fh;
            }
        }
        return ans;
	}
	cnt=1;
	cs=0;
	for(int i=ss;i<ee;i++){
		if(in[i]=='(')cs++;
		else if(in[i]==')')cs--;
		else if(cs==0){
            if(in[i]=='^'){
                pos[cnt]=i;
                cnt++;
            }
		}
	}
	pos[cnt]=ee;
	pos[0]=ss-1;
	if(cnt>1){
        int ans=cal(pos[cnt-1]+1,pos[cnt]);
        for(int i=cnt-1;i>0;i--){
            int tmp=cal(pos[i-1]+1,pos[i]);
            ans=ppow(tmp,ans);
        }
        return ans;
	}
    if(in[ss]=='+')return cal(ss+1,ee);
    if(in[ss]=='-')return -cal(ss+1,ee);
    bool isdig=true;
    int now=0;
    for(int i=ss;i<ee;i++){
        if(in[i]<'0'||in[i]>'9'){
            isdig=false;
            break;
        }
        now=now*10+in[i]-48;
    }
    if(isdig){
        int id=mi[now];
        if(id==0)return now;
        id=ffind(id);
        if(var[id].isnum)return var[id].val;
        return 0;
    }else{
        char ins[1010];
        int pp=0;
        for(int i=ss;i<ee;i++){
            ins[pp++]=in[i];
        }
        ins[pp]=0;
        for(int i=0;i<pp;i++){
            if(ins[i]>='A'&&ins[i]<='Z')ins[i]+=32;
        }
        int id=ms[ins];
        if(id==0)return 0;
        id=ffind(id);
        if(var[id].isnum)return var[id].val;
        return 0;
    }
}
void print(){
	int len=strlen(in);
	int stak[1010],sp=0;
	for(int i=0;i<len;i++){
        if(in[i]=='('){
            stak[sp++]=i;
        }else if(in[i]==')'){
            pre[i]=stak[--sp];
        }
	}
	printf("%d\n",cal(0,len));
}
int main(){
    freopen("plcool.in","r",stdin);
    freopen("plcool.out","w+",stdout);
    int cnt=1;
    while(~scanf("%s",in)){
        if(strcmp(in,"print")==0){
            scanf("%s",in);
            print();
        }else{
            scanf("%s%s",in,in2);
            int len=strlen(in);
            int len2=strlen(in2);
            bool pd=true;
            int now=0;
            for(int i=0;i<len;i++){
                if(in[i]<'0'||in[i]>'9'){
                    pd=false;
                    break;
                }
                now=now*10+in[i]-48;
            }
            int id1,id2;
            if(pd){
                id1=mi[now];
                if(id1==0){
                    var[cnt]=(node){true,cnt,now,""};
                    mi[now]=cnt;
                    id1=cnt;
                    cnt++;
                }
            }else{
                for(int i=0;i<len;i++){
                    if(in[i]>='A'&&in[i]<='Z')in[i]+=32;
                }
                id1=ms[in];
                if(id1==0){
                    var[cnt]=(node){false,cnt,-1,in};
                    ms[in]=cnt;
                    id1=cnt;
                    cnt++;
                }
            }
          //  printf("cnt=%d\n",cnt);
            pd=true;
            now=0;
            for(int i=0;i<len2;i++){
                if(in2[i]<'0'||in2[i]>'9'){
                    pd=false;
                    break;
                }
                now=now*10+in2[i]-48;
            }
            if(pd){
                id2=mi[now];
                if(id2==0){
                    var[cnt]=(node){true,cnt,now,""};
                    mi[now]=cnt;
                    id2=cnt;
                    cnt++;
                }
            }else{
                for(int i=0;i<len2;i++){
                    if(in2[i]>='A'&&in2[i]<='Z')in2[i]+=32;
                }
                id2=ms[in2];
              //  printf("id2=%d cnt=%d\n",id2,cnt);
                if(id2==0){
                    var[cnt]=(node){false,cnt,-1,in2};
                    ms[in2]=cnt;
                    id2=cnt;
                    cnt++;
                }
            }
          //  printf("id1=%d id2=%d\n",id1,id2);
            int xx=ffind(id1);
            int yy=ffind(id2);
            if(xx!=yy&&var[id1].fa==id1){
            	var[id1].fa=yy;
            }
        }
    }
    return 0;
}
/*
define 2 3
define 3 x
define x y
define y 5
print 4
print 2
print 3
0

*/

