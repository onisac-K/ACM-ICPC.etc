#include<bits/stdc++.h>
using namespace std;
const int N = 1<<11;

int tree1[N+5],tree2[N+5];
char str[N+5];

void insert(int x,int f){
	if(f == 1){
		int pos = 1;
		while(1){
			if(x>tree1[pos] && tree1[pos*2+1]==-1){
				tree1[pos*2+1] = x;
				break;
			}
			if(x>tree1[pos] && tree1[pos*2+1]!=-1){
				pos = pos*2+1;
			}
			if(x<tree1[pos] && tree1[pos*2]==-1){
				tree1[pos*2] = x;
				break;
			}
			if(x<tree1[pos] && tree1[pos*2]!=-1){
				pos = pos*2;
			}
		}
	}
	if(f == 2){
		int pos = 1;
		while(1){
			if(x>tree2[pos] && tree2[pos*2+1]==-1){
				tree2[pos*2+1] = x;
				break;
			}
			if(x>tree2[pos] && tree2[pos*2+1]!=-1){
				pos = pos*2+1;
			}
			if(x<tree2[pos] && tree2[pos*2]==-1){
				tree2[pos*2] = x;
				break;
			}
			if(x<tree2[pos] && tree2[pos*2]!=-1){
				pos = pos*2;
			}
		}
	}
	
}

int main()
{
	int n;
	while(cin>>n && n){
		memset(tree1,-1,sizeof(tree1));
		memset(tree2,-1,sizeof(tree2));
		scanf("%s",str);
		int L = strlen(str);
		tree1[1] = str[0]-'0';
		for(int i=1;i<L;++i){
			int x = str[i]-'0';
			insert(x,1);
		}
		for(int i=0;i<n;++i){	
			memset(tree2,-1,sizeof(tree2));
			scanf("%s",str);
			L = strlen(str);
			tree2[1] = str[0]-'0';
			for(int i=1;i<L;++i){
				int x = str[i]-'0';
				insert(x,2);
			}
			int flag = 0;
			/*for(int i=0;i<20;++i)cout<<tree1[i]<<' ';
			cout<<endl;
			for(int i=0;i<20;++i)cout<<tree2[i]<<' ';
			cout<<endl;*/
			
			for(int i=1;i<N;++i){
				if(tree1[i]!=tree2[i])flag = 1;
			}		
			if(flag == 1)cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
	}
	return 0;
}
