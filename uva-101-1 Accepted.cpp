
#include<cstdio>
#include<cstring>
int now[30][30],cnt[30],posx[30],posy[30];
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			cnt[i]=1;
			now[i][0]=i;
			posx[i]=i;
			posy[i]=0;
		}
		while(1){
			char in[10];
			scanf("%s",in);
			if(strcmp(in,"quit")==0)break;
			int a,b;
			char in2[10];
			scanf("%d%s%d",&a,in2,&b);
			if(posx[a]==posx[b])continue;
			if(in[0]=='m'){
				if(in2[1]=='n'){
					for(int i=posy[a]+1;i<cnt[posx[a]];i++){
						int tmp=now[posx[a]][i];
						posx[tmp]=tmp;
						posy[tmp]=cnt[tmp];
						now[tmp][cnt[tmp]++]=tmp;
					}
					cnt[posx[a]]=posy[a];
					for(int i=posy[b]+1;i<cnt[posx[b]];i++){
						int tmp=now[posx[b]][i];
						posx[tmp]=tmp;
						posy[tmp]=cnt[tmp];
						now[tmp][cnt[tmp]++]=tmp;
					}
					cnt[posx[b]]=posy[b]+2;
					posx[a]=posx[b];
					posy[a]=posy[b]+1;
					now[posx[a]][posy[a]]=a;
				}else{
					for(int i=posy[a]+1;i<cnt[posx[a]];i++){
						int tmp=now[posx[a]][i];
						posx[tmp]=tmp;
						posy[tmp]=cnt[tmp];
						now[tmp][cnt[tmp]++]=tmp;
					}
					cnt[posx[a]]=posy[a];
					posx[a]=posx[b];
					posy[a]=cnt[posx[b]]++;
					now[posx[a]][posy[a]]=a;
				}
			}else{
				if(in2[1]=='n'){
					for(int i=posy[b]+1;i<cnt[posx[b]];i++){
						int tmp=now[posx[b]][i];
						posx[tmp]=tmp;
						posy[tmp]=cnt[tmp];
						now[tmp][cnt[tmp]++]=tmp;
					}
					cnt[posx[b]]=posy[b]+1;
					int from=posx[a];
					int ch=posy[a];
					int all=cnt[posx[a]];
					for(int i=posy[a];i<all;i++){
						cnt[from]--;
						int tmp=now[from][i];
						posx[tmp]=posx[b];
						posy[tmp]=cnt[posx[b]]++;
						now[posx[tmp]][posy[tmp]]=tmp;
					}
					cnt[from]=ch;
				}else{
					int from=posx[a];
					int ch=posy[a];
					int all=cnt[posx[a]];
					for(int i=posy[a];i<all;i++){
						cnt[from]--;
						int tmp=now[from][i];
						posx[tmp]=posx[b];
						posy[tmp]=cnt[posx[b]]++;
						now[posx[tmp]][posy[tmp]]=tmp;
					}
					cnt[from]=ch;
				}
			}
		}
		for(int i=0;i<n;i++){
			printf("%d:",i);
			for(int j=0;j<cnt[i];j++){
				printf(" %d",now[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

