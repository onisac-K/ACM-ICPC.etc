#include<bits/stdc++.h>
using namespace std;

int a[60][60];
int n;

void dfs(int i,int j,int k)
{
	if(k>n*n)return ;
	int posi = (i+n)%n;
	int posj = (j+n)%n;
	a[posi][posj]=k;
	if(k%n==0)dfs(posi+1,posj,k+1);
	else dfs(posi-1,posj+1,k+1);
}

int main()
{
	int f=1;

	while(cin>>n)
	{
		dfs(0,n/2,1);
		printf("Case %d:\n",f++);
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				printf("%5d",a[i][j]);
			}
			cout<<endl;
		}
	}
	return 0;
}
