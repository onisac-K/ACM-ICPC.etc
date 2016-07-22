#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;

#define ll long long 

int G[20][20]; 

void Floyd(int n){
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
            }
		}
	}
}

int main()
{
	int m;
	while(cin>>m && m)
	{
		memset(G,0x3f3f3f3f,sizeof(G));
		int u,v,d;
		int n=0;
		for(int i=0;i<m;++i){
			G[i][i]=0;
			scanf("%d%d%d",&u,&v,&d);
			n = max(max(n,u),v);
			G[u][v] = min(G[u][v],d);
			G[v][u] = min(G[v][u],d);
		}
		n++;
		//cout<<n<<endl;
		Floyd(n);
		int maxi = 0;
		int ans = 0x3f3f3f3f;
		for(int i=0;i<n;++i){
			int sum = 0;
			for(int j=0;j<n;++j){
				if(i==j)continue;
				sum += G[i][j];
			}
			if(sum<ans){
				ans = sum;
				maxi = i;
			}
		}
		cout<<maxi<<' '<<ans<<endl;
	}
	return 0;
}

