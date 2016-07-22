#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;

#define ll long long 

int G[305][305]; 

void Floyd(int n){
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
            }
		}
	}
}

#define INF 0x3f3f3f3f

int num[305];

int main()
{
	int n,m;
	cin>>n>>m;
	memset(G,INF,sizeof(G));
	for(int i=1;i<=n;++i)G[i][i]=0;
	for(int i=0;i<m;++i){
		int k;
		cin>>k;
		for(int j=0;j<k;++j)scanf("%d",&num[j]);
		for(int j=0;j<k;++j){
			for(int q=0;q<k;++q){
				//cout<<num[j]<<' '<<num[q]<<endl;
				//if(num[j] == num[q])continue;
				G[num[j]][num[q]]=1;
				G[num[q]][num[j]]=1;
			}
		}
	}

	Floyd(n);
	int ans = INF;
	for(int i=1;i<=n;++i){
		int s = 0;
		for(int j=1;j<=n;++j)
			if(i!=j) s += G[i][j];
		ans = min(ans,s);
	}
	cout<<(int)(ans*100/(n-1))<<endl;
	return 0;
}
